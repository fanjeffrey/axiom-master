#if !defined(SeqList_H)
#define SeqList_H

#include "LinearList.h"

template <class T>
class SeqList : public LinearList<T>
{
  public:
    virtual T Get(int index);
    virtual int Locate(T value);
    virtual void Insert(T value, int index);
    virtual T Delete(int index);
    virtual void Reverse();
    virtual void Subtract(const SeqList<T> &);

  protected:
    T elements[Capacity];
};

//
template <class T>
T SeqList<T>::Get(int index)
{
    this->ValidateBeforeGetting(index);

    return elements[index - 1];
}

template <class T>
int SeqList<T>::Locate(T value)
{
    for (int i = 1; i <= this->length; i++)
    {
        if (elements[i - 1] == value)
            return i;
    }

    return -1;
}

template <class T>
void SeqList<T>::Insert(T value, int index)
{
    this->ValidateBeforeInsertion(index);

    for (int i = this->length - 1; i >= index - 1; i--)
    {
        elements[i + 1] = elements[i];
    }

    elements[index - 1] = value;

    this->length++;
}

template <class T>
T SeqList<T>::Delete(int index)
{
    this->ValidateBeforeDeleteion(index);

    T temp = elements[index - 1];

    for (int i = index - 1; i < this->length - 1; i++)
    {
        elements[i] = elements[i + 1];
    }

    this->length--;

    return temp;
}

template <class T>
void SeqList<T>::Reverse()
{
    int m = this->length / 2;
    for (int i = 0; i < m; i++)
    {
        T temp = elements[i];
        elements[i] = elements[this->length - 1 - i];
        elements[this->length - 1 - i] = temp;
    }
}

// This method assumes that both lists are already sorted in ascending order.
template <class T>
void SeqList<T>::Subtract(const SeqList<T> &listB)
{
    int i = 0;
    int j = 0;

    while (i < this->length && j < listB.length)
    {
        if (elements[i] < listB.elements[j])
        {
            i++;
        }
        else if (listB.elements[j] < elements[i])
        {
            j++;
        }
        else
        {
            for (int k = i; k < this->length; k++)
            {
                elements[k] = elements[k + 1];
            }

            this->length--;
        }
    }
}

#endif
