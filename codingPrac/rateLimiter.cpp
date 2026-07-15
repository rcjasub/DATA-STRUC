#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class RateLimiter
{
private:
    int maxRequest;
    int windowSeconds;
    unordered_map<string, queue<long>> userTimestamps;

public:
    RateLimiter(int maxRequests, int windowSeconds)
    {
        this->maxRequest = maxRequests;
        this->windowSeconds = windowSeconds;
    }

    bool allowRequest(string userId, long timestamp)
    {
        queue<long> &userQueue = userTimestamps[userId];

        while (!userQueue.empty() && userQueue.front() < timestamp - this->windowSeconds)
        {
            userQueue.pop();
        }

        if (userQueue.size() >= maxRequest)
        {
            return false;
        }

        userQueue.push(timestamp);
        return true;
    }
};

int main()
{
    RateLimiter limiter(3, 10);  // max 3 requests per 10 seconds

    cout << boolalpha;
    cout << limiter.allowRequest("alice", 1) << endl;   // true (1st)
    cout << limiter.allowRequest("alice", 2) << endl;   // true (2nd)
    cout << limiter.allowRequest("alice", 3) << endl;   // true (3rd)
    cout << limiter.allowRequest("alice", 5) << endl;   // false (4th, still within window of 1,2,3)
    cout << limiter.allowRequest("alice", 12) << endl;  // true (timestamp 1 expired: 12-10=2, 1<2 expired; now only 2,3,12 in window = 3, still allowed)
    cout << limiter.allowRequest("bob", 1) << endl;     // true (different user, own separate queue)

    return 0;
}