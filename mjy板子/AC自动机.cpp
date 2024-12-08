#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;

int trie[maxn][26];
int fail[maxn];
int cnt[maxn];
int idx;

void insert(string& s){
    int p=0;//指针
    for(int i=0;s[i];i++){
        int j = s[i] - 'a';//映射
        if(!trie[p][j]) trie[p][j] = ++idx;
        p = trie[p][j];
    }
    cnt[p]++;
}
//建立ac自动机之前要先建字典树
void build(){
    queue <int > q;
    for(int i =0 ;i < 26;i++){
        if(trie[0][i]) q.push(trie[0][i]);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = 0;i < 26;i++){
            int v = trie[u][i];
            if(v) fail[v] = trie[fail[u]][i],q.push(v);
            else trie[u][i] = trie[fail[u]][i];
        }
    }
}

int query(string& s){//从0开始
    int ans=0;
    for(int k = 0,i = 0;s[k];k++){
        i=trie[i][s[k] - 'a'];
        for(int j = i;j && ~cnt[j];j = fail[j]){//很神奇
            ans += cnt[j];
            cnt[j] = -1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    build();
    string t;
    cin>>t;
    cout<<query(t)<<endl;
}