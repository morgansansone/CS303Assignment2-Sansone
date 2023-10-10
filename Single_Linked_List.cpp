#include "Single_Linked_List.h"
#include <cstddef> // Include this header for size_t

// Constructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    // Implement the destructor to delete all nodes and free memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Function to check if the list is empty
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

// Function to insert an item at the front of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node{item, head};
    if (empty()) {
        tail = new_node;
    }
    head = new_node;
    ++num_items;
}

// Function to insert an item at the end of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node{item, nullptr};
    if (empty()) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
    ++num_items;
}

// Function to remove the item from the front of the list
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        return false; // Return false if the list is empty
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    --num_items;
    if (empty()) {
        tail = nullptr;
    }
    return true;
}

// Function to retrieve the item from the front of the list
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        // Handle empty list (you might throw an exception or return a default value)
    }
    return head->data;
}

// Function to insert an item at a specific index
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items; // Insert at the end if index is beyond the end of the list
    }
    if (index == 0) {
        push_front(item); // Special case for inserting at the front
    } else if (index == num_items) {
        push_back(item); // Special case for inserting at the back
    } else {
        Node* current = head;
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        Node* new_node = new Node{item, current->next};
        current->next = new_node;
        ++num_items;
    }
}

// Function to remove an item at a specific index
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false; // Return false if index is beyond the end of the list
    }
    if (index == 0) {
        return pop_front(); // Special case for removing the first element
    } else {
        Node* current = head;
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        --num_items;
        if (index == num_items - 1) {
            tail = current; // Update tail if the last element is removed
        }
        return true;
    }
}

// Function to find the position of the first occurrence of an item
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index; // Return the index if item is found
        }
        current = current->next;
        ++index;
    }
    return num_items; // Return the size of the list if item is not found
}
