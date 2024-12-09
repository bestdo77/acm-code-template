#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
vector<int> e[1000],tp;
int din[1000];
int vis[1000];
int n,m;
int ans=0;
bool toposort(int r){
	queue<int> Q;
	int t[1000];
	bool flag=true;
	for(int i = 1; i <=n; i++) {
		t[i] = din[i];
		if(!din[i]) Q.push(i), vis[i] = true;
	}
	while(!Q.empty()){
		if(Q.size()>1) flag=false;//如果同时出现两个，说明这两个要么是不能确定，要么是矛盾，不更新 
		int x=Q.front();
		Q.pop();
		tp.push_back(x);
		for(int i=0;i<e[x].size();i++){
            int it=e[x][i];
			t[it]--;
			if(!t[it]&&!vis[it]) Q.push(it),vis[it]=1;;
		}	
	}
//	for(auto it:tp) cout<<char(it + 'A'-1);
	if(tp.size()<n) return false;
	if(flag && !ans) ans = r;
	return true;
}
string s[1000];
int main(){
	while(cin>>n>>m&&n+m!=0){
        bool flg=0;
        tp.clear();
        for(int i=1;i<=n;i++){
            e[i].clear();
            din[i]=0;
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            cin>>s[i];
        }
        for(int i = 1; i <= m; i++) {
            string c;
            c=s[i];
            int x = c[0] - 'A'+1, y = c[2] - 'A'+1;
            e[x].push_back(y);
            din[y]++;
            if(!toposort(i)) {
                cout<<"Inconsistency found after "<<i<<" relations."<<endl;
                // return 0;
                flg=1;
                break;
            }
            if(ans){
                cout<<"Sorted sequence determined after "<<ans<<" relations: ";
                for(int i=0;i<tp.size();i++) cout<<char(tp[i] + 'A'-1);
                cout<<"."<<endl;
                // return 0;
                flg=1;
                break;
            }
            memset(vis, 0, sizeof(vis));
            if(i!=m) tp.clear();
        }
        if(!flg){
            if(ans){
                cout<<"Sorted sequence determined after "<<ans<<" relations: ";
                for(int i=0;i<tp.size();i++) cout<<char(tp[i] + 'A'-1);
                cout<<"."<<endl;
            }else cout<<"Sorted sequence cannot be determined."<<endl;
        }
    }
	return 0;
	
}