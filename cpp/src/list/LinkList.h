#if !defined(LinkList_H)
#define LinkList_H

#include "LinearList.h"

// forward declaration
template <class T> class LinkList;

template <class T>
class LinkListNode
{
    friend class LinkList<T>;
    public:
        LinkListNode():next(nullptr){}
        virtual T GetData(){return data;}
        virtual LinkListNode<T> * GetNext() {return next;}
    private:
        T data;
        LinkListNode<T> * next;
};

template <class T>
class LinkList : public LinearList <T>
{
    // methods:
    public:
        LinkList() {head = new LinkListNode<T>;}
        virtual ~LinkList() {Dispose();}
        
        // from ILinearList
        virtual T Get(int index);
        virtual int Locate(T value);
        virtual void Insert(T value, int index);
        virtual T Delete(int index);
    protected:
        virtual void Dispose();
    
    // fields:
    protected:
        LinkListNode<T> * head;
};

template <class T>
T LinkList<T>::Get(int index)
{    
    this->ValidateBeforeGetting(index);

    LinkListNode<T> * p = head->next;
    while(p && --index)
    {
        p = p->next;
    }

    return p->data;
}

template <class T>
int LinkList<T>::Locate(T value)
{
    int index = 1;
    LinkListNode<T> * p = head->next;
    while(p && p->data != value)
    {
        index ++;
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
    
    LinkListNode<T> * p = head;
    while (p && --index)
    {
        p = p->next;
    }
    
    LinkListNode<T> * n = new LinkListNode<T>;
    n->data = value;
    n->next = p->next;
    p->next = n;

    this->Length() ++;
}

template <class T>
T LinkList<T>::Delete(int index)
{
    this->ValidateBeforeDeleteion(index);
    
    LinkListNode<T> * p = head;
    while (p && --index)
    {
        p = p->next;
    }
    
    if (p)
    {
        LinkListNode<T> * t = p->next;
        p->next = t->next;
        
        T retVal = t->data;
        delete t;

        this->Length() --;
        
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
    LinkListNode<T> * t = head->next;
    while(t)
    {
        head->next = t->next;
        delete t;
        t = head->next;
    }
}

#endif
