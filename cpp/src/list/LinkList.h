#include "LinearList.h"

template <class T>
class LinkList : public LinearList <T>
{
    public:
        virtual void Init();
        virtual T Get(int index);
        virtual int Locate(T value);
        virtual void Insert(T value, int index);
        virtual T Delete(int index);
    protected:
        LinkListNode<T> * head;
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
    if (length == 0)
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
