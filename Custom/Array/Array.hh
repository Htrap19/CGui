#pragma once

namespace CGui
{
	template <typename Array>
	class ArrayIterator
	{
	public:
		using ValueType = typename Array::ValueType;
		using ReferenceType = ValueType&;
		using PointerType = ValueType*;

	public:
		ArrayIterator(PointerType ptr)
			: m_Ptr(ptr) {}

		ArrayIterator& operator++()
		{
			m_Ptr++;
			return *this;
		}

		ArrayIterator operator++(int)
		{
			ArrayIterator temp = *this;
			++(*this);
			return temp;
		}

		ArrayIterator& operator--()
		{
			m_Ptr--;
			return *this;
		}

		ArrayIterator operator--(int)
		{
			ArrayIterator temp = *this;
			--(*this);
			return temp;
		}

		ReferenceType operator[](size_t index)
		{
			return *(m_Ptr + index);
		}

		PointerType operator->()
		{
			return m_Ptr;
		}

		ReferenceType operator*()
		{
			return *m_Ptr;
		}

		bool operator==(const ArrayIterator& other)
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const ArrayIterator& other)
		{
			return !(*this == other);
		}

	private:
		PointerType m_Ptr;
	};

	template <typename T, size_t size>
	class Array
	{
	public:
		using ValueType = T;
		using Iterator = ArrayIterator<Array<T, size>>;

	public:
		Array()
		{
		}

		constexpr uint32_t Size() const
		{
			return size;
		}

		Iterator begin()
		{
			return Iterator(m_Data);
		}

		Iterator end()
		{
			return Iterator(m_Data + size);
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