#pragma once

#include "../Converter/Convert.hh"
#include "../Custom/Storage/Storage.hh"
#include "../Custom/List/List.hh"
#include <tuple>

namespace CGui
{
  template <typename WidgetType>
  class EventHandler
  {
    public:
      EventHandler(WidgetType *w)
      {
        Storage::GetInstance().MakePrivate<const char *, Single::List<std::any>*>("allcallbacks");
        t_widget = w;
      }

      long unsigned int SignalHandler(Events event, void(*func)())
      {
        if(singleCallbackMethods == NULL)
        {
          emptyCallbackMethods = new Single::List<std::any>;
          Storage::GetInstance().Add<const char *, Single::List<std::any>*>("Instance", emptyCallbackMethods, "allcallbacks");
        }

        emptyCallbackMethods->Insert(func);
        auto callback = +[](GtkWidget *widget, Single::List<std::any> *list) -> void
        {
          list->ForEach(+[](Single::Node<std::any> *node)
          {
            auto f = std::any_cast<void(*)()>(node->data);
            f();
          });
        };

        return reinterpret_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), std::get<char *>(Converter::Convert::GetInstance().ConvertToGtkCode(event)), G_CALLBACK(callback), emptyCallbackMethods));
      }

      long unsigned int SignalHandler(Events event, void(*func)(WidgetType*))
      {
        if(singleCallbackMethods == NULL)
        {
          singleCallbackMethods = new Single::List<std::any>;
          Storage::GetInstance().Add<const char *, Single::List<std::any>*>("Instance", singleCallbackMethods, "allcallbacks");
        }

        singleCallbackMethods->Insert(func);

        auto callback = +[](GtkWidget *widget, WidgetType *data) -> void
        {
          data->singleCallbackMethods->ForEach(+[](Single::Node<std::any> *node, WidgetType *ins)
          {
            auto f = std::any_cast<void(*)(WidgetType*)>(node->data);
            f(ins);
          }, data);
        };
        return reinterpret_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), std::get<char *>(Converter::Convert::GetInstance().ConvertToGtkCode(event)), G_CALLBACK(callback), t_widget));
      }

      template <typename ... Args> long unsigned int SignalHandler(Events event, void(*func)(WidgetType*, Args*...), Args & ... args)
      {
        if(infiniteCallbackMethods == NULL)
        {
          infiniteCallbackMethods = new Single::List<std::any>;
          Storage::GetInstance().Add<const char *, Single::List<std::any>*>("Instance", infiniteCallbackMethods, "allcallbacks");
        }

        infiniteCallbackMethods->Insert(std::make_tuple(func, &args...));

        auto callback = +[](GtkWidget *widget, WidgetType *data) -> void
        {
          auto f = +[](Single::Node<std::any> *node, WidgetType *ins)
          {
            std::apply([&ins](auto *func, Args * ... a)
            {
              func(ins, a...);
            }, std::any_cast<std::tuple<void(*)(WidgetType*, Args*...), Args*...>>(node->data));
          };

          data->infiniteCallbackMethods->ForEach(f, data);
        };

        return reinterpret_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), std::get<char *>(Converter::Convert::GetInstance().ConvertToGtkCode(event)), G_CALLBACK(callback), t_widget));
      }

      template <typename ... Args> long unsigned int SignalHandler(Events event, void(*func)(Args*...), Args & ... args)
      {
        if(infiniteCallbackMethods == NULL)
        {
          infiniteCallbackMethods = new Single::List<std::any>;
          Storage::GetInstance().Add<const char *, Single::List<std::any>*>("Instance", infiniteCallbackMethods, "allcallbacks");
        }

        infiniteCallbackMethods->Insert(std::make_tuple(func, &args...));

        auto callback = +[](GtkWidget *widget, WidgetType *data) -> void
        {
          auto f = +[](Single::Node<std::any> *node, WidgetType *ins)
          {
            std::apply([](auto *func, Args * ... a)
            {
              func(a...);
            }, std::any_cast<std::tuple<void(*)(Args*...), Args*...>>(node->data));
          };

          data->infiniteCallbackMethods->ForEach(f, data);
        };

        return reinterpret_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), std::get<char *>(Converter::Convert::GetInstance().ConvertToGtkCode(event)), G_CALLBACK(callback), t_widget));
      }

      void DisconnectHandler(long unsigned int id)
      {
        auto *first_value = reinterpret_cast<gulong*>(&id);
        auto &final_value = *first_value;
        g_signal_handler_disconnect(t_widget->GetWidget(), final_value);
      }

      virtual ~EventHandler()
      {  }

    protected:
      Single::List<std::any> *emptyCallbackMethods = NULL;
      Single::List<std::any> *singleCallbackMethods = NULL;
      Single::List<std::any> *infiniteCallbackMethods = NULL;

    private:
      WidgetType *t_widget;
  };
};
