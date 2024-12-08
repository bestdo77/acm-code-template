#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn = 1e5+10;
int a[maxn];
map <pair<char,char>,char> mp;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mp[{'N','W'}]='L';
    mp[{'N','E'}]='R';
    mp[{'S','W'}]='R';
    mp[{'S','E'}]='L';
    mp[{'W','S'}]='L';
    mp[{'W','N'}]='R';
    mp[{'E','S'}]='R';
    mp[{'E','N'}]='L';
    int t;
    cin>>t;
    vector <pair <char,int>> ans;
    while(t--){
        int n;cin>>n;char now;char start;ans.clear();
        for (int i=1;i<=n;i++){
            char c;
            cin >>c;
            int num;
            cin >>num;
            if (i!=1){
                ans.push_back({mp[{now,c}],0});
            }else {
                start=c;
            }
            now=c;
            ans.push_back({'Z',num});
        }
        cout <<ans.size()<<" "<<start<<endl;
        for (int i=0;i<ans.size();i++){
            cout <<ans[i].first<<" ";
            if (ans[i].first=='Z')cout <<ans[i].second;
            cout <<endl;
        }
    }

    
}