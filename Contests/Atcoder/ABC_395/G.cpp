#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;


void Atomatic_AC_machine() {
    int N, Q;
    cin >> N >> Q;

    vector<int> nest(N + 1);
    vector<int> id(N + 1); // id[i] 表示第 i 个巢中所有鸽子的编号
    for (int i = 1; i <= N; ++i) {
        nest[i] = i;
        id[i] = i; 
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            
            int a, b;
            cin >> a >> b;
            int current_nest = nest[a]; // 当前鸽子 a 所在的巢
            id[current_nest] = 0; // 当前巢中不再有鸽子
            nest[a] = b; // 更新鸽子 a 的位置
            id[b] = a; // 更新巢 b 中的鸽子
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            swap(id[a], id[b]); // 交换两个巢中的鸽子编号
            if (id[a] != 0) {
                nest[id[a]] = a; // 更新鸽子的位置
            }
            if (id[b] != 0) {
                nest[id[b]] = b; // 更新鸽子的位置
            }
        } else if (op == 3) {

            int a;
            cin >> a;
            cout << nest[a] << endl; 
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}