#if !defined(SeqStack_H)
#define SeqStack_H

#include <vector>
#include "Stack.h"

using namespace std;

template <class T>
class SeqStack : public Stack<T>
{
  public:
    virtual void Push(T &);
    virtual void Pop();
    virtual T &GetTop();
    virtual bool IsEmpty();
    virtual bool IsFull();

  private:
    vector<T> elements;
};

template <typename T>
void SeqStack<T>::Push(T &e)
{
    elements.push_back(e);
}

template <typename T>
void SeqStack<T>::Pop()
{
    elements.pop_back();
}

template <typename T>
T &SeqStack<T>::GetTop()
{
    return elements[elements.size()];
}

template <typename T>
bool SeqStack<T>::IsEmpty()
{
    return elements.empty();//.size() == 0;
}

template <typename T>
bool SeqStack<T>::IsFull()
{
    return elements.size() >= elements.max_size();
}

#endif