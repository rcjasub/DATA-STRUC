//hash table have a key value pairs, 
//if more then two are store in one index , that is called a collision,
//to deal with it we can store as a link list, or find the next open slot.

//size should be a prime number, better.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node
{
   public:
   string key;
   int value;
   Node* next;

   Node(string key, int value)
   {
    this->key = key;
    this->value = value;
    next = nullptr;
   }

};


class HashTable
{
    private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

    public:

    void printTable()
    {
        for(int i = 0; i < SIZE; i++)
        {
            cout<<i<<":"<<endl;
            if(dataMap[i])
            {
                Node* temp = dataMap[i];
                while(temp)
                {
                    cout<<" {"<<temp->key<<", "<<temp->value<<"}"<<endl;
                    temp = temp->next;
                }
            }
        }
    }


    int hash(string key)
    {
        int hash = 0;
        for(int i = 0; i < key.length(); i++)
        {
           int asciiVal = int(key[i]);
           hash = (hash + asciiVal * 23) % SIZE;     
        }
        return hash;
    }

    void set(string key, int value)
    {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if(dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else{
            Node* temp = dataMap[index];
            while(temp->next)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    int get(string key)
    {
        int index = hash(key);
        Node* temp = dataMap[index];
        while(temp)
        {
            if(temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }

    vector<string> keys()
    {
        vector<string> allKeys;
        for(int i = 0; i < SIZE; i++)
        {
            Node* temp = dataMap[i];
            while(temp)
            {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
       return allKeys;
    }
};

int main()
{
    HashTable* myHashTable = new HashTable();
    myHashTable->set("nails", 2);
    myHashTable->set("screws", 3);
    myHashTable->set("bolts", 4);
    myHashTable->set("nuts", 5);
    myHashTable->set("washers", 6);

   vector<string> keys = myHashTable->keys();
   for(int i = 0; i < keys.size(); i++)
   {
       cout<<keys[i]<<endl;
   }

   
    return 0;
}