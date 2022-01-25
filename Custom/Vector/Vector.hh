#pragma once

#include <utility>

namespace CGui
{
	template <typename Vector>
	class VectorIterator
	{
	public:
		using ValueType = typename Vector::ValueType;
		using ReferenceType = ValueType&;
		using PointerType = ValueType*;

	public:
		VectorIterator(PointerType ptr)
			: m_Ptr(ptr) {}

		VectorIterator& operator++()
		{
			m_Ptr++;
			return *this;
		}

		VectorIterator operator++(int)
		{
			VectorIterator temp = *this;
			++(*this);
			return temp;
		}

		VectorIterator& operator--()
		{
			m_Ptr--;
			return *this;
		}

		VectorIterator operator--(int)
		{
			VectorIterator temp = *this;
			--(*this);
			return temp;
		}

		ReferenceType operator+(size_t num)
		{
			return (*this)[num];
		}

		ReferenceType operator-(size_t num)
		{
			return *(m_Ptr - num);
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

		bool operator==(const VectorIterator& other) const
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const VectorIterator& other) const
		{
			return !(*this == other);
		}

	private:
		PointerType m_Ptr;
	};

	template <typename T>
	class Vector
	{
	public:
		using ValueType = T;
		using Iterator = VectorIterator<Vector<T>>;

	public:
		Vector()
		{
			ReAlloc(2); // Default capacity is 2
		}

		Vector(const Vector& other)
		{
			ReAlloc(other.m_Capacity);
			for (size_t i = 0; i < other.m_Size; i++)
				new(&m_Data[i]) T(other.m_Data[i]);
			m_Size = other.m_Size;
		}

		Vector(Vector&& other) noexcept
		{
			m_Data = other.m_Data;
			m_Size = other.m_Size;
			m_Capacity = other.m_Capacity;
			other.m_Data = nullptr;
			other.m_Size = 0;
			other.m_Capacity = 0;
		}

		~Vector()
		{
			Clear();
			::operator delete(m_Data, m_Capacity * sizeof(T));
		}

		void PushBack(const T& value)
		{
			if (m_Size >= m_Capacity)
				ReAlloc(m_Capacity + (m_Capacity / 2));

			m_Data[m_Size++] = value;
		}

		void PushBack(T&& value)
		{
			if (m_Size >= m_Capacity)
				ReAlloc(m_Capacity + (m_Capacity / 2));

			m_Data[m_Size++] = std::move(value);
		}

		template <typename ... Args>
		T& EmplaceBack(Args&& ... args)
		{
			if (m_Size >= m_Capacity)
				ReAlloc(m_Capacity + (m_Capacity / 2));

			new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
			return m_Data[m_Size++];
		}

		void PopBack()
		{
			if (m_Size < 0)
				return;

			m_Size--;
			m_Data[m_Size].~T();
		}

		void Resize()
		{
			if (m_Capacity <= m_Size)
				return;

			ReAlloc(m_Size);
		}

		void Clear()
		{
			for (size_t i = 0; i < m_Size; i++)
				m_Data[i].~T();

			m_Size = 0;
		}

		size_t Size() const
		{
			return m_Size;
		}

		size_t Capacity() const
		{
			return m_Capacity;
		}

		T& Front()
		{
			return m_Data[0];
		}

		T& Back()
		{
			return m_Data[m_Size - 1];
		}

		Iterator begin()
		{
			return Iterator(m_Data);
		}

		Iterator end()
		{
			return Iterator(m_Data + m_Size);
		}

		T& operator[](size_t index)
		{
			if (index > m_Size)
				throw "[Vector]: Out of range!.";

			return m_Data[index];
		}

		const T& operator[](size_t index) const
		{
			if (index > m_Size)
				throw "[Vector]: Out of range!.";

			return m_Data[index];
		}

		Vector& operator=(const Vector& other)
		{
			Clear();
			if (!m_Data)
				::operator delete(m_Data, m_Capacity * sizeof(T));

			ReAlloc(other.m_Capacity);
			for (size_t i = 0; i < other.m_Size; i++)
				new(&m_Data[i]) T(other.m_Data[i]);
			m_Size = other.m_Size;
			return *this;
		}

		Vector& operator=(Vector&& other)
		{
			Clear();
			if (!m_Data)
				::operator delete(m_Data, m_Capacity * sizeof(T));

			m_Data = other.m_Data;
			m_Size = other.m_Size;
			m_Capacity = other.m_Capacity;
			other.m_Data = nullptr;
			other.m_Size = 0;
			other.m_Capacity = 0;
			return *this;
		}

	protected:
		void ReAlloc(size_t newCapacity)
		{
			T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

			if (newCapacity < m_Size)
				m_Size = newCapacity;

			for (size_t i = 0; i < m_Size; i++)
				new(&newBlock[i]) T(std::move(m_Data[i]));

			for (size_t i = 0; i < m_Size; i++)
				m_Data[i].~T();

			::operator delete(m_Data, m_Capacity * sizeof(T));
			m_Data = newBlock;
			m_Capacity = newCapacity;
		}

	private:
		T* m_Data = nullptr;

		size_t m_Size = 0;
		size_t m_Capacity = 0;
	};
}