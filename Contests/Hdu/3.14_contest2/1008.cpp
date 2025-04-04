#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
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
vector<int> e[N],tp;
int d[N];
int n;
bool toposort(){
	tp.clear();
    queue<int> Q;
	for(int i=1;i<=3*n;i++){
		if(!d[i]) Q.push(i);
	}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		tp.push_back(x);
		for(auto it:e[x]){
			if(--d[it]==0) Q.push(it);
		}	
	}
	return tp.size()==3*n;
}
void Atomatic_AC_machine(){
    int m;cin>>n>>m;
    for(int i=1;i<=3*n;i++){
        e[i].clear();
        d[i]=0;
    }
    bool flag=0;
    for(int i=1;i<=m;i++){
        int x,y,c;cin>>x>>y>>c;
        int t1=2*n-x+1;
        int t2=2*n+x-y/2;
        int t3=y/2+y%2;
        // cout<<t1<<" "<<t2<<" "<<t3<<endl;
        if(c==t1){
            e[t2].push_back(t1);
            e[t3].push_back(t1);
            d[t1]+=2;
        }else if(c==t2){
            // db(i<<" "<<2)
            // cendl
            e[t1].push_back(t2);
            e[t3].push_back(t2);
            d[t2]+=2;
        }else if(c==t3){
            // db(i<<" "<<3)
            // cendl
            e[t1].push_back(t3);
            e[t2].push_back(t3);
            d[t3]+=2;
        }else{
            // cout<<"No"<<endl;
            flag=1;
        }#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
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

void Atomatic_AC_machine(){
    
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}
    }
    if(flag){
        cout<<"No"<<endl;
        return;
    }
    if(toposort()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}