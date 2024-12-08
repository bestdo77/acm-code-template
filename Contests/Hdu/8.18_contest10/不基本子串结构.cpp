#include <iostream>
#include <cstring>
using namespace std;
#define ull unsigned long long 
const int N=1e6+10;
const ull p=89;
ull mip[N];
ull pre[N],suf[N];
char a[1000010]; // 文本串
char b[1000010]; // 模板串(将被匹配的子串)
char c[1000010];
char d[1000010];
char emp[1000010];
int kmp_next[1000010]; // next数组
int ans[1000010],p1=0;
void getNext(int m){//后缀和前缀匹配
	int j = 0;
	// 初始化next[0]的值
	kmp_next[0] = 0;
	for(int i=1; i<m; ++i){
		// 当这一位不匹配时，将j指向此位之前最大公共前后缀的位置
		while(j>0 && b[i]!=b[j]) j=kmp_next[j-1];
		// 如果这一位匹配，那么将j+1，继续判断下一位
		if(b[i]==b[j]) ++j;
		// 更新next[i]的值
		kmp_next[i] = j;
	}
}//后缀数组一直是

void kmp(int n,int m){
    p1=0;
	int i, j = 0;
	// 初始化位置p = -1
	int p = -1;
	// 初始化next数组
	getNext(m);
	for(i=0; i<n; ++i){
		// 当这一位不匹配时，将j指向此位之前最大公共前后缀的位置
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		// 如果这一位匹配，那么将j+1，继续判断下一位
		if(b[j]==a[i]) ++j;
		// 如果是子串(m位完全匹配)，则更新位置p的值，并中断程序
		if(j==m){
		 	ans[++p1]=i-m+1;
			//这里直接return 1,可以判断存不存在匹配串
		 	j=kmp_next[j-1];
		}
	}
	// 返回位置p的值
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    mip[0]=1;
    for(int i=1;i<=1e6;i++){
        mip[i]=mip[i-1]*p;
    }
    while(t--){
        cin>>c>>d;
        int n=strlen(c);
        int m=strlen(d);
        if(n<=m){
            for (int i=0;i<n;i++)b[i]=c[i];
            for (int i=0;i<m;i++)a[i]=d[i];
            swap(n,m);
        }
        else{
            for (int i=0;i<n;i++)a[i]=c[i];
            for (int i=0;i<m;i++)b[i]=d[i];

        }
        // cout <<n<<m<<endl;
        // cout <<a<<" "<<b<<endl;
        kmp(n,m);
        if(p1==1){
            cout<<n<<endl;
        }else if(p1>=2){
            cout<<-1<<endl;
        }else{
            //a的前缀，b的后缀
            ull ansa=0,ansb=0;
            int len=0;
            for(int i=0;i<min(n,m);i++){
                ansa=ansa*p+(a[i]-'a');
                ansb+=mip[i]*(b[m-i-1]-'a');
                // cout<<ansa<<" "<<ansb<<endl;
                if(ansa==ansb) len=max(len,i+1);
            }
            ansa=0,ansb=0;
            for(int i=0;i<min(n,m);i++){
                ansa+=mip[i]*(a[n-i-1]-'a');
                ansb=ansb*p+(b[i]-'a');
                // cout<<ansa<<" "<<ansb<<endl;
                if(ansa==ansb) len=max(len,i+1);
            }
            // cout<<len<<endl;
            cout<<n+m-len<<endl;
        }
        for(int i=0;a[i];i++){
            a[i]='\0';
        }
        for(int i=0;b[i];i++){
            b[i]='\0';
        }
        for(int i=0;i<m;i++){
            kmp_next[i]=0;
        }
    }	
	return 0;
} 