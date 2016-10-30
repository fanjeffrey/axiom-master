#if !defined SeqList_H
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
        virtual T* GetData();
        virtual int Locate(T value);
        virtual void Insert(T value, int index);
        virtual T Delete(int index);
        virtual void Display();
    protected:
        T data[Capacity];
        int length;
};

#endif
