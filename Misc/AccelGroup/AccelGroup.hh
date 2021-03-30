#pragma once

#include <gtk/gtk.h>
#include <tuple>
#include <any>

#include "../../Converter/Convert.hh"
#include "../../Custom/DeleteOnQuit/DeleteOnQuit.hh"

namespace CGui
{
	class AccelGroup
	{
	public:
		AccelGroup();
		template <typename ... Args>
		void Connect(unsigned int accel_key, ModifierType accel_mods, AccelFlags accel_flags, void(*callback)(Args...), Args ... args);
		template <typename ... Args>
		void ConnectByPath(const char* accel_path, void(*callback)(Args...), Args ... args);
		template <typename ... Args>
		bool Disconnect(void(*callback)(Args...), Args ... args);
		bool DisconnectKey(unsigned int accel_key, ModifierType accel_mods);
		void Lock();
		void Unlock();
		bool IsLocked();
		ModifierType ModifierMask();

		bool IsAccelGroup();

		class Accelerator
		{
		public:
			static bool Valid(unsigned int keyval, ModifierType modifiers);
			static AcceleratorParseData Parse(const char* accelerator);
			static const char* Name(unsigned int accelerator_key, ModifierType accelerator_mods);
			static const char* Label(unsigned int accelerator_key, ModifierType accelerator_mods);
			static AcceleratorParseWithKeyCode ParseWithKeyCode(const char* accelerator);
			static void DefaultModeMask(ModifierType default_mod_mask);
			static ModifierType DefaultModeMask();
		};

		GtkAccelGroup* GetWidget();

	private:
		GtkAccelGroup* accel_group;

		struct PassingData
		{
			std::any data;
		};
	};

	template <typename ... Args>
	void AccelGroup::Connect(unsigned int accel_key, ModifierType accel_mods, AccelFlags accel_flags, void(*callback)(Args...), Args ... args)
	{
		PassingData* data = new PassingData
		{
			std::make_tuple(callback, args...)
		};
		DeleteOnQuit::Instance().Add(data);

		auto main_callback = [](GClosure* sender, GValue* return_value, guint number_param, const GValue* params, gpointer invokation_hint, gpointer marshal_data) -> void
		{
			auto apply_callback = [](void(*func_call)(Args...), Args ... args) -> void
			{
				func_call(args...);
			};
			std::apply(apply_callback, std::any_cast<std::tuple<void(*)(Args...), Args...>>(((PassingData*)marshal_data)->data));
		};

		auto closure = g_closure_new_simple(sizeof(GClosure), nullptr);
		g_closure_set_meta_marshal(closure, (gpointer)data, main_callback);

		gtk_accel_group_connect(accel_group, accel_key, (GdkModifierType)accel_mods, (GtkAccelFlags)accel_flags, closure);
	}

	template <typename ... Args>
	void AccelGroup::ConnectByPath(const char* accel_path, void(*callback)(Args...), Args ... args)
	{
		PassingData* data = new PassingData
		{
			std::make_tuple(callback, args...)
		};
		DeleteOnQuit::Instance().Add(data);

		auto main_callback = [](GClosure* sender, GValue* return_value, guint number_param, const GValue* params, gpointer invokation_hint, gpointer marshal_data) -> void
		{
			auto apply_callback = [](void(*func_call)(Args...), Args ... args) -> void
			{
				func_call(args...);
			};
			std::apply(apply_callback, std::any_cast<std::tuple<void(*)(Args...), Args...>>(((PassingData*)marshal_data)->data));
		};

		auto closure = g_closure_new_simple(sizeof(GClosure), nullptr);
		g_closure_set_meta_marshal(closure, (gpointer)data, main_callback);

		gtk_accel_group_connect_by_path(accel_group, accel_path, closure);
	}

	template <typename ... Args>
	bool AccelGroup::Disconnect(void(*callback)(Args...), Args ... args)
	{
		PassingData* data = new PassingData
		{
			std::make_tuple(callback, args...)
		};
		DeleteOnQuit::Instance().Add(data);

		auto main_callback = [](GClosure* sender, GValue* return_value, guint number_param, const GValue* params, gpointer invokation_hint, gpointer marshal_data) -> void
		{
			auto apply_callback = [](void(*func_call)(Args...), Args ... args) -> void
			{
				func_call(args...);
			};
			std::apply(apply_callback, std::any_cast<std::tuple<void(*)(Args...), Args...>>(((PassingData*)marshal_data)->data));
		};

		auto closure = g_closure_new_simple(sizeof(GClosure), nullptr);
		g_closure_set_meta_marshal(closure, (gpointer)data, main_callback);

		return gtk_accel_group_disconnect(accel_group, closure);
	}

}