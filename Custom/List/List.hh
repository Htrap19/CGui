#pragma once

#include <utility>

namespace CGui
{
	namespace Single
	{
		template <typename List>
		class ListIterator
		{
		public:
			using NodePtr = typename List::NodePtr;
			using ReferenceType = typename List::ValueType&;

		public:
			ListIterator(NodePtr ptr) : m_Ptr(ptr)
			{}

			ListIterator& operator++()
			{
				m_Ptr = m_Ptr->m_Next;
				return *this;
			}

			ListIterator& operator++(int)
			{
				ListIterator temp = *this;
				m_Ptr = m_Ptr->m_Next;
				return temp;
			}

			ReferenceType operator[](size_t index)
			{
				if (index == 0)
					return m_Ptr->m_Data;

				size_t idx = 0;
				while (m_Ptr != nullptr)
				{
					if (idx == index)
						break;

					m_Ptr = m_Ptr->m_Next;
					idx++;
				}

				return m_Ptr->m_Data;
			}

			ReferenceType operator*()
			{
				return m_Ptr->m_Data;
			}

			bool operator==(const ListIterator& other)
			{
				return (m_Ptr == other.m_Ptr);
			}

			bool operator!=(const ListIterator& other)
			{
				return !(*this == other);
			}

		private:
			NodePtr m_Ptr;
		};

		template <typename T>
		struct Node
		{
			T m_Data;
			Node<T>* m_Next;

			Node() = default;
			Node(const T& data) : m_Data(data), m_Next(nullptr)
			{}
			Node(T&& data) : m_Data(std::move(data)), m_Next(nullptr)
			{}

			Node(const Node&) = delete;
			Node(Node&&) = delete;
		};

		template <typename T>
		class List
		{
		public:
			using ValueType = T;
			using Node = typename Node<T>;
			using NodePtr = Node*;
			using Iterator = ListIterator<List<T>>;

		public:
			List() : m_Head(nullptr), m_Size(0)
			{
			}

			List(const List& other)
			{
				m_Size = other.m_Size;
				NodePtr node = other.m_Head;
				while (node != nullptr)
				{
					NodePtr newNode = new Node(node->m_Data);
					PlaceBackNode(newNode);
					node = node->m_Next;
				}
			}

			List(List&& other)
			{
				m_Size = other.m_Size;
				m_Head = other.m_Head;
				other.m_Head = nullptr;
				other.m_Size = 0;
			}

			~List()
			{
				Clear();
			}

			void PushFront(const T& obj)
			{
				NodePtr newNode = new Node(obj);
				m_Size++;
				PlaceFrontNode(newNode);
			}

			void PushFront(T&& obj)
			{
				NodePtr newNode = new Node(std::move(obj));
				m_Size++;
				PlaceFrontNode(newNode);
			}

			void PushBack(const T& obj)
			{
				NodePtr newNode = new Node(obj);
				m_Size++;
				PlaceBackNode(newNode);
			}

			void PushBack(T&& obj)
			{
				NodePtr newNode = new Node(std::move(obj));
				m_Size++;
				PlaceBackNode(newNode);
			}

			template <typename ... Args>
			T& EmplaceFront(Args&& ... args)
			{
				NodePtr newNode = (NodePtr)::operator new(sizeof(Node));
				new(&newNode->m_Data) T(std::forward<Args>(args)...);
				m_Size++;

				PlaceFrontNode(newNode);

				return newNode->m_Data;
			}

			template <typename ... Args>
			T& EmplaceBack(Args&& ... args)
			{
				NodePtr newNode = (NodePtr)::operator new(sizeof(Node));
				new(&newNode->m_Data) T(std::forward<Args>(args)...);
				m_Size++;

				PlaceBackNode(newNode);

				return newNode->m_Data;
			}

			void Remove(const T& obj)
			{
				NodePtr node = m_Head;
				NodePtr prevNode = nullptr;
				while (node != nullptr)
				{
					if (const_cast<T&>(obj) == node->m_Data)
						break;

					prevNode = node;
					node = node->m_Next;
				}

				if (node != nullptr)
				{
					if (prevNode != nullptr)
						prevNode->m_Next = node->m_Next;
					else
						m_Head = node->m_Next;

					node->m_Data.~T();
					::operator delete(node, sizeof(Node));
					m_Size--;
				}
			}

			void Clear()
			{
				NodePtr node = m_Head;
				NodePtr nextNode = nullptr;
				while (node != nullptr)
				{
					nextNode = node->m_Next;
					node->m_Data.~T();
					::operator delete(node, sizeof(Node));

					node = nextNode;
				}
				m_Head = nullptr;
				m_Size = 0;
			}

			size_t Size() const
			{
				return m_Size;
			}

			Iterator begin()
			{
				return Iterator(m_Head);
			}

			Iterator end()
			{
				return Iterator(nullptr);
			}

			T& operator[](size_t index)
			{
				if (index > m_Size)
					throw "[List]: Out of range!.";

				return begin()[index];
			}

			const T& operator[](size_t index) const
			{
				if (index > m_Size)
					throw "[List]: Out of range!.";

				return begin()[index];
			}

		protected:
			void PlaceFrontNode(NodePtr newNode)
			{
				newNode->m_Next = m_Head;
				m_Head = newNode;
			}

			void PlaceBackNode(NodePtr newNode)
			{
				if (m_Head == nullptr)
					PlaceFrontNode(newNode);
				else
				{
					NodePtr node = m_Head;
					while (node != nullptr && node->m_Next != nullptr)
						node = node->m_Next;

					newNode->m_Next = node->m_Next;
					node->m_Next = newNode;
				}
			}

		private:
			NodePtr m_Head;
			size_t m_Size;
		};

	}
	using Single::List;
}