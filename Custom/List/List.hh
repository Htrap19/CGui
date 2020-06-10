#pragma once

#include <iostream>

namespace CGui
{
	namespace Single
	{
		template <typename Data>
		class Node
		{
		public:
			Data data;
			Node<Data>* next;
		};

		template <typename Data>
		class List
		{
		public:
			List(void);
			~List(void);
			bool IsEmpty();
			Node<Data>* Insert(Data data);
			Node<Data>* First();
			Node<Data>* Last();
			unsigned int Size();
			bool SelectData(Data data);
			bool HasSelectedData();
			Data& SelectedData();
			bool Exists(Data data);
			template <typename filter> List<filter> Filter(filter(*func)(Node<Data>*));
			template <typename filter> List<filter> Filter(filter(*func)(Data&));
			template <typename filter, typename ... Args> List<filter> Filter(filter(*func)(Node<Data>*, Args...), Args& ... args);
			template <typename filter, typename ... Args> List<filter> Filter(filter(*func)(Data&, Args...), Args& ... args);
			Node<Data>* Find(Data data);
			void ForEach(void(*func)(Node<Data>*));
			void ForEach(void(*func)(Data&));
			template <typename ... Args> void ForEach(void(*func)(Node<Data>*, Args...), Args& ... args);
			template <typename ... Args> void ForEach(void(*func)(Data&, Args...), Args& ... args);
			bool Delete(Data data);

			Data& operator[](unsigned int index);

		private:
			Node<Data>* head;
			unsigned int size;
			Data* selected_data;
		};

		template <typename Data>
		List<Data>::List() : size{ 0 }, selected_data{ NULL }
		{
			head = NULL;
		}

		template <typename Data>
		List<Data>::~List()
		{
			Node<Data>* currNode = head;
			Node<Data>* nextNode = NULL;

			while (currNode != NULL)
			{
				nextNode = currNode->next;
				delete currNode;
				currNode = nextNode;
			}
		}

		template <typename Data>
		Node<Data>* List<Data>::Insert(Data data)
		{
			Node<Data>* currNode = head;
			while (currNode && currNode->next != NULL)
				currNode = currNode->next;

			Node<Data> * newNode = new Node<Data>;
			newNode->data = data;

			if (head == NULL)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = currNode->next;
				currNode->next = newNode;
			}

			size++;
			return newNode;
		}

		template <typename Data>
		Node<Data>* List<Data>::First()
		{
			return head;
		}

		template <typename Data>
		Node<Data>* List<Data>::Last()
		{
			Node<Data>* currNode = head;
			while (currNode && currNode->next != NULL)
				currNode = currNode->next;

			return currNode;
		}

		template <typename Data>
		unsigned int List<Data>::Size()
		{
			return size;
		}

		template <typename Data>
		bool List<Data>::SelectData(Data data)
		{
			Node<Data>* currNode = head;

			while (currNode != NULL)
			{
				if (currNode->data == data)
				{
					selected_data = &data;
					return true;
				}
				else
				{
					currNode = currNode->next;
					continue;
				}
			}

			return false;
		}

		template <typename Data>
		bool List<Data>::HasSelectedData()
		{
			return !(selected_data == NULL);
		}

		template <typename Data>
		Data& List<Data>::SelectedData()
		{
			return *selected_data;
		}

		template <typename Data>
		bool List<Data>::Exists(Data data)
		{
			Node<Data>* currNode = head;

			while (currNode && currNode->next != NULL)
			{
				if (currNode->data == data)
					return true;

				currNode = currNode->next;
			}

			return false;
		}

		template <typename Data>
		template <typename filter> List<filter> List<Data>::Filter(filter(*func)(Node<Data>*))
		{
			Node<Data>* currNode = head;
			List<filter> ret;

			while (currNode != NULL)
			{
				ret.Insert(func(currNode));
				currNode = currNode->next;
			}

			return ret;
		}

		template <typename Data>
		template <typename filter> List<filter> List<Data>::Filter(filter(*func)(Data&))
		{
			Node<Data>* currNode = head;
			List<filter> ret;

			while (currNode != NULL)
			{
				ret.Insert(func(currNode->data));
				currNode = currNode->next;
			}

			return ret;
		}

		template <typename Data>
		template <typename filter, typename ... Args> List<filter> List<Data>::Filter(filter(*func)(Node<Data>*, Args...), Args & ... args)
		{
			Node<Data>* currNode = head;
			List<filter> ret;

			while (currNode != NULL)
			{
				ret.Insert(func(currNode, args...));
				currNode = currNode->next;
			}

			return ret;
		}

		template <typename Data>
		template <typename filter, typename ... Args> List<filter> List<Data>::Filter(filter(*func)(Data&, Args...), Args & ... args)
		{
			Node<Data>* currNode = head;
			List<filter> ret;

			while (currNode != NULL)
			{
				ret.Insert(func(currNode->data, args...));
				currNode = currNode->next;
			}

			return ret;
		}

		template <typename Data>
		Node<Data>* List<Data>::Find(Data data)
		{
			Node<Data>* currNode = head;

			while (currNode && currNode != NULL)
			{
				if (currNode->data == data)
					return currNode;
			}

			return NULL;
		}

		template <typename Data>
		void List<Data>::ForEach(void(*func)(Node<Data>*))
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode);
				currNode = currNode->next;
			}
		}

		template <typename Data>
		void List<Data>::ForEach(void(*func)(Data&))
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode->data);
				currNode = currNode->next;
			}
		}

		template <typename Data>
		template <typename ... Args> void List<Data>::ForEach(void(*func)(Node<Data>*, Args...), Args & ... args)
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode, args...);
				currNode = currNode->next;
			}
		}

		template <typename Data>
		template <typename ... Args> void List<Data>::ForEach(void(*func)(Data&, Args...), Args & ... args)
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode->data, args...);
				currNode = currNode->next;
			}
		}

		template <typename Data>
		bool List<Data>::Delete(Data data)
		{
			Node<Data>* currNode = head;
			Node<Data>* prevNode = NULL;

			while (currNode && currNode->next != NULL)
			{
				if (currNode->data != data)
				{
					prevNode = currNode;
					currNode = currNode->next;
				}
				else
					break;
			}

			if (currNode)
				if (prevNode)
				{
					prevNode->next = currNode->next;
					delete currNode;
					size--;
					return true;
				}
				else
				{
					head = currNode->next;
					delete currNode;
					size--;
					return true;
				}

			return false;
		}

		template<typename Data>
		Data& List<Data>::operator[](unsigned int index)
		{
			if (index <= 0)
				return head->data;

			Node<Data> * currNode = head;
			unsigned int currIndex = 0;

			while (currNode && currNode != NULL)
			{
				if (currIndex != index)
				{
					currNode = currNode->next;
					currIndex++;
					continue;
				}
				else
					break;
			}

			return currNode->data;
		}
	};

	namespace KeyValue
	{
		template <typename Key, typename Value>
		class Node
		{
		public:
			Key key;
			Value value;
			Node<Key, Value>* next;
		};

		template <typename Key, typename Value>
		class List
		{
		public:
			List(void);
			~List(void);
			bool IsEmpty();
			Node<Key, Value>* Insert(Key key, Value value);
			Node<Key, Value>* First();
			Node<Key, Value>* Last();
			unsigned int Size();
			bool ExistsValue(Value value);
			bool ExistsKey(Key key);
			Node<Key, Value>* FindByKey(Key key);
			Node<Key, Value>* FindByValue(Value value);
			void ForEach(void(*func)(Node<Key, Value>*));
			void ForEach(void(*func)(Key&, Value&));
			template <typename ... Args> void ForEach(void(*func)(Node<Key, Value>*, Args...), Args ... args);
			template <typename ... Args> void ForEach(void(*func)(Key&, Value&, Args...), Args ... args);
			bool DeleteKey(Key key);
			bool DeleteValue(Value value);

			std::pair<Key, Value> operator[](unsigned int index);

		private:
			Node<Key, Value>* head;
			unsigned int size;
		};

		template <typename Key, typename Value>
		List<Key, Value>::List() : size{ 0 }
		{
			head = NULL;
		}

		template <typename Key, typename Value>
		List<Key, Value>::~List()
		{
			Node<Key, Value>* currNode = head, * nextNode = NULL;

			while (currNode != NULL)
			{
				nextNode = currNode->next;
				delete currNode;
				currNode = nextNode;
			}
		}

		template <typename Key, typename Value>
		bool List<Key, Value>::IsEmpty()
		{
			return (head == NULL);
		}

		template <typename Key, typename Value>
		Node<Key, Value>* List<Key, Value>::Insert(Key key, Value value)
		{
			Node<Key, Value>* currNode = head;

			while (currNode && currNode->next != NULL)
				currNode = currNode->next;

			Node<Key, Value> * newNode = new Node<Key, Value>;
			newNode->key = key;
			newNode->value = value;

			if (head == NULL)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = currNode->next;
				currNode->next = newNode;
			}

			size++;
			return newNode;
		}

		template <typename Key, typename Value>
		Node<Key, Value>* List<Key, Value>::First()
		{
			return head;
		}

		template <typename Key, typename Value>
		Node<Key, Value>* List<Key, Value>::Last()
		{
			Node<Key, Value>* currNode = head;

			while (currNode && currNode->next != NULL)
				currNode = currNode->next;

			return currNode;
		}

		template <typename Key, typename Value>
		unsigned int List<Key, Value>::Size()
		{
			return size;
		}

		template <typename Key, typename Value>
		bool List<Key, Value>::ExistsKey(Key key)
		{
			Node<Key, Value>* currNode = head;

			while (currNode && currNode->next != NULL)
			{
				if (currNode->key == key)
					return true;
			}

			return false;
		}

		template <typename Key, typename Value>
		bool List<Key, Value>::ExistsValue(Value value)
		{
			Node<Key, Value>* currNode = head;

			while (currNode && currNode->next != NULL)
			{
				if (currNode->value == value)
					return true;
			}

			return false;
		}

		template <typename Key, typename Value>
		Node<Key, Value>* List<Key, Value>::FindByKey(Key key)
		{
			Node<Key, Value> currNode = head;

			while (currNode && currNode != NULL)
			{
				if (currNode->key == key)
					return currNode;
			}

			return NULL;
		}

		template <typename Key, typename Value>
		Node<Key, Value>* List<Key, Value>::FindByValue(Value value)
		{
			Node<Key, Value> currNode = head;

			while (currNode && currNode != NULL)
			{
				if (currNode->value == value)
					return currNode;
			}

			return NULL;
		}

		template <typename Key, typename Value>
		void List<Key, Value>::ForEach(void(*func)(Node<Key, Value>*))
		{
			Node<Key, Value>* currNode = head;

			while (currNode != NULL)
			{
				func(currNode);
				currNode = currNode->next;
			}
		}

		template <typename Key, typename Value>
		void List<Key, Value>::ForEach(void(*func)(Key&, Value&))
		{
			Node<Key, Value>* currNode = head;

			while (currNode != NULL)
			{
				func(currNode->key, currNode->value);
				currNode = currNode->next;
			}
		}

		template <typename Key, typename Value>
		template <typename ... Args> void List<Key, Value>::ForEach(void(*func)(Node<Key, Value>*, Args...), Args ... args)
		{
			Node<Key, Value>* currNode = head;

			while (currNode != NULL)
			{
				func(currNode, args...);
				currNode = currNode->next;
			}
		}

		template <typename Key, typename Value>
		template <typename ... Args> void List<Key, Value>::ForEach(void(*func)(Key&, Value&, Args...), Args ... args)
		{
			Node<Key, Value>* currNode = head;

			while (currNode != NULL)
			{
				func(currNode->key, currNode->value, args...);
				currNode = currNode->next;
			}
		}

		template <typename Key, typename Value>
		bool List<Key, Value>::DeleteKey(Key key)
		{
			Node<Key, Value>* currNode = head;
			Node<Key, Value>* prevNode = NULL;

			while (currNode && currNode->next != NULL)
			{
				if (currNode->key != key)
				{
					prevNode = currNode;
					currNode = currNode->next;
				}
				else
					break;
			}

			if (currNode)
				if (prevNode)
				{
					prevNode->next = currNode->next;
					delete currNode;
					size--;
					return true;
				}
				else
				{
					head = currNode->next;
					delete currNode;
					size--;
					return true;
				}

			return false;
		}

		template <typename Key, typename Value>
		bool List<Key, Value>::DeleteValue(Value value)
		{
			Node<Key, Value>* currNode = head;
			Node<Key, Value>* prevNode = NULL;

			while (currNode && currNode->next != NULL)
			{
				if (currNode->value != value)
				{
					prevNode = currNode;
					currNode = currNode->next;
				}
				else
					break;
			}

			if (currNode)
				if (prevNode)
				{
					prevNode->next = currNode->next;
					delete currNode;
					size--;
					return true;
				}
				else
				{
					head = currNode->next;
					delete currNode;
					size--;
					return true;
				}

			return false;
		}

		template <typename Key, typename Value>
		std::pair<Key, Value> List<Key, Value>::operator[](unsigned int index)
		{
			if (index <= 0)
				return std::make_pair(head->key, head->value);

			Node<Key, Value> * currNode = head;
			unsigned int currIndex = 0;

			while (currNode != NULL)
			{
				if (currIndex != index)
				{
					currNode = currNode->next;
					currIndex++;
					continue;
				}
				else
					break;
			}

			return std::make_pair(currNode->key, currNode->value);
		}
	};
};
