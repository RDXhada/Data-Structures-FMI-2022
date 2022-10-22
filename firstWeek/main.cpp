#include <iostream>


struct Node {
    int val;
    Node *next;
    Node(): val(0), next(nullptr)  {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
    
};


class LinkedList {
private:
    Node *head;
public:
    LinkedList() { head = nullptr;}
    
    ~LinkedList(){
        while (head != nullptr)
        {
            Node *current = head;
            head = head->next;
            delete current;
        }
    }
    
    //insert head to the list
    void insertFirst(int new_value)
    {
        head = new Node(new_value, head);
    }
    
    //insert last element to the list
    void insertLast(int new_value)
    {
        Node* new_node = new Node();
        
        Node *last = head;
        
        new_node->val = new_value;
        
        new_node->next = nullptr;
        
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    
    //insert After a given element
    void insertAfter(int previous, int new_value){
        Node *new_node = new Node(new_value);
        if (previous == head->val) {
            new_node->next = head->next;
            head->next = new_node;
            return;
        }
        
        Node *temp = head;
        while (temp->val != previous) {
            temp = temp->next;
            if (temp == nullptr) {
                return;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    
    
    //push head first
    void push(int new_value)
    {
        Node *new_node = new Node();
        new_node->val = new_value;
        new_node->next = head;
        head = new_node;
    }
    
    //pop
    void pop()
    {
        if(head == nullptr){
            return;
        }
        
        Node *new_node = head;
        while(new_node->next->next != nullptr)
        {
            new_node = new_node->next;
        }
        delete new_node->next;
        new_node->next = nullptr;
    }
    
    void deleteFirst()
    {
        //check if element is NULL
        if(head == nullptr){
            return;
        }
        
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    
    void deleteLast(){
        
        //check if head is NULL
        if (head == nullptr) {
            return;
        }
        //check if next element is NULL
        if (head->next == nullptr) {
            delete head;
            return;
        }
        
        Node *previous_last = head;
        
        //find the previous to the last node(second last element)
        while(previous_last->next->next != nullptr)
        {
            previous_last = previous_last->next;
        }
        //delete last node
        delete (previous_last->next);
        
        //make the previous_last element to be last
        previous_last->next = nullptr;
    }
    
    
    //print list
    void printList()
    {
        Node* node = head;
        while (node != nullptr)
        {
            std::cout << " " << node->val;
            node = node->next;
        }
    }
    
};


int main(){
    LinkedList LL;
    
    //insert head
    LL.insertFirst(5);
    LL.insertFirst(7);
    LL.insertFirst(8);
    std::cout << "Adding element to head (list result): ";
    LL.printList();
    std::cout << std::endl;
    
    //insert last
    LL.insertLast(232);
    LL.insertLast(999);
    std::cout << "Addint last element(list result): ";
    LL.printList();
    std::cout << std::endl;
    std::cout << "Popping the last element:";
    LL.pop();
    LL.printList();
    std::cout << std::endl;
    std::cout << "Pushing the last element:";
    LL.push(3);
    LL.printList();
    std::cout << std::endl;
    std::cout<<"Insert after a given element:";
    LL.insertAfter(8, 38);
    LL.printList();
    std::cout << std::endl;
    std::cout << "Delete first element: ";
    LL.deleteFirst();
    LL.deleteFirst();
    LL.printList();
    std::cout << std::endl;
    std::cout << "Delete last element: ";
    LL.deleteLast();
    LL.printList();
    std::cout << std::endl;
    return 0;
}


