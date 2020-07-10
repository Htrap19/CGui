#pragma once
#include <gtk/gtk.h>
#include "../Storage/Storage.hh"

namespace CGui
{
	struct Init
	{
	public:
		Init(int argc, char* argv[])
		{
			gtk_init(&argc, &argv);
		}
		~Init()
		{
			gtk_main();
		}
	};

	static void UpdateUIWhile()
	{
		while (gtk_events_pending())
			gtk_main_iteration();
	}

	static void UpdateUI()
	{
		gtk_main_iteration();
	}

	static void MainQuit()
	{
		/*auto f = [](KeyValue::Node<const char*, Single::List<std::any>*> * node) -> void
		{
			if (std::string(node->key) == "Instance")
				delete node->value;
		};

		Storage::GetInstance().ForEach<const char*, Single::List<std::any>*>(f, "allcallbacks");
		Storage::GetInstance().Free<const char*, Single::List<std::any>*>("allcallbacks");

		auto f2 = [](KeyValue::Node<const char*, void*> * node) -> void
		{
			if (std::string(node->key) == "Instance")
				delete node->value;
		};

		Storage::GetInstance().ForEach<const char*, void*>(f2, "passingdata");
		Storage::GetInstance().Free<const char*, void*>("passingdata");

		auto f3 = [](KeyValue::Node<const char*, KeyValue::List<Events, std::any>*> * node) -> void
		{
			if (std::string(node->key) == "Instance")
				delete node->value;
		};

		Storage::GetInstance().ForEach<const char*, KeyValue::List<Events, std::any>*>(f3, "mainlistevents");
		Storage::GetInstance().Free<const char*, KeyValue::List<Events, std::any>*>("mainlistevents");

		auto f4 = [](KeyValue::Node<const char*, KeyValue::List<Signals, std::any>*> * node) -> void
		{
			if (std::string(node->key) == "Instance")
				delete node->value;
		};

		Storage::GetInstance().ForEach<const char*, KeyValue::List<Signals, std::any>*>(f4, "mainlistsignals");
		Storage::GetInstance().Free<const char*, KeyValue::List<Signals, std::any>*>("mainlistsignals");*/

		auto free = [](KeyValue::Node<const char*, void*> * node) -> void
		{
			if (std::string(node->key) == "Instance")
				delete node->value;
		};

		Storage::GetInstance().ForEach<const char*, void*>(free, "deleteonquit");
		Storage::GetInstance().Free<const char*, void*>("deleteonquit");

		gtk_main_quit();
	}
};