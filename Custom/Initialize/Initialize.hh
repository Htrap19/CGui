#pragma once
#include <gtk/gtk.h>
#include "../DeleteOnQuit/DeleteOnQuit.hh"

namespace CGui
{
	struct Init
	{
	public:
		Init(int argc, char* argv[])
		{
			gtk_init(&argc, &argv);
		}

		void Render()
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
		gtk_main_quit();
	}
};