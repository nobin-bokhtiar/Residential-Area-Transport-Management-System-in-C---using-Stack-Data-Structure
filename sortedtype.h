#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED

template <class ItemType>
class SortedType
{
    struct NodeType
    {
        ItemType info;
        int ID;
        NodeType* next;
    };
    public:
        SortedType();
        ~SortedType();
        bool IsFull();
        int LengthIs();
        void MakeEmpty();
        void RetrieveItem(ItemType&, bool&,int);
        void InsertItem(ItemType,int);
        void DeleteItem(ItemType,int);
        void ResetList();
        void GetNextItem(ItemType&,int&);
    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
};


#endif // SORTEDTYPE_H_INCLUDED
