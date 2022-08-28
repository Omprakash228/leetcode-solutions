#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s;
    stack<int> q;
public:
    MyQueue() : s(), q() {
    }

    void push(int x) {
        while(q.size()) {
            s.push(q.top());
            q.pop();
        }
        s.push(x);
        while(s.size()) {
            q.push(s.top());
            s.pop();
        }
    }

    int pop() {
        int val = q.top();
        q.pop();
        return val;
    }

    int peek() {
        return q.top();
    }

    bool empty() {
        return q.size() == 0;
    }
};

int main() {
    MyQueue* obj = new MyQueue();

    obj->push(1);
    obj->push(2);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;

    return 0;
}