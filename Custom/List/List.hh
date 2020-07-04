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
			unsigned int Insert(Data data);
			Data First();
			Data Last();
			unsigned int Size();
			bool SelectData(Data data);
			bool HasSelectedData();
			Data& SelectedData();
			void UnselectData();
			bool Exists(Data data);
			bool Exists(bool(*func)(List<Data>*));
			template <typename filter> List<filter> Filter(filter(*func)(Node<Data>*));
			template <typename filter> List<filter> Filter(filter(*func)(Data&));
			template <typename filter, typename ... Args> List<filter> Filter(filter(*func)(Node<Data>*, Args...), Args ... args);
			template <typename filter, typename ... Args> List<filter> Filter(filter(*func)(Data&, Args...), Args ... args);
			unsigned int Find(Data data);
			void ForEach(void(*func)(Node<Data>*));
			void ForEach(void(*func)(Data&));
			void ForEach(void(*func)(Data));
			template <typename ... Args> void ForEach(void(*func)(Node<Data>*, Args...), Args ... args);
			template <typename ... Args> void ForEach(void(*func)(Data&, Args...), Args ... args);
			template <typename ... Args> void ForEach(void(*func)(Data, Args...), Args ... args);
			bool Delete(Data data);
			void DeleteAll();

			Data& operator[](unsigned int index);

		private:
			Node<Data>* head;
			Data* selected_data;
		};

		template <typename Data>
		List<Data>::List() : selected_data{ NULL }
		{
			head = NULL;
		}

		template <typename Data>
		List<Data>::~List()
		{
			this->DeleteAll();
		}

		template <typename Data>
		unsigned int List<Data>::Insert(Data data)
		{
			Node<Data>* currNode = head;
			unsigned int index = 0;

			while (currNode && currNode->next != NULL)
			{
				currNode = currNode->next;
				index++;
			}

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

			return index;
		}

		template <typename Data>
		Data List<Data>::First()
		{
			return head->data;
		}

		template <typename Data>
		Data List<Data>::Last()
		{
			Node<Data>* currNode = head;
			while (currNode && currNode->next != NULL)
				currNode = currNode->next;

			return currNode->data;
		}

		template <typename Data>
		unsigned int List<Data>::Size()
		{
			if (head == NULL)
				return 0;

			Node<Data> * currNode = head;
			unsigned int size = 0;

			while (currNode != NULL)
			{
				size++;
				currNode = currNode->next;
			}

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
		void List<Data>::UnselectData()
		{
			selected_data = NULL;
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
		bool List<Data>::Exists(bool(*func)(List<Data>*))
		{
			return func(this);
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
		template <typename filter, typename ... Args> List<filter> List<Data>::Filter(filter(*func)(Node<Data>*, Args...), Args ... args)
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
		template <typename filter, typename ... Args> List<filter> List<Data>::Filter(filter(*func)(Data&, Args...), Args ... args)
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
		unsigned int List<Data>::Find(Data data)
		{
			Node<Data>* currNode = head;
			unsigned int index = 0;

			while (currNode && currNode != NULL)
			{
				if (currNode->data == data)
					return index;

				currNode = currNode->next;
				index++;
			}

			return 0;
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

		template<typename Data>
		void List<Data>::ForEach(void(*func)(Data))
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode->data);
				currNode = currNode->next;
			}
		}

		template <typename Data>
		template <typename ... Args> void List<Data>::ForEach(void(*func)(Node<Data>*, Args...), Args ... args)
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode, args...);
				currNode = currNode->next;
			}
		}

		template <typename Data>
		template <typename ... Args> void List<Data>::ForEach(void(*func)(Data&, Args...), Args ... args)
		{
			Node<Data>* currNode = head;
			while (currNode != NULL)
			{
				func(currNode->data, args...);
				currNode = currNode->next;
			}
		}

		template<typename Data>
		template<typename ... Args> void List<Data>::ForEach(void(*func)(Data, Args...), Args ...args)
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
					return true;
				}
				else
				{
					head = currNode->next;
					delete currNode;
					return true;
				}

			return false;
		}

		template<typename Data>
		void List<Data>::DeleteAll()
		{
			Node<Data>* currNode = head;
			Node<Data>* nextNode = NULL;

			while (currNode != NULL)
			{
				nextNode = currNode->next;
				delete currNode;
				currNode = nextNode;
			}

			head = NULL;
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
			KeyValueData<Key, Value> Insert(Key key, Value value);
			KeyValueData<Key, Value> First();
			KeyValueData<Key, Value> Last();
			unsigned int Size();
			bool ExistsValue(Value value);
			bool ExistsKey(Key key);
			KeyValueData<Key, Value> FindByKey(Key key);
			KeyValueData<Key, Value> FindByValue(Value value);
			void ForEach(void(*func)(Node<Key, Value>*));
			void ForEach(void(*func)(Key&, Value&));
			template <typename ... Args> void ForEach(void(*func)(Node<Key, Value>*, Args...), Args ... args);
			template <typename ... Args> void ForEach(void(*func)(Key&, Value&, Args...), Args ... args);
			bool DeleteKey(Key key);
			bool DeleteValue(Value value);

			KeyValueData<Key, Value> operator[](unsigned int index);

		private:
			Node<Key, Value>* head;
		};

		template <typename Key, typename Value>
		List<Key, Value>::List()
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
		KeyValueData<Key, Value> List<Key, Value>::Insert(Key key, Value value)
		{
			Node<Key, Value>* currNode = head;
			unsigned int index = 0;

			while (currNode && currNode->next != NULL)
			{
				currNode = currNode->next;
				index++;
			}

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

			return { newNode->key, newNode->value, index };
		}

		template <typename Key, typename Value>
		KeyValueData<Key, Value> List<Key, Value>::First()
		{
			return { head->key, head->value, 0 };
		}

		template <typename Key, typename Value>
		KeyValueData<Key, Value> List<Key, Value>::Last()
		{
			Node<Key, Value>* currNode = head;
			unsigned int index = 0;

			while (currNode && currNode->next != NULL)
			{
				currNode = currNode->next;
				index++;
			}

			return { currNode->key, currNode->value, index };
		}

		template <typename Key, typename Value>
		unsigned int List<Key, Value>::Size()
		{
			if (head == NULL)
				return 0;

			Node<Key, Value> * currNode = head;
			unsigned int size = 0;

			while (currNode != NULL)
			{
				size++;
				currNode = currNode->next;
			}

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

				currNode = currNode->next;
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

				currNode = currNode->next;
			}

			return false;
		}

		template <typename Key, typename Value>
		KeyValueData<Key, Value> List<Key, Value>::FindByKey(Key key)
		{
			Node<Key, Value>* currNode = head;
			unsigned int index = 0;

			while (currNode && currNode != NULL)
			{
				if (currNode->key == key)
					return { currNode->key, currNode->value, index };

				currNode = currNode->next;
				index++;
			}

			return { };
		}

		template <typename Key, typename Value>
		KeyValueData<Key, Value> List<Key, Value>::FindByValue(Value value)
		{
			Node<Key, Value>* currNode = head;
			unsigned int index = 0;

			while (currNode && currNode != NULL)
			{
				if (currNode->value == value)
					return { currNode->key, currNode->value, index };

				currNode = currNode->next;
				index++;
			}

			return { };
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
					return true;
				}
				else
				{
					head = currNode->next;
					delete currNode;
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
					return true;
				}
				else
				{
					head = currNode->next;
					delete currNode;
					return true;
				}

			return false;
		}

		template <typename Key, typename Value>
		KeyValueData<Key, Value> List<Key, Value>::operator[](unsigned int index)
		{
			if (index <= 0)
				return { head->key, head->value };

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

			return { currNode->key, currNode->value };
		}
	};
};
