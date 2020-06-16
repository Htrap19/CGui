#pragma once

#include <gtk/gtk.h>
#include "../../Converter/Convert.hh"

namespace CGui
{
	class Pixbuf
	{
	public:
		Pixbuf(GdkPixbuf* pixbuf, bool copy_options = false);
		Pixbuf(const char* filename);
		Pixbuf(const char* filename, int width, int height, bool aspactRatio);
		Pixbuf(const char* filename, int width, int height);
		~Pixbuf();
		void SimpleScale(int dest_width, int des_height, InterpType type);
		void Scale(int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType type);;
		void CompositeColorSimple(int dest_width, int dest_height, InterpType type, int overall_alpha, int check_size, int color1, int color2);
		void Composite(int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType type, bool overall_alpha);
		void Rotate(PixbufRotation rotation);
		void Flip(bool horizontal);
		Pixbuf SubPixbuf(int src_x, int src_y, int width, int height);
		void AddAlpha(bool substitute_color, unsigned char r, unsigned char g, unsigned int b);
		Pixbuf CopyArea(int src_x, int src_y, int width, int height, int dest_x, int dest_y);
		void SaturateAndPixelate(float saturate, bool pixelate);
		void ApplyEmbeddedOrientation();
		void Fill(unsigned int pixel);
		bool HasError();
		const char* ErrorMessage();
		int ErrorDomain();
		int ErrorCode();
		GdkPixbuf* GetWidget();

	private:
		GdkPixbuf* pixbuf;
		GError* error;
	};
}