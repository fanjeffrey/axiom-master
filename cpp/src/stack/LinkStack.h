#if !defined(LinkStack_H)
#define LinkStack_H

#include "Stack.h"

template <typename T>
class LinkStack;

template <typename T>
class StackNode
{
  public:
    StackNode() { next = NULL; }

  private:
    T data;
    StackNode *next;

    //
    friend class LinkStack<T>;
};

template <typename T>
class LinkStack : public Stack<T>
{
  public:
    virtual void Push(T &);
    virtual void Pop();
    virtual T &GetTop();
    virtual bool IsEmpty() { return top == NULL; }
    virtual bool IsFull() { return false; }

  public:
    LinkStack() { top = NULL; }
    virtual ~LinkStack() { Dispose(); };

  protected:
    virtual void Dispose();

  private:
    StackNode<T> *top;
};

template <typename T>
void LinkStack<T>::Push(T &e)
{
    StackNode<T> *n = new StackNode<T>;
    n->data = e;
    n->next = top;
    top = n;
}

template <typename T>
void LinkStack<T>::Pop()
{
    if (IsEmpty())
    {
        throw "Error: the stack is empty.";
    }

    StackNode<T> *t = top;
    top = top->next;
    delete t;
}

template <typename T>
T &LinkStack<T>::GetTop()
{
    if (IsEmpty())
    {
        throw "Error: the stack is empty.";
    }

    return top->data;
}

template <typename T>
void LinkStack<T>::Dispose()
{
    StackNode<T> *t;
    while (top)
    {
        t = top;
        top = top->next;
        delete t;
    }
}

#endif