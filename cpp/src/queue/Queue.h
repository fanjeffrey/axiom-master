#if !defined(Queue_H)
#define Queue_H

#include <string>

using namespace std;

template <typename T>
class Queue
{
  public:
    virtual void Enqueue(T &) = 0;
    virtual void Dequeue() = 0;
    virtual T &GetFront() = 0;
    virtual bool IsEmpty() = 0;
    virtual bool IsFull() = 0;
    virtual string ToString() = 0;
};

#endif