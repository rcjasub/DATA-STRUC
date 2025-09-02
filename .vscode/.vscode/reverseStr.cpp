#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Stack
{
    private:
    vector<int> stackVector;

    public:
    void printStack() {
        for (int i = stackVector.size() - 1; i >= 0; i--) {
            cout << stackVector[i] << endl;
        }
    }

    bool isEmpty() {
        return stackVector.empty();
    }

    void push(int value) {
        stackVector.push_back(value);
    }

    void pop() {
        if(isEmpty()) return;
        stackVector.pop_back();
    }

    int peek() {
        if(isEmpty()) return INT_MIN;
        return stackVector.back();  // ✅ Fix: Return the top of the stack
    }

    int getSize() {
        return stackVector.size();
    }

    void reverseString(string str) {
       Stack CharStac;
       std::string reversedStr = "";

       for(char ch : str)
       {
              CharStac.push(ch);
       }

       while(!CharStac.isEmpty())
       {
        reversedStr += CharStac.peek();
        CharStac.pop();
       }

       cout << "Reversed String: " << reversedStr;

       cout << endl;
    }
};

int main()
{
    Stack stack;
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    stack.printStack();

    stack.reverseString("Hello World");

    return 0;
}
