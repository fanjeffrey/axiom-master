#if !defined(LinearList_H)
#define LinearList_H

#define Capacity 1000

template <class T>
class LinearList
{
    public:
        virtual T Get(int index) = 0;
        virtual int Locate(T value) = 0;
        virtual void Insert(T value, int index) = 0;
        virtual T Delete(int index) = 0;
    public:
        virtual int Count() {return Length();} // return the count of the elements for external access 
        virtual bool IsEmpty() {return Length() == 0;}
        virtual bool IsFull() {return Length() == Capacity;}
    protected:
        virtual int& Length() {return length;} // only for internal access
        virtual bool IsValidGettingIndex(int index) {return index < 1 || index > Length();}
        virtual bool IsValidInsertionIndex(int index) {return index < 1 || index > Length() + 1;}
        virtual bool IsValidDeletionIndex(int index) {return index < 1 || index > Length();}
        virtual void ValidateBeforeGetting(int index);
        virtual void ValidateBeforeInsertion(int index);
        virtual void ValidateBeforeDeleteion(int index);
    private:
        int length;
};

template <class T>
inline void LinearList<T>::ValidateBeforeGetting(int index)
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

template <class T>
inline void LinearList<T>::ValidateBeforeInsertion(int index)
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

template <class T>
inline void LinearList<T>::ValidateBeforeDeleteion(int index)
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

#endif
