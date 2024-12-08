#include <iostream>
using namespace std;
int a[110][110],n;
void logadd(int l,int r){
	for(int j=1;j<=n;j++){
		a[l][j]|=a[r][j];	
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]){
				logadd(j,i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
} 