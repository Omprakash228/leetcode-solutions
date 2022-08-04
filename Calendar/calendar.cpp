#include <iostream>
#include <map>

using namespace std;

class MyCalendar {
    map<int, int> m;
    public:
        MyCalendar() {

        }

        bool book(int start, int end) {
            map<int, int>::iterator it = m.upper_bound(start);
            
            if(it == m.end() || it->second >= end)
            {
                m[end] = start;
                return true;
            }
            return false;
        }
};

int main() {
    MyCalendar* obj = new MyCalendar();

    cout << obj->book(15, 25) << endl;
    cout << obj->book(10, 20) << endl;
    cout << obj->book(20, 30) << endl;

    return 0;
}