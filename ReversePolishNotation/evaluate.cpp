#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public: 
    static int eval(vector<string>& tokens) {
        stack<int> s;
        unordered_set<string> operators{"+", "-", "*", "/"};

        for(string t : tokens) {
            if(operators.count(t) == 1) {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                s.push(applyOperation(t, o1, o2));
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }

    static int applyOperation(string op, int operand1, int operand2) {
        if(op == "+") {
            return add(operand1, operand2);
        } else if (op == "-") {
            return subtract(operand1, operand2);
        } else if (op == "*") {
            return multiply(operand1, operand2);
        } else {
            return divide(operand1, operand2);
        }
    }

    static int add(int op1, int op2) {
        return op1 + op2;
    }

    static int subtract(int op1, int op2) {
        return op1 - op2;
    }

    static int multiply(int op1, int op2) {
        return op1 * op2;
    }

    static int divide(int op1, int op2) {
        return op1 / op2;
    }
};

int main() {
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << Solution::eval(tokens) << endl;
    return 0;
}