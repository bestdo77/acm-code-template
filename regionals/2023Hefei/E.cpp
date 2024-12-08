#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=1e6+10;
map<int,int> cl;
vector<int> cx[N],cy[N];
int id;
int precx[N],precy[N];
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int col;cin>>col;
            if(cl[col]==0){
                cl[col]=++id;
            }
            cx[cl[col]].push_back(i);
            cy[cl[col]].push_back(j);
        }
    }
    int sum=0;
    for(auto c:cl){
        int col=c.second;
        sort(cx[col].begin(),cx[col].end());
        int pre=0;
        for(int i=0;i<cx[col].size();i++){
            pre+=cx[col][i];
            precx[i]=pre;
        }
        sort(cy[col].begin(),cy[col].end());
        pre=0;
        for(int i=0;i<cy[col].size();i++){
            pre+=cy[col][i];
            precy[i]=pre;
        }
        for(int i=0;i<cx[col].size();i++){
            sum+=(i+1)*cx[col][i]-precx[i];
        }
        for(int i=0;i<cy[col].size();i++){
            sum+=(i+1)*cy[col][i]-precy[i];
        }
    }
    cout<<sum*2<<endl;
}