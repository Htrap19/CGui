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
		EventHandler(WidgetType* w)
		{
			Storage::GetInstance().MakePrivate<const char*, Single::List<std::any>*>("allcallbacks");
			t_widget = w;
		}

		long unsigned int SignalHandler(Events event, void(*func)())
		{
			if (singleCallbackMethods == NULL)
			{
				emptyCallbackMethods = new Single::List<std::any>;
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", emptyCallbackMethods, "allcallbacks");
			}

			emptyCallbackMethods->Insert(func);

			auto callback = [](GtkWidget * widget, Single::List<std::any> * list) mutable -> void
			{
				list->ForEach([](Single::Node<std::any> * node)
					{
						auto f = std::any_cast<void(*)()>(node->data);
						f();
					});
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, Single::List<std::any>*))callback), emptyCallbackMethods));
		}

		long unsigned int SignalHandler(Events event, void(*func)(WidgetType*))
		{
			if (singleCallbackMethods == NULL)
			{
				singleCallbackMethods = new Single::List<std::any>;
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", singleCallbackMethods, "allcallbacks");
			}

			singleCallbackMethods->Insert(func);

			auto callback = [](GtkWidget * widget, EventHandler * data)
			{
				auto f = [](Single::Node<std::any> * node, WidgetType * ins) mutable -> void
				{
					auto user_func = std::any_cast<void(*)(WidgetType*)>(node->data);
					user_func(ins);
				};

				data->singleCallbackMethods->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, data->t_widget);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, EventHandler*))callback), this));
		}

		template <typename ... Args> long unsigned int SignalHandler(Events event, void(*func)(WidgetType*, Args* ...), Args& ... args)
		{
			if (infiniteCallbackMethods == NULL)
			{
				infiniteCallbackMethods = new Single::List<std::any>;
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", infiniteCallbackMethods, "allcallbacks");
			}

			infiniteCallbackMethods->Insert(std::make_tuple(func, &args...));

			auto callback = [](GtkWidget * widget, EventHandler * data) mutable -> void
			{
				auto f = [](Single::Node<std::any> * node, WidgetType * ins) mutable -> void
				{
					auto user_f = [&ins](void(*func)(WidgetType*, Args * ...), Args * ... user_data)
					{
						func(ins, std::forward<Args*>(user_data)...);
					};

					std::apply(user_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args * ...), Args * ...>>(node->data));
				};

				data->infiniteCallbackMethods->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, data->t_widget);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, EventHandler*))callback), this));
		}

		template <typename ... Args> long unsigned int SignalHandler(Events event, void(*func)(Args* ...), Args& ... args)
		{
			if (infiniteCallbackMethods == NULL)
			{
				infiniteCallbackMethods = new Single::List<std::any>;
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", infiniteCallbackMethods, "allcallbacks");
			}

			infiniteCallbackMethods->Insert(std::make_tuple(func, &args...));

			auto callback = [](GtkWidget * widget, EventHandler * data) mutable -> void
			{
				auto f = [](Single::Node<std::any> * node, WidgetType * ins) mutable -> void
				{
					auto user_f = [](void(*func)(Args * ...), Args * ... user_data)
					{
						func(std::forward<Args*>(user_data)...);
					};

					std::apply(user_f, std::any_cast<std::tuple<void(*)(Args * ...), Args * ...>>(node->data));
				};

				data->infiniteCallbackMethods->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, data->t_widget);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, EventHandler*))callback), this));
		}

		void DisconnectHandler(long unsigned int id)
		{
			g_signal_handler_disconnect(t_widget->GetWidget(), *reinterpret_cast<gulong*>(&id));
		}

		virtual ~EventHandler()
		{  }

	protected:
		Single::List<std::any>* emptyCallbackMethods = NULL;
		Single::List<std::any>* singleCallbackMethods = NULL;
		Single::List<std::any>* infiniteCallbackMethods = NULL;

	private:
		WidgetType* t_widget;
	};
};
