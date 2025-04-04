#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> e[1000],tp;
int d[1000];
int n;
bool toposort(){
	queue<int> Q;
	for(int i=1;i<=n;i++){
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
	return tp.size()==n;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		while(cin>>x&&x){
			e[i].push_back(x);
			d[x]++;
		}
	}
	if(toposort()){
		for(auto it:tp){
			cout<<it<<" ";
		}
	}
	return 0;	
}
