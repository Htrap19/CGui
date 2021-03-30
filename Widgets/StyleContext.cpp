#include "./StyleContext.hh"

namespace CGui
{

	StyleContext::StyleContext() : m_StyleContext(nullptr)
	{
	}

	StyleContext::StyleContext(GtkWidget* widget)
	{
		this->SetContext(widget);
	}

	void StyleContext::AddStyleClass(const char* classname) const
	{
		gtk_style_context_add_class(GTK_STYLE_CONTEXT(m_StyleContext), classname);
	}

	void StyleContext::RemoveStyleClass(const char* classname) const
	{
		gtk_style_context_remove_class(GTK_STYLE_CONTEXT(m_StyleContext), classname);
	}

	bool StyleContext::HasStyleClass(const char* classname) const
	{
		return gtk_style_context_has_class(GTK_STYLE_CONTEXT(m_StyleContext), classname);
	}

	CGui::Vector<std::string> StyleContext::ListStyleClasses() const
	{
		auto g_list = gtk_style_context_list_classes(GTK_STYLE_CONTEXT(m_StyleContext));
		Vector<std::string> styleclasses(std::move(GListToStringVector(g_list)));
		g_list_free(g_list);
		return std::move(styleclasses);
	}

	bool StyleContext::IsStyleContext() const
	{
		return GTK_IS_STYLE_CONTEXT(m_StyleContext);
	}

	void StyleContext::SetContext(GtkWidget* widget) const
	{
		m_StyleContext = gtk_widget_get_style_context(GTK_WIDGET(widget));
	}

}