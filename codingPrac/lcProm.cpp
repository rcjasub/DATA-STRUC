#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;   // dependency -> list of things that depend on it
    unordered_map<int, int> dayReady;        // node -> computed day (memoized)
    unordered_set<int> visited;
    unordered_set<int> currPath;

    int dfs(int node) {
        // TODO 1: if node already in dayReady, just return the cached value
        if(dayReady.find(node) != dayReady.end()) {
            return dayReady[node];
        }

        // TODO 2: cycle check — if node is in currPath, return -1 (signals impossible)
        if(currPath.find(node) != currPath.end()){
            return -1;
        }


        currPath.insert(node);
    
        int maxDependencyDay = 0;  // default if this node has NO dependencies

        for (int dep : graph[node]) {
            // TODO 3: recursively get dep's day
            int res = dfs(dep);
            // TODO 4: if that recursive call returns -1, propagate -1 immediately (cycle found)
            if(res == -1) return -1;
            // TODO 5: otherwise, update maxDependencyDay if this dep's day is bigger
            maxDependencyDay = max(maxDependencyDay, res);
        }

        int myDay = maxDependencyDay + 1;

        // TODO 6: backtrack — remove node from currPath
        currPath.erase(node);
        // TODO 7: cache myDay in dayReady before returning it
        dayReady[node] = myDay;

        return myDay;
    }

    int minDays(int n, vector<vector<int>>& trainingPairs) {
        // TODO 8: build `graph` from trainingPairs — think carefully about
        //         which direction the edge should point, given dfs(node)
        //         needs to look at node's DEPENDENCIES, not who depends on node

        for(int i = 0; i < trainingPairs.size(); i++) {
            int a = trainingPairs[i][0];
            int b = trainingPairs[i][1];

            graph[a].push_back(b);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int day = dfs(i);
            if (day == -1) return -1;   // cycle found anywhere = impossible
            result = max(result, day);  // TODO 9: why max, not sum, here too?
        }
        return result;
    }
};