#if !defined LinearList_H
#define LinearList_H

template <class T>
class LinearList
{
    public:
        virtual void Init() = 0;
        virtual int Length() = 0;
        virtual T Get(int index) = 0;
        virtual T* GetData() = 0;
        virtual int Locate(T value) = 0;
        virtual void Insert(T value, int index) = 0;
        virtual T Delete(int index) = 0;        
};

#endif
