#if !defined(LinearList_H)
#define LinearList_H

#define Capacity 1000

class LinearList
{
    public:
        LinearList() : length(0){}
        virtual int Length() {return length;}
        virtual bool IsEmpty() {return length == 0;}
        virtual bool IsFull() {return length == Capacity;}      
    protected:
        int length;
        virtual bool IsValidGettingIndex(int index) {return index < 1 || index > length;}
        virtual bool IsValidInsertionIndex(int index) {return index < 1 || index > length + 1;}
        virtual bool IsValidDeletionIndex(int index) {return index < 1 || index > length;}
        virtual void ValidateBeforeGetting(int index);
        virtual void ValidateBeforeInsertion(int index);
        virtual void ValidateBeforeDeleteion(int index);
};

inline void LinearList::ValidateBeforeGetting(int index)
{
    if (IsEmpty())
    {
        throw "The list is empty.";      
    }
    
    if (IsValidGettingIndex(index))
    {
        throw "No data at that position.";    
    }
}

inline void LinearList::ValidateBeforeInsertion(int index)
{
    if (IsFull())
    {
        throw "The list is full.";
    }
    
    if (IsValidInsertionIndex(index))
    {
        throw "Wrong position for insertion.";
    }
}

inline void LinearList::ValidateBeforeDeleteion(int index)
{
    if (IsEmpty())
    {
        throw "The list is empty.";
    }
    
    if (IsValidDeletionIndex(index))
    {
        throw "Wrong position for deletion.";
    }
}

template <class T>
class ILinearList
{
    public:
        virtual T Get(int index) = 0;
        virtual int Locate(T value) = 0;
        virtual void Insert(T value, int index) = 0;
        virtual T Delete(int index) = 0;
};

#endif
