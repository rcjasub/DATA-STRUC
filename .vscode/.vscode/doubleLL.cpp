#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head) {
            cout << "Head value: " << head->value << endl;
        } else {
            cout << "List is empty!" << endl;
        }
    }

    void getTail() {
        if (tail) {
            cout << "Tail value: " << tail->value << endl;
        } else {
            cout << "List is empty!" << endl;
        }
    }

    void getLength() {
        cout << "Length of the list: " << length << endl;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; // goes forward to new node
            newNode->prev = tail; // goes backward from the new node
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;

        Node* temp = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev; // Move the tail pointer backward
            tail->next = nullptr; // Disconnect the new tail's next pointer
        }
        delete temp;  // Delete the last node
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;

        Node* temp = nullptr;

        if (index < length / 2) {
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; i--) {
                temp = temp->prev;
            }
        }

        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;

        if (index == 0) {
            prepend(value);
            return true;
        }

        if (index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;

        newNode->prev = before;
        newNode->next = after;

        before->next = newNode;
        after->prev = newNode;

        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;

        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* temp = get(index);
        temp->next->prev = temp->prev;  // go forward , then back but this back points to the previous node
        temp->prev->next = temp->next; // go back, then forward but this forward points to the next node

        delete temp;
        length--;
    }

    void SwapFirstAndLast() {
        if (length < 2) return; // No swap needed if there are fewer than 2 nodes

        // Save the original head and tail
        Node* first = head;
        Node* last = tail;

        // Swap the head and tail pointers
        head = last;
        tail = first;

        // Update the new head's next and prev pointers
        head->next = first->next; // New head points to the second node
        head->prev = nullptr;     // New head's prev is null (it's the first node)

        // Update the new tail's next and prev pointers
        tail->prev = last->prev;  // New tail points to the second-to-last node
        tail->next = nullptr;     // New tail's next is null (it's the last node)

        // Fix the previous head's next pointer
        if (head->next) {
            head->next->prev = head; // The second node's prev points to the new head
        }

        // Fix the previous tail's prev pointer
        if (tail->prev) {
            tail->prev->next = tail; // The second-to-last node's next points to the new tail
        }
    }

    void FirstAndLastValueSwap() {
        if (length < 2) return;
        int temp = head->value;
        head->value = tail->value;
        tail->value = temp;
    }

    void reverse() {
        if(length < 2) return;

        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;;
        Node* before = nullptr;
        
        for(int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            temp->prev = after;
            before = temp;
            temp = after;
        }
    }

    bool IsPalindrome()
{
   if(length < 2) return true;

   Node* forward = head;
   Node* backward = tail;

   for(int i = 0; i < length/2; i++)
   {
     if(forward->value != backward->value) return false;

     forward = forward->next;
     backward = backward->prev;
   }

   return true;
}

// void swapPairs()
// {
//     if(length < 2) return;

//     Node* dummy = new Node(0);
//     Node* current = head;

//     while(current != )
// }

};

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);



   

    if(myDLL->IsPalindrome())
    {
        cout << "The list is a palindrome" << endl;
    }
    else
    {
        cout << "The list is not a palindrome" << endl;
    }
    myDLL->printList();


    return 0;
}
