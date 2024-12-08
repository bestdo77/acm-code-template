#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> e[1000],tp;
int din[1000];
int n;
bool toposort(){//满足一条边uv，在图中所有边的情况下，u均在v之前。
	queue<int> Q;//将所有入度为0的点入队，然后依次输出,如果同一时间有很多个点入队，说明无法判断结果。
	for(int i=1;i<=n;i++){
		if(!din[i]) Q.push(i);
	}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		tp.push_back(x);
		for(auto it:e[x]){
			if(--din[it]==0) Q.push(it);
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
			din[x]++;
		}
	}
	if(toposort()){
		for(auto it: tp){
			cout<<it<<" ";
		}
	}
	return 0;
	
}