#include <iostream>
#include <unordered_map>

using namespace std;

class Logger {
public:
    unordered_map<string, int> q;
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(!q.count(message) || timestamp - q[message] >= 10) {
            q[message] = timestamp;
            return true;
        }
        return false;
    }
};

int main() {
    Logger l;
    cout << l.shouldPrintMessage(1, "foo") << endl;
    cout << l.shouldPrintMessage(2, "bar") << endl;
    cout << l.shouldPrintMessage(3, "foo") << endl;
    cout << l.shouldPrintMessage(8, "bar") << endl;
    cout << l.shouldPrintMessage(10, "foo") << endl;
    cout << l.shouldPrintMessage(11, "foo") << endl;
    return 0;
}