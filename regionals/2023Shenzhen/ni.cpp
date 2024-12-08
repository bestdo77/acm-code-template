#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> nums;
stack<char> ops;
unordered_map<char, int> ump{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

void eval() {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char c = ops.top(); ops.pop();

    int d = 0;
    if ('+' == c) d = a + b;
    else if ('-' == c) d = a - b;
    else if ('*' == c) d = a * b;
    else if ('/' == c) d = a / b;
    else {
        d = 1;
        while (b --) d *= a;
    }
    nums.push(d);
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string left;
    for (int i = 0; i < n; i ++) left += '(';
    s = left + s + ')';
    n = s.size();
    for (int i = 0; i < n; i ++) {
        auto c = s[i];
        if ('(' == c) ops.push(c);
        else if (isdigit(c)) {
            int j = i, x = 0;
            while (isdigit(s[j])) x = x * 10 + (s[j ++] - '0');
            nums.push(x);
            i = j - 1;
        }
        else if (')' == c) {
            while (ops.top() != '(') eval();
            ops.pop();
        }
        else {
            if ('-' == c && s[i-1] == '(') 
                nums.push(0);
            }
            while (ops.size() && ops.top() != '(' && ump[ops.top()] >= ump[c]) eval(); 
            ops.push(c);
        }
    }
    while (ops.size()) {
        if (ops.top() == '(') ops.pop();
        else eval();
    }
    cout << nums.top() << endl;
    return 0;
}
