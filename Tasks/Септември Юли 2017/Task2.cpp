#include<iostream>

struct Node {
    int data;
    Node* next;
};

void sortList(Node* first) {
    Node* slow = first;
    Node* fast;
    while(slow != nullptr) {
        fast = slow->next;
        while (fast != nullptr) {
            if(slow->data > fast->data) {
                int temp = slow->data;
                slow->data = fast->data;
                fast->data = temp;
            }
            fast = fast->next;
        }
        slow = slow->next;
    }
}

void push(Node*& first, int elem)
{
    if(first == nullptr) {
        first = new Node{elem, nullptr};
        return;
    }
    first = new Node{elem, first};
}

void print(Node* list) {
    while(list != nullptr) {
        std::cout << list->data << "->";
        list = list->next;
    }
    std::cout << "null\n";
}

int main() {
    Node* a;
    push(a, 3);
    push(a, 10);
    push(a, 4);
    push(a, 1);
    print(a);

    sortList(a);
    print(a);
}