#if !defined(SeqList_H)
#define SeqList_H

#include "LinearList.h"

template <class T>
class SeqList : public LinearList, public ILinearList <T>
{
    public:
        // from ILinearList
        virtual T Get(int index);
        virtual int Locate(T value);
        virtual void Insert(T value, int index);
        virtual T Delete(int index);

        // native
        virtual T* Elements();
    protected:
        T elements[Capacity];
};

//
template <class T>
T SeqList<T>::Get(int index)
{
    ValidateBeforeGetting(index);
    
    return elements[index - 1];
}

template <class T>
int SeqList<T>::Locate(T value)
{
    for(int i=1; i<=length; i++)
    {
        if (elements[i-1] == value) return i;
    }
    
    return -1;
}

template <class T>
void SeqList<T>::Insert(T value, int index)
{    
    ValidateBeforeInsertion(index);
    
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
    ValidateBeforeDeleteion(index);
    
    T temp = elements[index - 1];
    
    for (int i = index - 1; i < length - 1; i++)
    {
        elements[i] = elements[i+1];
    }
    
    length --;
    
    return temp;
}

//
template <class T>
T* SeqList<T>::Elements()
{
    return elements;
}

#endif
