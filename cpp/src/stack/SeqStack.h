#if !defined(SeqStack_H)
#define SeqStack_H

#include <vector>
#include <sstream>
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
    virtual string ToString();

  private:
    vector<T> elements;
};

template <typename T>
void SeqStack<T>::Push(T &e)
{
    if (IsFull())
    {
        throw "Error: the stack is full.";
    }

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
    return elements[elements.size() - 1];
}

template <typename T>
inline bool SeqStack<T>::IsEmpty()
{
    return elements.empty(); //.size() == 0;
}

template <typename T>
inline bool SeqStack<T>::IsFull()
{
    return elements.size() >= elements.max_size();
}

template <typename T>
string SeqStack<T>::ToString()
{
    ostringstream os;
    if (IsEmpty())
    {
        os << "0 elements." << endl;
    }
    else
    {
        os << elements.size() << " elements:";
        for (int i = elements.size() - 1; i >= 0; i--)
        {
            os << " " << elements[i];
        }
    }

    return os.str();
}

#endif