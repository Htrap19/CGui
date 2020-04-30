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
        Node<Data> *next;
    };

    template <typename Data>
    class List
    {
      public:
        List(void);
        ~List(void);
        bool IsEmpty();
        Node<Data> *Insert(Data data);
        Node<Data> *First();
        Node<Data> *Last();
        bool Exists(Data data);
        Node<Data> *Find(Data data);
        void ForEach(void(*func)(Node<Data>*));
        void ForEach(void(*func)(Data &data));
        template <typename ... Args> void ForEach(void(*func)(Node<Data>*, Args...), Args ... args);
        template <typename ... Args> void ForEach(void(*func)(Data&, Args...), Args ... args);
        bool Delete(Data data);

      private:
        Node<Data> *head;
    };
  };

  namespace KeyValue
  {
    template <typename Key, typename Value>
    class Node
    {
      public:
        Key key;
        Value value;
        Node<Key, Value> *next;
    };

    template <typename Key, typename Value>
    class List
    {
      public:
        List(void);
        ~List(void);

        bool IsEmpty();
        Node<Key, Value> *Insert(Key key, Value value);
        Node<Key, Value> *First();
        Node<Key, Value> *Last();
        bool ExistsValue(Value value);
        bool ExistsKey(Key key);
        Node<Key, Value> *FindByKey(Key key);
        Node<Key, Value> *FindByValue(Value value);
        void ForEach(void(*func)(Node<Key, Value>*));
        void ForEach(void(*func)(Key&, Value&));
        template <typename ... Args> void ForEach(void(*func)(Node<Key, Value>*, Args...), Args ... args);
        template <typename ... Args> void ForEach(void(*func)(Key&, Value&, Args...), Args ... args);
        bool DeleteKey(Key key);
        bool DeleteValue(Value value);

      private:
        Node<Key, Value> *head;
    };
  };
};

#include "./List.cc"
