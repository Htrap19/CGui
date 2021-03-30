#pragma once

#include "../Converter/Convert.hh"
#include "../Custom/DeleteOnQuit/DeleteOnQuit.hh"
#include "../Custom/List/List.hh"
#include <tuple>
#include <any>

namespace CGui
{
	template <typename WidgetType>
	class Handler
	{
	public:
		Handler(WidgetType* w) : t_widget{w}
		{
		}

		long unsigned int SignalHandler(Signals signal, void(*func)())
		{
			auto callback = [](GtkWidget* widget, void(*func)())
			{
				func();
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, void(*)()))callback), func));
		}

		long unsigned int SignalHandler(Signals signal, void(*func)(WidgetType*))
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto user_func = std::any_cast<void(*)(WidgetType*)>(func_data->func);
				user_func(func_data->ins);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args>
		long unsigned int SignalHandler(Signals signal, void(*func)(WidgetType*, Args...), Args ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, args...), t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto apply_f = [&func_data](void(*user_func)(WidgetType*, Args ...), Args ... user_data)
				{
					user_func(func_data->ins, user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args ...), Args ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args>
		long unsigned int SignalHandler(Signals signal, void(*func)(Args...), Args ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, args...), t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto apply_f = [](void(*user_func)(Args ...), Args ... user_data)
				{
					user_func(user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(Args ...), Args ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		long unsigned int EventHandler(Events event, int(*func)())
		{
			auto callback = [](GtkWidget* widget, GdkEvent* user_event, int(*func)()) -> gint
			{
				return func();
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, int(*)()))callback), func));
		}

		long unsigned int EventHandler(Events event, void(*func)())
		{
			auto callback = [](GtkWidget* widget, GdkEvent* user_event, void(*func)()) -> void
			{
				func();
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, void(*)()))callback), func));
		}

		long unsigned int EventHandler(Events event, int(*func)(WidgetType*))
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto user_func = std::any_cast<int(*)(WidgetType*)>(func_data->func);
				return user_func(func_data->ins);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));

		}

		long unsigned int EventHandler(Events event, void(*func)(WidgetType*))
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto user_func = std::any_cast<void(*)(WidgetType*)>(func_data->func);
				user_func(func_data->ins);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args> long unsigned int EventHandler(Events event, int(*func)(WidgetType*, Args...), Args ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, args...), t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto apply_f = [&func_data](int(*user_func)(WidgetType*, Args ...), Args ... user_data)
				{
					return user_func(func_data->ins, user_data...);
				};

				return std::apply(apply_f, std::any_cast<std::tuple<int(*)(WidgetType, Args ...), Args ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));

		}

		template <typename ... Args> long unsigned int EventHandler(Events event, void(*func)(WidgetType*, Args ...), Args ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, args...), t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto apply_f = [&func_data](void(*user_func)(WidgetType*, Args ...), Args ... user_data)
				{
					user_func(func_data->ins, user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args ...), Args ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args> long unsigned int EventHandler(Events event, int(*func)(Args...), Args ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, args...), t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto apply_f = [](int(*user_func)(Args ...), Args ... user_data)
				{
					return user_func(user_data...);
				};

				return std::apply(apply_f, std::any_cast<std::tuple<int(*)(Args ...), Args ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));

		}

		template <typename ... Args> long unsigned int EventHandler(Events event, void(*func)(Args ...), Args ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, args...), t_widget
			};
			DeleteOnQuit::Instance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto apply_f = [](void(*user_func)(Args ...), Args ... user_data)
				{
					user_func(user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(Args ...), Args ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		void DisconnectHandler(long unsigned int id)
		{
			g_signal_handler_disconnect(t_widget->GetWidget(), *(gulong*)&id);
		}

		virtual ~Handler()
		{  }

	protected:
		struct PassingDataByFunc
		{
			std::any func;
			WidgetType* ins;
		};

	private:
		WidgetType* t_widget;
	};
};
