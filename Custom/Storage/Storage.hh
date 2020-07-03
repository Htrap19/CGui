#pragma once

#include <iostream>
#include "../List/List.hh"
#include <any>

namespace CGui
{
	class Storage
	{
	public:
		Storage(const Storage&) = delete;
		Storage(const Storage&&) = delete;
		Storage& operator=(const Storage&) = delete;
		Storage& operator==(const Storage&) = delete;

		~Storage()
		{
			delete std::any_cast<KeyValue::List<std::any, std::any>*>(l_instance->First().value);
			delete l_instance;
		}

		template <typename Key, typename Value> void Add(std::any key, std::any value, const char* passkey = NULL)
		{
			if (passkey == NULL)
			{
				auto innerList = std::any_cast<KeyValue::List<std::any, std::any>*>(l_instance->First().value);
				innerList->Insert(key, value);
			}
			else
			{
				auto f = [](KeyValue::Node<std::any, std::any> * node, const char* pass, std::any * key, std::any * value)
				{
					try
					{
						if (std::any_cast<std::string>(node->key) != "NULL" && std::any_cast<std::string>(node->key) == std::string(pass))
						{
							auto innerList = std::any_cast<KeyValue::List<Key, Value>*>(node->value);
							innerList->Insert(std::any_cast<Key>(*key), std::any_cast<Value>(*value));
						}
					}
					catch (const std::bad_any_cast & e)
					{
						std::cout << e.what() << std::endl;
					}
				};

				l_instance->ForEach((void(*)(KeyValue::Node<std::any, std::any>*, const char*, std::any*, std::any*))f, passkey, &key, &value);
			}
		}

		template <typename Key = std::any, typename Value = std::any> void ForEach(void(*func)(KeyValue::Node<Key, Value>*), const char* passkey = NULL)
		{
			if (passkey == NULL || std::string(passkey) == "NULL")
			{
				auto innerList = std::any_cast<KeyValue::List<Key, Value>*>(l_instance->First().value);
				innerList->ForEach(func);
			}
			else
			{
				auto f = [](KeyValue::Node<std::any, std::any> * node, const char* pass, void(*func)(KeyValue::Node<Key, Value>*))
				{
					try
					{
						if (std::any_cast<std::string>(node->key) != "NULL" && std::any_cast<std::string>(node->key) == std::string(pass))
						{
							auto innerList = std::any_cast<KeyValue::List<Key, Value>*>(node->value);
							innerList->ForEach(func);
						}
					}
					catch (const std::bad_any_cast & e)
					{
						std::cout << e.what() << std::endl;
					}
				};

				l_instance->ForEach((void(*)(KeyValue::Node<std::any, std::any>*, const char*, void(*)(KeyValue::Node<Key, Value>*)))f, passkey, func);
			}
		}

		static Storage& GetInstance()
		{
			static Storage instance;
			return instance;
		}

		bool IsExistsPrivate(const char* passkey)
		{
			bool exists = false;
			auto f = [](KeyValue::Node<std::any, std::any> * node, bool* e, const char* p) -> void
			{
				if (std::any_cast<std::string>(node->key) == std::string(p))
					* e = true;
			};

			l_instance->ForEach((void(*)(KeyValue::Node<std::any, std::any>*, bool*, const char*))f, &exists, passkey);

			return exists;
		}

		template <typename Key, typename Value> bool MakePrivate(const char* passkey)
		{
			if (!GetInstance().IsExistsPrivate(passkey))
			{
				bool inserted = false;
				auto f = [](KeyValue::Node<std::any, std::any> * node, bool* i, const char* pass, KeyValue::List<std::any, std::any> * l)
				{
					if (!*i)
						if (std::string(pass) == std::any_cast<std::string>(node->key))
							* i = false;
						else
						{
							l->Insert(std::string(pass), new KeyValue::List<Key, Value>);
							*i = true;
						}
				};
				l_instance->ForEach((void(*)(KeyValue::Node<std::any, std::any>*, bool*, const char*, KeyValue::List<std::any, std::any>*))f, &inserted, passkey, l_instance);

				return inserted;
			}
			else
				return false;
		}

		template <typename Key, typename Value> bool Free(const char* passkey)
		{
			bool deleted;
			auto f = +[](KeyValue::Node<std::any, std::any> * node, const char* pass, bool* d)
			{
				if (std::string(pass) == std::any_cast<std::string>(node->key))
				{
					delete std::any_cast<KeyValue::List<Key, Value>*>(node->value);
					*d = true;
				}
				else
					*d = false;
			};

			l_instance->ForEach((void(*)(KeyValue::Node<std::any, std::any>*, const char*, bool*))f, passkey, &deleted);

			return deleted;
		}

	private:
		KeyValue::List<std::any, std::any>* l_instance;
		Storage() : l_instance{ new KeyValue::List<std::any, std::any> }
		{
			l_instance->Insert(std::string("NULL"), new KeyValue::List<std::any, std::any>);
		}
	};
};
