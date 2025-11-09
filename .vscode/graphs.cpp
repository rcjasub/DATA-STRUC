#include <unordered_map>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList; // Adjacency list representation of the graph

public:

    void printGraph()
    {
        for (auto [vertex, edges] : adjList)
        {
            cout << vertex << ": [ ";
            for (auto edge : edges)
            {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }

    bool addVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)  // <-- fixed typo from adjlist to adjList
        {
            adjList[vertex]; // This initializes an empty set for the new vertex
            return true; // Vertex added successfully
        }

        return false; // Vertex already exists
    }

    bool addEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
         adjList.at(vertex1).insert(vertex2); // Add vertex2 to the adjacency list of vertex1
         adjList.at(vertex2).insert(vertex1); // Add vertex1 to the adjacency list of vertex2 (for undirected graph)

         return true; // Edge added successfully
        }
        
        return false; // One or both vertices do not exist
    }


    bool removeEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2); // Remove vertex2 from the adjacency list of vertex1
            adjList.at(vertex2).erase(vertex1); // Remove vertex1 from the adjacency list of vertex2 (for undirected graph)

            return true; // Edge removed successfully
        }

        return false; // One or both vertices do not exist
    }


    bool removeVertex(string vertex)
    {
        if(adjList.count(vertex) == 0) return false;
        for(auto otherVertex : adjList.at(vertex))
        {
          adjList.at(otherVertex).erase(vertex); // Remove vertex from the adjacency list of its neighbors  
        }
        
         adjList.erase(vertex); // Remove the vertex from the graph
         return true; // Vertex removed successfully  
    }

    
      
};

int main()
{
    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");

    myGraph->addEdge("A", "B"); // Add an edge between A and B

    myGraph->printGraph(); // Print the graph before adding edges
}
