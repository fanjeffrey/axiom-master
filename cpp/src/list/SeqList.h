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

template <class T>
void SeqList<T>::Subtract(const SeqList<T> &listB)
{
    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < listB.length; j++)
        {
            if (elements[i] == listB.elements[j])
            {
                for (int k = i; k < this->length; k++)
                {
                    elements[k] = elements[k + 1];
                }

                this->length--;
            }
        }
    }
}

#endif
