#include "AccelGroup.hh"

namespace CGui
{
	AccelGroup::AccelGroup()
	{
		accel_group = gtk_accel_group_new();
	}

	/*bool AccelGroup::Disconnect(void(*callback)())
	{
		return gtk_accel_group_disconnect(accel_group, g_cclosure_new(callback, nullptr, nullptr));
	}*/

	bool AccelGroup::DisconnectKey(unsigned int accel_key, ModifierType accel_mods)
	{
		return gtk_accel_group_disconnect_key(accel_group, accel_key, (GdkModifierType)accel_mods);
	}

	void AccelGroup::Lock()
	{
		gtk_accel_group_lock(accel_group);
	}

	void AccelGroup::Unlock()
	{
		gtk_accel_group_unlock(accel_group);
	}

	bool AccelGroup::IsLocked()
	{
		return gtk_accel_group_get_is_locked(accel_group);
	}

	CGui::ModifierType AccelGroup::ModifierMask()
	{
		return (ModifierType)gtk_accel_group_get_modifier_mask(accel_group);
	}

	bool AccelGroup::Accelerator::Valid(unsigned int keyval, ModifierType modifiers)
	{
		return gtk_accelerator_valid(keyval, (GdkModifierType)modifiers);
	}

	CGui::AcceleratorParseData AccelGroup::Accelerator::Parse(const char* accelerator)
	{
		guint accelerator_key;
		GdkModifierType accelerator_mods;
		gtk_accelerator_parse(accelerator, &accelerator_key, &accelerator_mods);

		return { accelerator_key, (ModifierType)accelerator_mods };
	}

	const char* AccelGroup::Accelerator::Name(unsigned int accelerator_key, ModifierType accelerator_mods)
	{
		return gtk_accelerator_name(accelerator_key, (GdkModifierType)accelerator_mods);
	}

	const char* AccelGroup::Accelerator::Label(unsigned int accelerator_key, ModifierType accelerator_mods)
	{
		return gtk_accelerator_get_label(accelerator_key, (GdkModifierType)accelerator_mods);
	}

	CGui::AcceleratorParseWithKeyCode AccelGroup::Accelerator::ParseWithKeyCode(const char* accelerator)
	{
		guint accelerator_key;
		guint* accelerator_codes;
		GdkModifierType accelerator_mods;
		gtk_accelerator_parse_with_keycode(accelerator, &accelerator_key, &accelerator_codes, &accelerator_mods);

		return { accelerator_key, accelerator_codes, (ModifierType)accelerator_mods };
	}

	void AccelGroup::Accelerator::DefaultModeMask(ModifierType default_mod_mask)
	{
		gtk_accelerator_set_default_mod_mask((GdkModifierType)default_mod_mask);
	}

	CGui::ModifierType AccelGroup::Accelerator::DefaultModeMask()
	{
		return (ModifierType)gtk_accelerator_get_default_mod_mask();
	}

	GtkAccelGroup* AccelGroup::GetWidget()
	{
		return accel_group;
	}
}
