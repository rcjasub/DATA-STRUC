#include<iostream>
#include<climits>  // For INT_MIN
#include <stack>

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

class Stack {
private:
    Node* Top;
    int height;
    
public:
    Stack() {
        Top = nullptr;
        height = 0;
    }

    Stack(int value) {
        Node* newNode = new Node(value);
        Top = newNode;
        height = 1;
    }

    void printStack() {
        Node* temp = Top;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << endl;
    }

    void getTop() {
        std::cout << "Top: " << Top->value << endl;
    }

    int top()
    {
        if(Top)
        {
            return Top->value;
        }
        else
        {
            return INT_MIN;
        }
    }

    void getHeight() {
        std::cout << "Height: " << height << endl;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = Top;
        Top = newNode;
        height++;
    }

    int pop() {
        if (height == 0) return INT_MIN;

        Node* temp = Top;
        int popValue = Top->value;
        Top = Top->next;
        delete temp;
        height--;
        return popValue;
    }

    bool isEmpty() {
        return height == 0;
    }
};

class QueueUsingTwoStacks {
private:
    Stack stack1; 
    Stack stack2; 

public:

   int front()
   {
      if(stack2.isEmpty())
      {
        while(!stack1.isEmpty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
      }

      if(stack2.isEmpty())
      {
          return INT_MIN;
      }
    
      return stack2.top();
   }

   bool isEmpty()
   {
       return stack1.isEmpty() && stack2.isEmpty();
   }

   void enqueue(int value)
   {
    stack1.push(value);
   }

   int dequeue()
   {
     if(stack2.isEmpty())
     {
        if(stack1.isEmpty())
        {
            return INT_MIN;
        }

        while(!stack1.isEmpty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
     }

      int frontValue = stack2.top();
        stack2.pop();
        return frontValue;
   }

    
};

class Solution {
public:

    bool isVowel(char c) {
    c = tolower(c);          // convert to lowercase
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        // I want try this method. using stack because when we pop it comes in reverse
        // Create a function to check if it is a vowel
        // if it is push it to the stack
        // loop again to exchange vowels, with the stack (top)

        stack<char> Vowels;

        for(char x : s)
        {
           if(isVowel(x))
           {
              Vowels.push(x);
           }

        }

        for(int i = 0; i < s.length(); i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = Vowels.top();
                Vowels.pop();
            }
        }

        return s;

    }
};

int main() {
    
   Stack stack;
    stack.push(5);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    stack.printStack();
    stack.getTop();

    stack.pop();
    stack.pop();

    stack.printStack();

    QueueUsingTwoStacks queue;
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);

    cout << queue.front();
    queue.dequeue();
    cout << queue.front();

    return 0;
}
