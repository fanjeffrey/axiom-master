#include "LinearList.h"

template <class T>
class LinkList : public LinearList <T>
{
    public:
        LinkList() {head = new LinkListNode;}
        virtual ~LinkList() {Dispose();}
        virtual void Init();
        virtual T Get(int index);
        virtual int Locate(T value);
        virtual void Insert(T value, int index);
        virtual T Delete(int index);
        virtual bool IsEmpty() {return head == nullptr || head->next == nullptr;}
        virtual bool IsFull() {return length > 100;}
    protected:
        LinkListNode<T> * head;
        virtual void Dispose();
};

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
void LinkList<T>::Init()
{
    head->next = nullptr;
}

template <class T>
T LinkList<T>::Get(int index)
{    
    if (IsEmpty())
    {
        throw "The list is empty.";      
    }
    
    if (index < 1 || index > length)
    {
        throw "No data at that position.";    
    }

    LinkListNode * p = head->next;
    while(p && --index)
    {
        p = p->next;
    }

    return p->data;
}

template <class T>
int LinkList<T>::Locate(T value)
{
    int index = 0;
    LinkListNode * p = head->next;
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
    if (IsFull())
    {
        throw "The list is full.";
    }
    
    if (index < 1 || index > length + 1)
    {
        throw "Wrong position for insertion.";
    }
    
    LinkListNode * p = head;
    while (p && --index)
    {
        p = p->next;
    }
    
    LinkListNode * n = new LinkListNode;
    n->data = value;
    n->next = p->next;
    p->next = n;    
}

template <class T>
T LinkList<T>::Delete(int index)
{
    if (IsEmpty())
    {
        throw "The list is empty.";
    }
    
    if (index < 1 || index > length)
    {
        throw "Wrong position for deletion.";
    }
    
    LinkListNode * p = head;
    while (p && --index)
    {
        p = p->next;
    }
    
    if (p)
    {
        LinkListNode * t = p->next;
        p->next = t->next;
        
        T retVal = t->data;
        delete t;
        
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

}
