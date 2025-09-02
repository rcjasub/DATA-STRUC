#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public: 

    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty list" << endl;
        }
        else {
            while (temp != nullptr) {
                cout << temp->value;  // Print the node's value
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";  
                }
            }
            cout << endl;
        }
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    int getLength() {
        return length;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
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

    void deleteFirst() {
        if (length == 0) return;

        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;  
        }
        else {
            head = head->next;  // Update head
        }
        delete temp;
        length--;
    }

    void deleteLast() {
        if (length == 0) return;  
    
        if (length == 1) {
            delete head;  
            head = nullptr;  
            tail = nullptr;  
        }
        else {
            
            Node* temp = head;
            while (temp->next != tail) {  // Traverse to the second last node
                temp = temp->next;
            }
            
            // Now, 'temp' is the second last node
            delete tail;  // Delete the last node
            tail = temp;   // Update the tail pointer to point to the second last node
            tail->next = nullptr;  // Set the new tail's 'next' to nullptr
        }
    
        length--; 
    }
    
    void makeEmpty() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void Reverse()
    {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = temp->next;
        Node* before = nullptr;

        for(int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;

        }

    }

    Node* findMiddleNode() {
        Node* fast = head;
        Node* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // Slow moves one step at a time
            fast = fast->next->next;   // Fast moves two steps at a time
        }

        return slow; // Once fast reaches the end, slow will be at the middle
    }
  
    Node* findMid() {
        int midIndex = length / 2;
        Node* temp = head;  
        
        while(midIndex--) {
            temp = temp->next;  
        }
        
        return temp;  
    }
    
    void prepend(int value)
    {
      Node* newNode = new Node(value);
      if(length == 0) 
      {
        head = newNode;
        tail = newNode;
      }
      else
      {
        newNode->next = head;
        head = newNode;
      }
      length++;
    }

   bool insert(int index, int value)
   {
    if(length < 0 || index > length) return false;

    if(index == 0)
    {
        prepend(value);
        return true;
    }

    if(length == length)
    {
        append(value);
        return true;
    }

    Node* newNode = new Node(value);
    Node* temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
   }

    bool hasloop() {
        Node* tortoise = head; // slow pointer
        Node* hare = head; // fast pointer

        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (tortoise == hare) {
                return true; 
            }
        }
        return false; 
    }

    Node* findKthFromEnd(int k) {
        if (head == nullptr || k <= 0) return nullptr;
        Node* fast = head;
        Node* slow = head;

        for (int i = 1; i < k; i++) {
            if (fast == nullptr) {
                return nullptr; 
            }
            fast = fast->next;
        }

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Returns the Kth node from the end
    }

    void removeDuplicates() {
        if (head == nullptr) return;  

        unordered_set<int> values;  
        Node* previous = nullptr;   
        Node* current = head;       

        while (current != nullptr) {
            // If the value already exists in the set, it's a duplicate
            if (values.find(current->value) != values.end()) {
                // Bypass the current node
                previous->next = current->next;

                // Delete the duplicate node
                Node* temp = current;
                current = current->next; 
                delete temp;  

                length--;
            }
            else {
            
                values.insert(current->value);

                previous = current;

                current = current->next;
            }
        }
    }

    void partitionList(int x) {
        // Return if the list is empty
        if (head == nullptr) return;
     
        // Create dummy nodes for two lists
        Node dummy1(0);  // List for nodes < x
        Node dummy2(0);  // List for nodes >= x
        
        // Initialize pointers for two lists
        Node* left = &dummy1;
        Node* right = &dummy2;
        
        // Initialize the current pointer
        Node* current = head;
     
        // Iterate through the list
        while (current != nullptr) {
            // If the value is less than x
            if (current->value < x) {
                left->next = current;
                left = current;
            } else { // If the value is >= x
                right->next = current;
                right = current;
            }
            // Move to the next node
            current = current->next;
        }
     
        // Terminate the second list
        right->next = nullptr;
        
        // Connect the two lists
        left->next = dummy2.next;
        
        // Update the head of the list
        head = dummy1.next;
    }
    
    void reverseBetween(int L, int R)
    {
        if(L == R) return;

        Node* dummy = new Node(0);// this is a dummy node, a fake head of list
        dummy->next = head;// the dummy node points to the head of the original list
        Node* pre = dummy;// 'pre' points to the fake head of the list

        for(int i = 0; i < L - 1; i++) pre = pre->next;// pre points to the node before the L node

        Node* start = pre->next;// starrt points to the L node
        Node* then = start->next;// then points to the node after L

        for(int i = 0; i < R - L; i++)
        {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }

    }

    int binaryToDecimal() {
        int decimal = 0;
        Node* temp = head;  

        while (temp != nullptr) {
            decimal = decimal * 2 + temp->value;    
            temp = temp->next;  
        }

        return decimal;
    }


  static Node* MergeTwoSortedLists(Node* list1, Node* list2)
    {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->value < list2->value)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if(list1 != nullptr) tail->next = list1;
        if(list2 != nullptr) tail->next = list2;

        Node* MergeHead = dummy->next;
        delete dummy; // Free the dummy node
        return MergeHead; // Return the merged list starting from the next node of dummy
    }
};

int main() {
    LinkedList list1(1);
    list1.append(2);
    list1.append(3);
    list1.append(5);
    list1.append(6);
  
    LinkedList list2(1);
    list2.append(2);
    list2.append(3);
    list2.append(5);
    list2.append(6);
    
    cout << "List 1: ";
    list1.printList();
    cout << "List 2: ";
    list2.printList();

    Node* mergedHead = LinkedList::MergeTwoSortedLists(list1.getHead(), list2.getHead());

    cout << "Merged List: ";
    Node* temp = mergedHead;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

   
    return 0;
}

