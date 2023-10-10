#ifndef Single_Linked_List_H
#define Single_Linked_List_H

#include <iostream>
using namespace std;

template<typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    bool pop_front();
    bool pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
};

#endif // Single_Linked_List_H
