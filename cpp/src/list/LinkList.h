#if !defined(LinkList_H)
#define LinkList_H

#include "LinearList.h"
#include <iostream>
using namespace std;

// forward declaration
template <class T>
class LinkList;

template <class T>
class LinkListNode
{
    friend class LinkList<T>;

  public:
    LinkListNode() : next(nullptr) {}
    virtual T GetData() { return data; }
    virtual LinkListNode<T> *GetNext() { return next; }
  private:
    T data;
    LinkListNode<T> *next;
};

template <class T>
class LinkList : public LinearList<T>
{
    // methods:
  public:
    LinkList() { head = new LinkListNode<T>; }
    LinkList(const LinkList<T> &rll);
    LinkList<T>& operator= (LinkList<T>&);
    virtual ~LinkList() { Dispose(); }

    //
    virtual T Get(int index);
    virtual int Locate(T value);
    virtual void Insert(T value, int index);
    virtual T Delete(int index);
    virtual void Reverse();
    virtual LinkList<T> Split();

  protected:
    virtual void CopyFrom(const LinkList<T>&);
    virtual void Dispose();

    // fields:
  protected:
    LinkListNode<T> *head;
};

template <class T>
LinkList<T>::LinkList(const LinkList<T> &rll)
{cout << "In copy() ..." << endl;
    CopyFrom(rll);
}

template <class T>
LinkList<T>& LinkList<T>::operator= (LinkList<T>& rll)
{cout << "In operator=() ..." << endl;
    if (this == &rll) return *this;

    Dispose();
    CopyFrom(rll);
}

template <class T>
void LinkList<T>::CopyFrom(const LinkList<T> & rll)
{
    head = new LinkListNode<T>;

    LinkListNode<T> *r = head;
    LinkListNode<T> *t = rll.head->next;
    LinkListNode<T> *n;
    while (t)
    {
        n = new LinkListNode<T>;
        n->data = t->data;

        r->next = n;
        r = n;

        t = t->next;
    }

    r = t = n = nullptr;
}

template <class T>
T LinkList<T>::Get(int index)
{
    this->ValidateBeforeGetting(index);

    LinkListNode<T> *p = head->next;
    while (p && --index)
    {
        p = p->next;
    }

    return p->data;
}

template <class T>
int LinkList<T>::Locate(T value)
{
    int index = 1;
    LinkListNode<T> *p = head->next;
    while (p && p->data != value)
    {
        index++;
        p = p->next;
    }

    if (p)
        return index;
    else
        return -1;
}

template <class T>
void LinkList<T>::Insert(T value, int index)
{
    this->ValidateBeforeInsertion(index);

    LinkListNode<T> *p = head;
    while (p && --index)
    {
        p = p->next;
    }

    LinkListNode<T> *n = new LinkListNode<T>;
    n->data = value;
    n->next = p->next;
    p->next = n;

    this->Length()++;
}

template <class T>
T LinkList<T>::Delete(int index)
{
    this->ValidateBeforeDeleteion(index);

    LinkListNode<T> *p = head;
    while (p && --index)
    {
        p = p->next;
    }

    if (p)
    {
        LinkListNode<T> *t = p->next;
        p->next = t->next;

        T retVal = t->data;
        delete t;

        this->Length()--;

        return retVal;
    }
    else
    {
        throw "Error: ";
    }
}

template <class T>
void LinkList<T>::Dispose()
{
    LinkListNode<T> *t = head->next;
    while (t)
    {
        head->next = t->next;
        delete t;
        t = head->next;
    }

    delete head;
}

template <class T>
void LinkList<T>::Reverse()
{
    if (head->next == nullptr)
        return; // if this is an empty link list, do nothing.
    if (head->next->next == nullptr)
        return; // if only 1 node, do nothing.

    LinkListNode<T> *newRearNode = head->next;
    LinkListNode<T> *oldFirstNode = head->next->next;
    LinkListNode<T> *t;

    newRearNode->next = nullptr;

    while (oldFirstNode)
    {
        t = oldFirstNode;
        oldFirstNode = oldFirstNode->next;
        t->next = head->next;
        head->next = t;
    }

    t = nullptr;
}

template <class T>
LinkList<T> LinkList<T>::Split()
{
    LinkList<T> to;
    LinkListNode<T> *a = head->next;
    LinkListNode<T> *b = to.head;
    LinkListNode<T> *t;

    while (a)
    {
        t = a;
        a = a->next;
        if (a)
        {
            t->next = a->next;

            b->next = a;
            b = a;

            to.Length()++;
            this->Length()--;

            a = a->next;
        }
    }

    a = b = t = nullptr;

    return to;
}

#endif
