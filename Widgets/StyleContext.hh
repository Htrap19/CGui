#pragma once

#include <gtk/gtk.h>
#include "../Custom/VectorsUtilities/VectorUtilities.hh"
#include <iostream>

namespace CGui
{
	class StyleContext
	{
	public:
		StyleContext(GtkWidget* w);
		virtual void AddStyleClass(const char* classname) const;
		virtual void RemoveStyleClass(const char* classname) const;
		virtual bool HasStyleClass(const char* classname) const;
		virtual Vector<std::string> ListStyleClasses() const;

		bool IsStyleContext() const;

	protected:
		StyleContext();
		void SetContext(GtkWidget* widget) const;

	private:
		mutable GtkStyleContext* m_StyleContext;
	};
}