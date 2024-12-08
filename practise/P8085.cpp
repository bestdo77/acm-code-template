#include <bits/stdc++.h>
using namespace std;
#define int long long

bool type[2005];
int num[2005];
int opr[2005]; // +~1, -~2, *~10000, /~10001, ^~20000, (inv)~31, (~114514, )~1919810

// 获取主导运算符的索引
int domopr(int l, int r) {
    int dom = 5, domp = -1;
    int num = 0;
    
    for (int i = l; i <= r; i++) {
        if (opr[i] == 114514) num++;
        if (opr[i] == 1919810) num--;
        
        if (num) continue;
        
        if (type[i] == 0 && opr[i] / 10000 <= 2) {
            if (opr[i] / 10000 <= dom) {
                dom = opr[i] / 10000;
                domp = i;
            }
        } else if (type[i] == 0) {
            if (opr[i] / 10000 < dom) {
                dom = opr[i] / 10000;
                domp = i;
            }
        }
    }
    
    return domp;
}

// 计算表达式的值
int expr(int l, int r) {
    if (l > r) return 0;
    if (l == r) return num[l];
    
    int p = domopr(l, r);
    
    if (p == -1 && opr[l] == 114514 && opr[r] == 1919810) return expr(l + 1, r - 1);
    
    int num2 = expr(p + 1, r);
    if (opr[p] == 30000) return -1 * num2;
    
    int num1 = expr(l, p - 1);
    
    switch (opr[p]) {
        case 1:
            return num1 + num2;
        case 2:
            return num1 - num2;
        case 10000:
            return num1 * num2;
        case 10001:
            return num1 / num2;
        case 20000:
            return pow(num1, num2);
        default:
            return 0; // 防止未处理的情况
    }
}

signed main() {
    string s;
    cin >> s;
    
    vector<int> v;
    stack<int> st;
    
    // 处理括号
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == i - 1) {
                v.push_back(i);
                v.push_back(i - 1);
                st.pop();
            }
            if (!st.empty()) st.pop();
            else v.push_back(i);
        }
    }
    
    // 添加剩余的左括号位置
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    
    // 删除括号
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--) {
        s.erase(v[i], 1);
    }
    
    int cnt = 0;
    
    // 解析表达式
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            type[++cnt] = 1;
            while (s[i] >= '0' && s[i] <= '9') {
                num[cnt] *= 10;
                num[cnt] += s[i] - '0';
                i++;
            }
            i--;
        } else {
            type[++cnt] = 0;
            switch (s[i]) {
                case '+':
                    opr[cnt] = 1;
                    break;
                case '-':
                    opr[cnt] = 2;
                    break;
                case '*':
                    opr[cnt] = 10000;
                    break;
                case '/':
                    opr[cnt] = 10001;
                    break;
                case '^':
                    opr[cnt] = 20000;
                    break;
                case '(':
                    opr[cnt] = 114514;
                    break;
                case ')':
                    opr[cnt] = 1919810;
                    break;
            }
        }
    }
    
    // 处理负数
    for (int i = 1; i <= cnt; i++) {
        if (opr[i] == 2 && type[i - 1] == 0 && opr[i - 1] != 1919810) opr[i] = 30000;
    }
    
    cout << expr(1, cnt);
    return 0;
}