// Creator:  Ceon Jones
// Date: 4/25/2021
// Purpose: Implement a single linked list to be used as a stack

#ifndef SINGLE_LINKED_LIST_HPP // Include guard
#define SINGLE_LINKED_LIST_HPP // Define include guard

//Include necessary libraries
#include <iostream>
#include <stdexcept>
#include <numeric>

using namespace std;

//Single_Linked_List class
template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
       
        //Node constructor
        Node(const Item_Type& data_item, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {}
    };
    Node* head;
    Node* tail;
    size_t node_count;

public:
    //Single_Linked_List constructor and destructor
    Single_Linked_List();
    ~Single_Linked_List();

    //Single_Linked_List methods
    void push_front(const Item_Type& item);
    void pop_front();
    Item_Type& front() const;
    bool empty() const;
    size_t size() const;

    //Stack-specific methods
    void push(const Item_Type& item); //Push an element (same as push_front)
    void pop(); //Pop an element (same as pop_front)
    Item_Type& top() const; //Get the top element (same as front)
    bool is_empty() const; //Check if the stack is empty (same as empty)
    double average() const; //Calculate the average of the stack elements
    void display() const; //Display the stack
};

//Implementation

//constructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() 
    : head(nullptr), tail(nullptr), node_count(0) {}

//destructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

//push_front implementation (used for stack operations)
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {
        tail = head;
    }
    ++node_count;
}

//pop_front implementation
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        cout << "Stack is empty! Nothing to pop." << endl;
        return;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    --node_count;
    if (node_count == 0) {
        tail = nullptr;
    }
}


//front implementation
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        throw std::runtime_error("Empty list");
    }
    return head->data;
}

//empty implementation
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return node_count == 0;
}



//Reurns the number of nodes in the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return node_count;
}

//Stack specific method: Push an element
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push(const Item_Type& item) {
    push_front(item);
}

//Stack specific method: Pop an element
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop() {
    pop_front();
}

//Stack specific method: Get the top element
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::top() const {
    return front();
}

//Stack specific method: Check if the stack is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::is_empty() const {
    return empty();
}

//Stack specific method: Calculate the average of the stack elements
template <typename Item_Type>
double Single_Linked_List<Item_Type>::average() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty! Cannot calculate average.");
    }
    Node* current = head;
    double sum = 0;
    size_t count = 0;

    while (current != nullptr) {
        sum += current->data;
        current = current->next;
        ++count;
    }

    return sum / count;
}

//Stack specific method: Display the stack
template <typename Item_Type>
void Single_Linked_List<Item_Type>::display() const {
    if (empty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* current = head;
    cout << "Stack elements: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//Explicit template instantiation
//template class Single_Linked_List<int>;

#endif // SINGLE_LINKED_LIST_HPP