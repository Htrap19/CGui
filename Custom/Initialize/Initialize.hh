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
		auto f = [](KeyValue::Node<const char*, Single::List<std::any>*> * node) -> void
		{
			if (std::string(node->key) == "Instance")
				delete node->value;
		};

		Storage::GetInstance().ForEach<const char*, Single::List<std::any>*>(f, "allcallbacks");
		Storage::GetInstance().Free<const char*, Single::List<std::any>*>("allcallbacks");
		gtk_main_quit();
	}
};