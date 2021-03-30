#pragma once

#include <vector>

namespace CGui
{
	namespace Experimetal
	{
		template <typename T>
		class CallableGroup
		{
		public:
			CallableGroup() = default;

			CallableGroup(std::initializer_list<T*> list)
				: m_Objects(list)
			{
			}

			void Add(T* object)
			{
				if (!this->Exists(object))
					m_Objects.push_back(object);
			}

			void Add(std::initializer_list<T*> list)
			{
				for (auto object : list)
				{
					m_Objects.push_back(object);
				}
			}

			template <typename Func, typename ... Args>
			void Call(Func func, Args ... args)
			{
				for (auto& object : m_Objects)
				{
					(object->*func)(args...);
				}
			}

			std::vector<T*>& GetList()
			{
				return m_Objects;
			}

			bool Exists(T* object)
			{
				for (auto obj : m_Objects)
				{
					if (obj == object)
						return true;
				}

				return false;
			}

		private:
			std::vector<T*> m_Objects;
		};
	}
}