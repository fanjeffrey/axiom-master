#if !defined(Stack_H)
#define Stack_H

template <class T>
class Stack
{
  public:
    virtual void Push(T &) = 0;
    virtual void Pop() = 0;
    virtual T &GetTop() = 0;
    virtual bool IsEmpty() = 0;
    virtual bool IsFull() = 0;
};

#endif