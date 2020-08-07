#pragma once

#include <iostream>
#include "../List/List.hh"

namespace CGui
{
	class DeleteOnQuit
	{
	public:
		DeleteOnQuit(const DeleteOnQuit&) = delete;
		DeleteOnQuit(const DeleteOnQuit&&) = delete;
		DeleteOnQuit& operator=(const DeleteOnQuit&) = delete;
		DeleteOnQuit& operator=(const DeleteOnQuit&&) = delete;
		DeleteOnQuit& operator==(const DeleteOnQuit&) = delete;
		DeleteOnQuit& operator==(const DeleteOnQuit&&) = delete;

		static DeleteOnQuit& GetInstance()
		{
			static DeleteOnQuit instance;
			return instance;
		}

		void Add(void* data)
		{
			l_instance->Insert(data);
		}

		void ForEach(void(*func)(void*))
		{
			l_instance->ForEach(func);
		}

		Single::List<void*>* list()
		{
			return l_instance;
		}

		~DeleteOnQuit()
		{
			l_instance->ForEach([](void* data) -> void
				{
					delete data;
				});
			delete l_instance;
		}

	private:
		DeleteOnQuit() : l_instance{ new Single::List<void*> }
		{
		}

		Single::List<void*>* l_instance;
	};
};
