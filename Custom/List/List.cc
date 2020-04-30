#pragma once

#include "./List.hh"

namespace CGui
{
  namespace Single
  {
    template <typename Data>
    List<Data>::List()
    { head = NULL; }

    template <typename Data>
    List<Data>::~List()
    {
      Node<Data> *currNode = head;
      Node<Data> *nextNode = NULL;

      while(currNode != NULL)
      {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
      }
    }

    template <typename Data>
    Node<Data> *List<Data>::Insert(Data data)
    {
      Node<Data> *currNode = head;
      while(currNode && currNode->next != NULL)
        currNode = currNode->next;

      Node<Data> *newNode = new Node<Data>;
      newNode->data = data;

      if(head == NULL)
      {
        newNode->next = head;
        head = newNode;
      }
      else
      {
        newNode->next = currNode->next;
        currNode->next = newNode;
      }

      return newNode;
    }

    template <typename Data>
    Node<Data> *List<Data>::First()
    { return head; }

    template <typename Data>
    Node<Data> *List<Data>::Last()
    {
      Node<Data> *currNode = head;
      while(currNode && currNode->next != NULL)
        currNode = currNode->next;

      return currNode;
    }

    template <typename Data>
    bool List<Data>::Exists(Data data)
    {
      Node<Data> *currNode = head;

      while(currNode && currNode->next != NULL)
      {
        if(currNode->data == data)
          return true;
      }

      return false;
    }

    template <typename Data>
    Node<Data> *List<Data>::Find(Data data)
    {
      Node<Data> *currNode = head;

      while(currNode && currNode != NULL)
      {
        if(currNode->data == data)
          return currNode;
      }

      return NULL;
    }

    template <typename Data>
    void List<Data>::ForEach(void(*func)(Node<Data>*))
    {
      Node<Data> *currNode = head;
      while(currNode != NULL)
      {
        func(currNode);
        currNode = currNode->next;
      }
    }

    template <typename Data>
    void List<Data>::ForEach(void(*func)(Data&))
    {
      Node<Data> *currNode = head;
      while(currNode != NULL)
      {
        func(currNode->data);
        currNode = currNode->next;
      }
    }

    template <typename Data>
    template <typename ... Args> void List<Data>::ForEach(void(*func)(Node<Data>*, Args...), Args ... args)
    {
      Node<Data> *currNode = head;
      while(currNode != NULL)
      {
        func(currNode, args...);
        currNode = currNode->next;
      }
    }

    template <typename Data>
    template <typename ... Args> void List<Data>::ForEach(void(*func)(Data&, Args...), Args ... args)
    {
      Node<Data> *currNode = head;
      while(currNode != NULL)
      {
        func(currNode->data, args...);
        currNode = currNode->next;
      }
    }

    template <typename Data>
    bool List<Data>::Delete(Data data)
    {
      Node<Data> *currNode = head;
      Node<Data> *prevNode = NULL;

      while(currNode && currNode->next != NULL)
      {
        if(currNode->data != data)
        {
          prevNode = currNode;
          currNode = currNode->next;
        }
        else
          break;
      }

      if(currNode)
        if(prevNode)
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
  };

  namespace KeyValue
  {
    template <typename Key, typename Value>
    List<Key, Value>::List()
    { head = NULL; }

    template <typename Key, typename Value>
    List<Key, Value>::~List()
    {
      Node<Key, Value> *currNode = head, *nextNode = NULL;

      while(currNode != NULL)
      {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
      }
    }

    template <typename Key, typename Value>
    bool List<Key, Value>::IsEmpty()
    { return (head == NULL); }

    template <typename Key, typename Value>
    Node<Key, Value> *List<Key, Value>::Insert(Key key, Value value)
    {
      Node<Key, Value> *currNode = head;

      while(currNode && currNode->next != NULL)
        currNode = currNode->next;

      Node<Key, Value> *newNode = new Node<Key, Value>;
      newNode->key = key;
      newNode->value = value;

      if(head == NULL)
      {
        newNode->next = head;
        head = newNode;
      }
      else
      {
        newNode->next = currNode->next;
        currNode->next = newNode;
      }

      return newNode;
    }

    template <typename Key, typename Value>
    Node<Key, Value> *List<Key, Value>::First()
    { return head; }

    template <typename Key, typename Value>
    Node<Key, Value> *List<Key, Value>::Last()
    {
      Node<Key, Value> *currNode = head;

      while(currNode && currNode->next != NULL)
        currNode = currNode->next;

      return currNode;
    }

    template <typename Key, typename Value>
    bool List<Key, Value>::ExistsKey(Key key)
    {
      Node<Key, Value> *currNode = head;

      while(currNode && currNode->next != NULL)
      {
        if(currNode->key == key)
          return true;
      }

      return false;
    }

    template <typename Key, typename Value>
    bool List<Key, Value>::ExistsValue(Value value)
    {
      Node<Key, Value> *currNode = head;

      while(currNode && currNode->next != NULL)
      {
        if(currNode->value == value)
          return true;
      }

      return false;
    }

    template <typename Key, typename Value>
    Node<Key, Value> *List<Key, Value>::FindByKey(Key key)
    {
      Node<Key, Value> currNode = head;

      while (currNode && currNode != NULL)
      {
        if(currNode->key == key)
          return currNode;
      }

      return NULL;
    }

    template <typename Key, typename Value>
    Node<Key, Value> *List<Key, Value>::FindByValue(Value value)
    {
      Node<Key, Value> currNode = head;

      while (currNode && currNode != NULL)
      {
        if(currNode->value == value)
          return currNode;
      }

      return NULL;
    }

    template <typename Key, typename Value>
    void List<Key, Value>::ForEach(void(*func)(Node<Key, Value>*))
    {
      Node<Key, Value> *currNode = head;

      while(currNode != NULL)
      {
        func(currNode);
        currNode = currNode->next;
      }
    }

    template <typename Key, typename Value>
    void List<Key, Value>::ForEach(void(*func)(Key&, Value&))
    {
      Node<Key, Value> *currNode = head;

      while(currNode != NULL)
      {
        func(currNode->key, currNode->value);
        currNode = currNode->next;
      }
    }

    template <typename Key, typename Value>
    template <typename ... Args> void List<Key, Value>::ForEach(void(*func)(Node<Key, Value>*, Args...), Args ... args)
    {
      Node<Key, Value> *currNode = head;

      while(currNode != NULL)
      {
        func(currNode, args...);
        currNode = currNode->next;
      }
    }

    template <typename Key, typename Value>
    template <typename ... Args> void List<Key, Value>::ForEach(void(*func)(Key&, Value&, Args...), Args ... args)
    {
      Node<Key, Value> *currNode = head;

      while(currNode != NULL)
      {
        func(currNode->key, currNode->value, args...);
        currNode = currNode->next;
      }
    }

    template <typename Key, typename Value>
    bool List<Key, Value>::DeleteKey(Key key)
    {
      Node<Key, Value> *currNode = head;
      Node<Key, Value> *prevNode = NULL;

      while(currNode && currNode->next != NULL)
      {
        if(currNode->key != key)
        {
          prevNode = currNode;
          currNode = currNode->next;
        }
        else
          break;
      }

      if(currNode)
        if(prevNode)
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
      Node<Key, Value> *currNode = head;
      Node<Key, Value> *prevNode = NULL;

      while(currNode && currNode->next != NULL)
      {
        if(currNode->value != value)
        {
          prevNode = currNode;
          currNode = currNode->next;
        }
        else
          break;
      }

      if(currNode)
        if(prevNode)
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
  };
};
