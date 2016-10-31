#if !defined(SeqList_H)
#define SeqList_H

#include "LinearList.h"

#define Capacity 100

template <class T>
class SeqList : public LinearList <T>
{
    public:
        SeqList();
        virtual void Init();
        virtual int Length();
        virtual T Get(int index);
        virtual T* Elements();
        virtual int Locate(T value);
        virtual void Insert(T value, int index);
        virtual T Delete(int index);
    protected:
        T elements[Capacity];
        int length;
};

template <class T>
SeqList<T>::SeqList()
{
    T elements[Capacity];
    length = 0;
}

template <class T>
void SeqList<T>::Init()
{
    length = 0;
}

template <class T>
int SeqList<T>::Length()
{
    return length;
}

template <class T>
T SeqList<T>::Get(int index)
{
    if (length == 0)
    {
        throw "The list is empty.";      
    }
    
    if (index < 1 || index > length)
    {
        throw "No data at this position.";    
    }
    
    return elements[index - 1];
}

template <class T>
T* SeqList<T>::Elements()
{
    return elements;
}

template <class T>
int SeqList<T>::Locate(T value)
{
    for(int i=0; i<length; i++)
    {
        if (elements[i] == value) return i;
    }
    
    return -1;
}

template <class T>
void SeqList<T>::Insert(T value, int index)
{    
    if (length >= Capacity)
    {
        throw "The list is overflow.";
    }
    
    if (index < 1 || index > length + 1)
    {
        throw "Wrong position for insertion.";
    }
    
    for (int i = length - 1; i >= index - 1; i--)
    {
        elements[i + 1] = elements[i];
    }
    
    elements[index - 1] = value;
    length ++;
}

template <class T>
T SeqList<T>::Delete(int index)
{    
    if (length == 0)
    {
        throw "The list is empty.";
    }
    
    if (index < 1 || index > length)
    {
        throw "Wrong position for deletion.";
    }
    
    T temp = elements[index - 1];
    
    for (int i = index - 1; i < length - 1; i++)
    {
        elements[i] = elements[i+1];
    }
    
    length --;
    
    return temp;
}

#endif