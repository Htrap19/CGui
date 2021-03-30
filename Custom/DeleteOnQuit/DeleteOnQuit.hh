#pragma once

#include <iostream>
#include "../Vector/Vector.hh"

namespace CGui
{
	class DeleteOnQuit
	{
	public:
		DeleteOnQuit(const DeleteOnQuit&) = delete;
		DeleteOnQuit(DeleteOnQuit&&) = delete;
		DeleteOnQuit& operator=(const DeleteOnQuit&) = delete;
		DeleteOnQuit& operator=(DeleteOnQuit&&) = delete;
		DeleteOnQuit& operator==(const DeleteOnQuit&) = delete;
		DeleteOnQuit& operator==(DeleteOnQuit&&) = delete;

		static DeleteOnQuit& Instance()
		{
			static DeleteOnQuit instance;
			return instance;
		}

		void Add(void* data)
		{
			m_MemoryLocations.EmplaceBack(data);
		}

		~DeleteOnQuit()
		{
			for (auto& memoryaddr : m_MemoryLocations)
			{
				delete memoryaddr;
				memoryaddr = nullptr;
			}
		}

	private:
		DeleteOnQuit()
		{
		}

		Vector<void*> m_MemoryLocations;
	};
}