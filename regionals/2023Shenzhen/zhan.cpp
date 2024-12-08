#include <bits/stdc++.h>
using namespace std;

stack<int> nums;
stack<char> ops;
string s;
unordered_map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

void cal() {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char c = ops.top(); ops.pop();
    int res;
    if (c == '+') res = a + b;
    if (c == '-') res = a - b;
    if (c == '*') res = a * b;
    if (c == '/') res = a / b;
    if (c == '^') res = pow(a, b);
    nums.push(res);
}

int main() {
    cin >> s;
    string t(s.size(), '(');
    s = t + s + ')';

    for (int i = 0; i < s.size(); ++ i) 
        if (s[i] == '(') ops.push(s[i]);
        else if (s[i] >= '0' && s[i] <= '9') {
            int j = i, t = 0;
            while (s[j] >= '0' && s[j] <= '9') {
                t = t*10 + s[j] - '0';
                j++;
            }
            i = j-1;
            nums.push(t);
        } else if (s[i] == '-' && !(s[i-1] >= '0' && s[i-1] <= '9' || s[i-1] == ')')) { //特判出是负号
            nums.push(0);
            ops.push(s[i]);
        } else if (s[i] == ')') {
            while (ops.top() != '(') cal();
            ops.pop(); 
        } else {
            while (mp[ops.top()] >= mp[s[i]]) cal();
            ops.push(s[i]);
        }
    while (ops.size()) {
        if (ops.top() == '(') ops.pop();
        else cal();
    }
    cout << nums.top();
    return 0;
}