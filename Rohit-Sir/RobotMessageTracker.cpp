#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class RobotMessageTracker {

public:
    unordered_map<string, int> freq;
    queue<pair<int, string>> messageTime;

    void shouldPrintMessage(int timestamp, string message) {

        

        int target = timestamp - 10;

        while (!messageTime.empty() && messageTime.front().first <= target) {

            int oldTime = messageTime.front().first;
            string oldMessage = messageTime.front().second;
            messageTime.pop();

            if(!freq.count(message)){
                freq[message] = timestamp;
            }

            else if (timestamp - freq[oldMessage] >= 10) {
                cout << oldMessage << endl;
                freq[message] = timestamp;
            }else{
                freq.erase(message);
            }

        }
        messageTime.push({timestamp, message});

    }
};

int main() {
    RobotMessageTracker tracker;

    tracker.shouldPrintMessage(1, "foo");

    tracker.shouldPrintMessage(2, "bar");


    tracker.shouldPrintMessage(4, "foo");

    tracker.shouldPrintMessage(14, "foo");

    tracker.shouldPrintMessage(23, "foo");
    tracker.shouldPrintMessage(46, "foo");

     tracker.shouldPrintMessage(56, "bar");
     tracker.shouldPrintMessage(69, "bar");
   



    return 0;
}