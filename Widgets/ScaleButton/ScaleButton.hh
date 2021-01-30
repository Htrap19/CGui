#pragma once

#include "../Button/Button.hh"
#include "../../Misc/Adjustment/Adjustment.hh"
#include "../Orientable.hh"

namespace CGui
{
	class ScaleButton : public virtual Button, public virtual Orientable
	{
	public:
		ScaleButton(GtkScaleButton* scale_button);
		ScaleButton(IconSize size, double min, double max, double step, const char** icons);
		void Adjustment(CGui::Adjustment adjustment);
		CGui::Adjustment Adjustment();
		void Icons(const char** icons);
		void Value(double value);
		double Value();
		Widget Popup();
		Button PlusButton();
		Button MinusButton();
		bool IsScaleButton();

	protected:
		ScaleButton();
		void SetScaleButton(GtkScaleButton* scalebutton);
	};
}