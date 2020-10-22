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
		Handler(WidgetType* w)
		{
			/*Storage::GetInstance().MakePrivate<const char*, Single::List<std::any>*>("allcallbacks");
			Storage::GetInstance().MakePrivate<const char*, void*>("passingdata");
			Storage::GetInstance().MakePrivate<const char*, KeyValue::List<Events, std::any>*>("mainlistevents");
			Storage::GetInstance().MakePrivate<const char*, KeyValue::List<Signals, std::any>*>("mainlistsignals");*/
			//Storage::GetInstance().MakePrivate<const char*, void*>("deleteonquit");
			t_widget = w;
		}

		long unsigned int SignalHandler(Signals signal, void(*func)())
		{
			/*if (emptyCallbackMethods == NULL)
			{
				emptyCallbackMethods = new KeyValue::List<Signals, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Signals, std::any>*>("Instance", emptyCallbackMethods, "mainlistsignals");
			}

			PassingDataSignals* pass = new PassingDataSignals
			{
				this, signal, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!emptyCallbackMethods->ExistsKey(signal))
			{
				auto temp = new Single::List<std::any>;
				temp->Insert(func);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", temp, "allcallbacks");
				emptyCallbackMethods->Insert(signal, temp);
			}
			else
			{
				KeyValueData keyvaluedata = emptyCallbackMethods->FindByKey(signal);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(func);
			}

			auto callback = [](GtkWidget * widget, PassingDataSignals * d)
			{
				KeyValueData keyvaluedata = d->data->emptyCallbackMethods->FindByKey(d->signal);

				auto f = [](Single::Node<std::any> * node)
				{
					auto user_func = std::any_cast<void(*)()>(node->data);
					user_func();
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach(f);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto user_func = std::any_cast<void(*)()>(func_data->func);
				user_func();
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		long unsigned int SignalHandler(Signals signal, void(*func)(WidgetType*))
		{
			/*if (singleCallbackMethods == NULL)
			{
				singleCallbackMethods = new KeyValue::List<Signals, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Signals, std::any>*>("Instance", singleCallbackMethods, "mainlistsignals");
			}

			PassingDataSignals* pass = new PassingDataSignals
			{
				this, signal, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!singleCallbackMethods->ExistsKey(signal))
			{
				auto temp = new Single::List<std::any>;
				singleCallbackMethods->Insert(signal, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", temp, "allcallbacks");
				temp->Insert(func);
			}
			else
			{
				KeyValueData keyvaluedata = singleCallbackMethods->FindByKey(signal);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(func);
			}

			auto callback = [](GtkWidget * widget, PassingDataSignals * d)
			{
				KeyValueData keyvaluedata = d->data->singleCallbackMethods->FindByKey(d->signal);

				auto f = [](Single::Node<std::any> * node, WidgetType * ins)
				{
					auto user_func = std::any_cast<void(*)(WidgetType*)>(node->data);
					user_func(ins);
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, d->ins);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto user_func = std::any_cast<void(*)(WidgetType*)>(func_data->func);
				user_func(func_data->ins);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args> long unsigned int SignalHandler(Signals signal, void(*func)(WidgetType*, Args* ...), Args& ... args)
		{
			/*if (infiniteCallbackMethods == NULL)
			{
				infiniteCallbackMethods = new KeyValue::List<Signals, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Signals, std::any>*>("Instance", infiniteCallbackMethods, "mainlistsignals");
			}

			PassingDataSignals* pass = new PassingDataSignals
			{
				this, signal, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!infiniteCallbackMethods->ExistsKey(signal))
			{
				auto temp = new Single::List<std::any>;
				infiniteCallbackMethods->Insert(signal, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", temp, "allcallbacks");
				temp->Insert(std::make_tuple(func, &args...));
			}
			else
			{
				KeyValueData keyvaluedata = infiniteCallbackMethods->FindByKey(signal);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(std::make_tuple(func, &args...));
			}

			auto callback = [](GtkWidget * widget, PassingDataSignals * d)
			{
				KeyValueData keyvaluedata = d->data->infiniteCallbackMethods->FindByKey(d->signal);

				auto f = [](Single::Node<std::any> * node, WidgetType * ins)
				{
					auto apply_f = [&ins](void(*func)(WidgetType*, Args * ...), Args * ... user_data)
					{
						func(ins, user_data...);
					};

					std::apply(apply_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args * ...), Args * ...>>(node->data));
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, d->ins);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, &args...), t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto apply_f = [&func_data](void(*user_func)(WidgetType*, Args* ...), Args* ... user_data)
				{
					user_func(func_data->ins, user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args* ...), Args* ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args> long unsigned int SignalHandler(Signals signal, void(*func)(Args* ...), Args& ... args)
		{
			/*if (infiniteCallbackMethods == NULL)
			{
				infiniteCallbackMethods = new KeyValue::List<Signals, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Signals, std::any>*>("Instance", infiniteCallbackMethods, "mainlistsignals");
			}

			PassingDataSignals* pass = new PassingDataSignals
			{
				this, signal, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!infiniteCallbackMethods->ExistsKey(signal))
			{
				auto temp = new Single::List<std::any>;
				infiniteCallbackMethods->Insert(signal, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", temp, "allcallbacks");
				temp->Insert(std::make_tuple(func, &args...));
			}
			else
			{
				KeyValueData keyvaluedata = infiniteCallbackMethods->FindByKey(signal);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(std::make_tuple(func, &args...));
			}

			auto callback = [](GtkWidget * widget, PassingDataSignals * d)
			{
				KeyValueData keyvaluedata = d->data->infiniteCallbackMethods->FindByKey(d->signal);

				auto f = [](Single::Node<std::any> * node)
				{
					auto apply_f = [](void(*func)(Args * ...), Args * ... user_data)
					{
						func(user_data...);
					};

					std::apply(apply_f, std::any_cast<std::tuple<void(*)(Args * ...), Args * ...>>(node->data));
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach(f);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, &args...), t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, PassingDataByFunc* func_data)
			{
				auto apply_f = [](void(*user_func)(Args* ...), Args* ... user_data)
				{
					user_func(user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(Args* ...), Args* ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(signal), G_CALLBACK((void(*)(GtkWidget*, PassingDataByFunc*))callback), pass));
		}

		long unsigned int EventHandler(Events event, int(*func)())
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto user_func = std::any_cast<int(*)()>(func_data->func);
				return user_func();
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		long unsigned int EventHandler(Events event, void(*func)())
		{
			/*if (emptyEventsCallbacks == NULL)
			{
				emptyEventsCallbacks = new KeyValue::List<Events, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Events, std::any>*>("Instance", emptyEventsCallbacks, "mainlistevents");
			}

			PassingData* pass = new PassingData
			{
				this, event, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!emptyEventsCallbacks->ExistsKey(event))
			{
				auto temp = new Single::List<std::any>;
				emptyEventsCallbacks->Insert(event, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", emptyEventsCallbacks, "allcallbacks");
				temp->Insert(func);
			}
			else
			{
				KeyValueData keyvaluedata = emptyEventsCallbacks->FindByKey(event);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(func);
			}

			auto callback = [](GtkWidget * widget, GdkEvent * event, PassingData * d)
			{
				KeyValueData keyvaluedata = d->data->emptyEventsCallbacks->FindByKey(d->event);

				auto f = [](Single::Node<std::any> * node)
				{
					auto user_func = std::any_cast<void(*)()>(node->data);
					user_func();
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach(f);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto user_func = std::any_cast<void(*)()>(func_data->func);
				user_func();
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		long unsigned int EventHandler(Events event, int(*func)(WidgetType*))
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto user_func = std::any_cast<int(*)(WidgetType*)>(func_data->func);
				return user_func(func_data->ins);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));

		}

		long unsigned int EventHandler(Events event, void(*func)(WidgetType*))
		{
			/*if (singleEventsCallbacks == NULL)
			{
				singleEventsCallbacks = new KeyValue::List<Events, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Events, std::any>*>("Instance", singleEventsCallbacks, "mainlistevents");
			}

			PassingData* pass = new PassingData
			{
				this, event, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!singleEventsCallbacks->ExistsKey(event))
			{
				auto temp = new Single::List<std::any>;
				singleEventsCallbacks->Insert(event, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", singleEventsCallbacks, "allcallbacks");
				temp->Insert(func);
			}
			else
			{
				KeyValueData keyvaluedata = singleEventsCallbacks->FindByKey(event);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(func);
			}

			auto callback = [](GtkWidget * widget, GdkEvent * user_event, PassingData * d)
			{
				KeyValueData keyvaluedata = d->data->singleEventsCallbacks->FindByKey(d->event);

				auto f = [](Single::Node<std::any> * node, WidgetType * ins)
				{
					auto user_func = std::any_cast<void(*)(WidgetType*)>(node->data);
					user_func(ins);
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, d->ins);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				func, t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto user_func = std::any_cast<void(*)(WidgetType*)>(func_data->func);
				user_func(func_data->ins);
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args> long unsigned int EventHandler(Events event, int(*func)(WidgetType*, Args*...), Args& ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, &args...), t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto apply_f = [&func_data](int(*user_func)(WidgetType*, Args* ...), Args* ... user_data)
				{
					return user_func(func_data->ins, user_data...);
				};

				return std::apply(apply_f, std::any_cast<std::tuple<int(*)(WidgetType*, Args* ...), Args* ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));

		}

		template <typename ... Args> long unsigned int EventHandler(Events event, void(*func)(WidgetType*, Args* ...), Args& ... args)
		{
			/*if (infiniteEventsCallbacks == NULL)
			{
				infiniteEventsCallbacks = new KeyValue::List<Events, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Events, std::any>*>("Instance", infiniteEventsCallbacks, "mainlistevents");
			}

			PassingData* pass = new PassingData
			{
				this, event, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!infiniteEventsCallbacks->ExistsKey(event))
			{
				auto temp = new Single::List<std::any>;
				infiniteEventsCallbacks->Insert(event, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", temp, "allcallbacks");
				temp->Insert(std::make_tuple(func, &args...));
			}
			else
			{
				auto keyvaluedata = infiniteEventsCallbacks->FindByKey(event);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(std::make_tuple(func, &args...));
			}

			auto callback = [](GtkWidget * widget, GdkEvent * user_event, PassingData * d) -> void
			{
				KeyValueData keyvaluedata = d->data->infiniteEventsCallbacks->FindByKey(d->event);

				auto f = [](Single::Node<std::any> * node, WidgetType * ins)
				{
					auto apply_f = [&ins](void(*func)(WidgetType*, Args * ...), Args * ... user_data)
					{
						func(ins, user_data...);
					};

					std::apply(apply_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args * ...), Args * ...>>(node->data));
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach((void(*)(Single::Node<std::any>*, WidgetType*))f, d->ins);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, &args...), t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto apply_f = [&func_data](void(*user_func)(WidgetType*, Args* ...), Args* ... user_data)
				{
					user_func(func_data->ins, user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(WidgetType*, Args* ...), Args* ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((void(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));
		}

		template <typename ... Args> long unsigned int EventHandler(Events event, int(*func)(Args*...), Args& ... args)
		{
			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, &args...), t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data) -> gint
			{
				auto apply_f = [](int(*user_func)(Args* ...), Args* ... user_data)
				{
					return user_func(user_data...);
				};

				return std::apply(apply_f, std::any_cast<std::tuple<int(*)(Args* ...), Args* ...>>(func_data->func));
			};

			return static_cast<long unsigned int>(g_signal_connect(G_OBJECT(t_widget->GetWidget()), Converter::Convert::GetInstance().GetGtkCode(event), G_CALLBACK((gint(*)(GtkWidget*, GdkEvent*, PassingDataByFunc*))callback), pass));

		}

		template <typename ... Args> long unsigned int EventHandler(Events event, void(*func)(Args* ...), Args& ... args)
		{
			/*if (infiniteEventsCallbacks == NULL)
			{
				infiniteEventsCallbacks = new KeyValue::List<Events, std::any>;
				Storage::GetInstance().Add<const char*, KeyValue::List<Events, std::any>*>("Instance", infiniteEventsCallbacks, "mainlistevents");
			}

			PassingData* pass = new PassingData
			{
				this, event, t_widget
			};
			Storage::GetInstance().Add<const char*, void*>("Instance", pass, "passingdata");

			if (!infiniteEventsCallbacks->ExistsKey(event))
			{
				auto temp = new Single::List<std::any>;
				infiniteEventsCallbacks->Insert(event, temp);
				Storage::GetInstance().Add<const char*, Single::List<std::any>*>("Instance", temp, "allcallbacks");
				temp->Insert(std::make_tuple(func, &args...));
			}
			else
			{
				KeyValueData keyvaluedata = infiniteEventsCallbacks->FindByKey(event);
				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->Insert(std::make_tuple(func, &args...));
			}

			auto callback = [](GtkWidget * widget, GdkEvent * user_event, PassingData * d) -> void
			{
				KeyValueData keyvaluedata = d->data->infiniteEventsCallbacks->FindByKey(d->event);

				auto f = [](Single::Node<std::any> * node) -> void
				{
					auto apply_f = [](void(*func)(Args * ...), Args * ... user_data)
					{
						func(user_data...);
					};

					std::apply(apply_f, std::any_cast<std::tuple<void(*)(Args * ...), Args * ...>>(node->data));
				};

				std::any_cast<Single::List<std::any>*>(keyvaluedata.value)->ForEach(f);
			};*/

			PassingDataByFunc* pass = new PassingDataByFunc
			{
				std::make_tuple(func, &args...), t_widget
			};
			DeleteOnQuit::GetInstance().Add(pass);

			auto callback = [](GtkWidget* widget, GdkEvent* user_event, PassingDataByFunc* func_data)
			{
				auto apply_f = [](void(*user_func)(Args* ...), Args* ... user_data)
				{
					user_func(user_data...);
				};

				std::apply(apply_f, std::any_cast<std::tuple<void(*)(Args* ...), Args* ...>>(func_data->func));
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
		/*KeyValue::List<Signals, std::any>* emptyCallbackMethods = NULL;
		KeyValue::List<Signals, std::any>* singleCallbackMethods = NULL;
		KeyValue::List<Signals, std::any>* infiniteCallbackMethods = NULL;
		KeyValue::List<Events, std::any>* emptyEventsCallbacks = NULL;
		KeyValue::List<Events, std::any>* singleEventsCallbacks = NULL;
		KeyValue::List<Events, std::any>* infiniteEventsCallbacks = NULL;

		struct PassingData
		{
			EventHandler* data;
			Events event;
			WidgetType* ins;
		};

		struct PassingDataSignals
		{
			EventHandler* data;
			Signals signal;
			WidgetType* ins;
		};*/

		struct PassingDataByFunc
		{
			std::any func;
			WidgetType* ins;
		};

	private:
		WidgetType* t_widget;
	};
};
