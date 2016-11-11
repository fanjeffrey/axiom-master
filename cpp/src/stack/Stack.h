#if !defined(Stack_H)
#define Stack_H

#include <string>

using namespace std;

template <class T>
class Stack
{
  public:
    virtual void Push(T &) = 0;
    virtual void Pop() = 0;
    virtual T &GetTop() = 0;
    virtual bool IsEmpty() = 0;
    virtual bool IsFull() = 0;
    virtual string ToString() = 0;
};

#endif