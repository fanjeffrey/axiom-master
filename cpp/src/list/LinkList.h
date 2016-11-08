#if !defined(LinkList_H)
#define LinkList_H

#include "LinearList.h"

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
    LinkList(const LinkList<T> &);
    LinkList<T> &operator=(const LinkList<T> &);
    virtual ~LinkList() { Dispose(); }

    //
    virtual T Get(int index);
    virtual int Locate(T value);
    virtual void Insert(T value, int index);
    virtual T Delete(int index);
    virtual void Reverse();
    virtual LinkList<T> Split();
    virtual void InsertSort();
    virtual void Merge(LinkList<T> &);
    virtual LinkList<T> Intersect(const LinkList<T> &);

  protected:
    virtual void CreateFrom(const LinkList<T> &);
    virtual void Dispose();

    // fields:
  protected:
    LinkListNode<T> *head;
};

template <class T>
LinkList<T>::LinkList(const LinkList<T> &other)
{
    CreateFrom(other);
}

template <class T>
LinkList<T> &LinkList<T>::operator=(const LinkList<T> &other)
{
    if (this == &other)
        return *this;

    Dispose();
    CreateFrom(other);
}

template <class T>
void LinkList<T>::CreateFrom(const LinkList<T> &other)
{
    head = new LinkListNode<T>;

    LinkListNode<T> *r = head;
    LinkListNode<T> *t = other.head->next;
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

    this->length = other.Count();
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

    this->length++;
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

        this->length--;

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
    LinkListNode<T> *a = head;
    LinkListNode<T> *b = to.head;
    LinkListNode<T> *cur = head->next; // point to the 1st node

    while (cur)
    {
        a->next = cur;
        a = cur;

        cur = cur->next; // move to the 2nd node
        if (cur)
        {
            b->next = cur;
            b = cur;

            cur = cur->next;

            to.length++;
            this->length--;
        }
    }

    a->next = b->next = nullptr;

    return to;
}

template <class T>
void LinkList<T>::InsertSort()
{
    if (head->next == nullptr)
        return; // if this is an empty link list
    if (head->next->next == nullptr)
        return; // if only 1 node in this list

    LinkListNode<T> *a, *b, *c, *d;
    c = head->next;
    d = head->next->next;
    while (d)
    {
        if (d->data < c->data)
        {
            a = head;
            b = head->next;
            while (b && b != d && b->data < d->data)
            {
                a = b;
                b = b->next;
            }

            if (b)
            {
                c->next = d->next;
                a->next = d;
                d->next = b;
            }
        }
        c = d;
        d = d->next;
    }
}

// Merge a link list sorted in ascending order.
// Before merging, make sure that both lists have been sorted in ascending order,
// if not, call InsertSort() prior to call this method.
template <class T>
void LinkList<T>::Merge(LinkList<T> &listToMerge)
{
    LinkListNode<T> *a, *b, *c;

    a = head->next;
    b = listToMerge.head->next;
    c = head;

    while (a && b)
    {
        if (a->data < b->data)
        {
            c->next = a;
            c = a;
            a = a->next;
        }
        else
        {
            c->next = b;
            c = b;
            b = b->next;
        }
    }

    c->next = a ? a : b;

    this->length += listToMerge.Count();
    listToMerge.length = 0;
}

template <class T>
LinkList<T> LinkList<T>::Intersect(const LinkList<T> &listB)
{
    LinkList<T> listC;

    LinkListNode<T> *a, *b, *c, *t;
    a = head->next;
    b = listB.head->next;
    c = listC.head;

    while (a && b)
    {
        if (a->data < b->data)
        {
            a = a->next;
        }
        else if (b->data < a->data)
        {
            b = b->next;
        }
        else // a->data equals to b->data
        {
            t = new LinkListNode<T>;
            t->data = a->data;

            c->next = t; // add to link list C
            c = c->next; // move to rear
            listC.length ++;

            a = a->next;
            b = b->next;
        }
    }

    return listC;
}

#endif
