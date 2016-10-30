
#include <iostream>
#include <algorithm>
#include <iterator>
#include "SeqList.h"

using namespace std;


template <class T>
SeqList<T>::SeqList()
{
    T data[Capacity];
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
    
    return data[index - 1];
}

template <class T>
T* SeqList<T>::GetData()
{
    return data;
}

template <class T>
int SeqList<T>::Locate(T value)
{
    for(int i=0; i<length; i++)
    {
        if (data[i] == value) return i;
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
    
    for (int i = length - 1; i >= index; i--)
    {
        data[i + 1] = data[i];
    }
    
    data[index - 1] = value;
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
    
    T temp = data[index - 1];
    
    for (int i = index - 1; i < length - 1; i++)
    {
        data[i] = data[i+1];
    }
    
    length --;
    
    return temp;
}

template <class T>
void SeqList<T>::Display()
{
    cout << "Elements: ";
    copy(data, data + length, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    SeqList<int> isl;
    isl.Init();
    cout << "Created a sequencial list..." << endl;
    cout << "length = " << isl.Length() << endl;
    
    for(int i=1; i<=10; i++)
    {
        int val = i;
        cout << "Inserting " << val << " at " << isl.Length() << "..." << endl;
        isl.Insert(val, isl.Length() + 1);
        cout << "Inserted. length = " << isl.Length() << endl;
    }
    
    isl.Display();
    
    isl.Delete(7);
    isl.Display();
    
    isl.Insert(7, 3);
    isl.Display();
    
    return 0;
}
