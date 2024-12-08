#include <bits/stdc++.h>

#define int long long
#define pii pair<int,int>
using namespace std;
typedef long long ll;

const int maxn=4e7+10;

int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
} 
int trie[maxn][26];
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

int query (string & s){
    int p = 0;
    for(int i=0;s[i];i++){
        int j = s[i] - 'a';
        if(!trie[p][j]) return 0;
        p=trie[p][j];
    }
    return cnt[p];
}

signed main(){
    
}