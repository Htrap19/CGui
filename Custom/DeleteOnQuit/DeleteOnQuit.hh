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

	class DeleteOnQuitArray
	{
	public:
		DeleteOnQuitArray(const DeleteOnQuitArray&) = delete;
		DeleteOnQuitArray(const DeleteOnQuitArray&&) = delete;
		DeleteOnQuitArray& operator=(const DeleteOnQuitArray&) = delete;
		DeleteOnQuitArray& operator=(const DeleteOnQuitArray&&) = delete;
		DeleteOnQuitArray& operator==(const DeleteOnQuitArray&) = delete;
		DeleteOnQuitArray& operator==(const DeleteOnQuitArray&&) = delete;

		static DeleteOnQuitArray& GetInstance()
		{
			static DeleteOnQuitArray instance;
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

		~DeleteOnQuitArray()
		{
			l_instance->ForEach([](void* data) -> void
				{
					delete[] data;
				});
			delete l_instance;
		}

	private:
		DeleteOnQuitArray() : l_instance{ new Single::List<void*> }
		{
		}

		Single::List<void*>* l_instance;
	};
};
