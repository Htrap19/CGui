#pragma once

namespace CGui
{
	template <typename T, size_t size>
	class Array
	{
	public:
		Array()
		{
		}

		constexpr int Size() const
		{
			return size;
		}

		T& operator[](size_t index)
		{
			return m_Data[index];
		}

		const T& operator[](size_t index) const
		{
			return m_Data[index];
		}

	private:
		T m_Data[size];
	};
}