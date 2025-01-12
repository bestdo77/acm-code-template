#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> nxt;
vector<int> kmp(string &a,string &b){
    int n=a.size(),m=b.size();
    vector<int> next(m,0);
    int j=0;
    for(int i=1;i<m;i++){
        while(j>0&&b[i]!=b[j]) j=next[j-1];
        if(b[i]==b[j]) j++;
        next[i]=j;
    }
    j=0;
    nxt=next;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(j>0&&b[j]!=a[i]) j=next[j-1];
        if(a[i]==b[j]) j++;
        if(j==m){
            ans.emplace_back(i-m+1);
            j=next[j-1];
            //这里return 1判断存不存在匹配串
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b;cin>>a>>b;
    vector<int> ans=kmp(a,b);
    
    for(auto it:ans){
        cout<<it+1<<endl;
    }
    for(auto it:nxt){
        cout<<it<<" ";
    }
    cout<<endl;
}