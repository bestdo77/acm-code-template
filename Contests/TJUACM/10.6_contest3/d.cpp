#include <bits/stdc++.h>
using namespace std;
int d4,d6,d8,d12,d20;
class Bigint {
	public:
		int len = 0,a[505];//len记录位数，a记录每个数位 
		Bigint(int x=0){//默认为0 
			memset(a,0,sizeof(a));
            len = 1;
			for(;x;len++)//初始化使得大整数能够表示整型 
			{
				a[len]=x%10,x/=10;
			}
			len--;
            if(x==0) len=1;
		}
		bool check0(){
            if (len>=2)return 0;
            if (a[1]==0&&a[2]==0)return 1;
            return 0;
        }
		int &operator[](int i){//在运算符重载中，使用引用可以使函数更有效率
			return a[i];
		} //在x和a之间建立联系，通过x[i]可以直接访问i的位数
		
		void flatten(int L){//从1到L范围内全部展平; 
			len=L;
			for(int i=1;i<=len;i++){
				a[i+1]+=a[i]/10,a[i]%=10;//展平，把该位数大于2的部分给到前一位 
			}
			while(!a[len]) len--;//重置长度为有效长度 
		}
		
	friend ostream& operator<<(ostream &out, const Bigint &b) {
        for (int i = max(b.len, 1); i >= 1; i--) {
            out << b.a[i];
        }
        return out; // 允许链式调用
    }
		
	Bigint& operator=(const string &b){
		len=b.length();
		for(int i=1;i<=b.length();i++){
			a[i]=b[len-i]-'0';
		}
		return *this;
	}
	
	friend istream& operator>>(istream &in, Bigint &b) {
        string tmp;
        in >> tmp;
        b = tmp; // 使用已有的字符串赋值重载
        return in;
    }
    
	bool operator>(const Bigint &b) const {
        if(len>b.len) return true; 
        if(len<b.len) return false; 
        for(int i=len;i>=1;i--) {
            if(a[i]>b.a[i]) return true;
            else if(a[i]<b.a[i]) return false;
        }
        return false;
   }
    
	bool operator<(const Bigint &b)const{
      if(len<b.len) return true; 
        if(len>b.len) return false; 
        for(int i=len;i>=1;i--) {
            if(a[i]<b.a[i]) return true;
            else if(a[i]>b.a[i]) return false;
        }
        return false;
   }
    
   bool operator==(const Bigint &b) const {
    cout <<len<<" "<<b.len<<" "<<endl;
        if(len!=b.len) return false;
        for(int i=1; i<=len;i++) {
            if (a[i]!=b.a[i]) return false;
        }
        return true;
   }
};
 
Bigint operator+(Bigint a,Bigint b){
	Bigint c;
	int len=max(a.len,b.len);
	for(int i=1;i<=len;i++){
		c[i]+=a[i]+b[i];
	}
	c.flatten(len+1);//两个数相加肯定不超过len+1位
	return c; 
}
 
Bigint operator*(Bigint a,Bigint b){
	Bigint c(0);
	int lena=a.len;
	int lenb=b.len;
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			c[i+j-1]+=a[i]*b[j];
		}
	}
	c.flatten(lena+lenb);
	return c;
}
 
Bigint operator-(Bigint a,Bigint b){//默认a大于b 
	if(a<b) cout<<"overflow"<<endl;
	int lena=a.len;
	int lenb=b.len;
	for(int i=1;i<=lenb;i++){
		a[i]-=b[i];
	}
	for(int i=1;i<=lena;i++){
		if(a[i]<0) a[i]+=10,a[i+1]--;
	}
	while(a[a.len]==0) a.len--;
	return a;	
}
 
Bigint operator/(Bigint a,Bigint b){
	Bigint tmp(0);
	if(b==tmp) cout<<"overflow"<<endl;
	int cnt=0;
	while(a>b||a==b){
		a=a-b,cnt++;
	}
	Bigint c(cnt);
	return c;
}
 
Bigint operator%(Bigint a,Bigint b){
	while(a>b||a==b){
		a=a-b;
	}
	while(a[a.len]==0) a.len--;
	return a;
}


struct no{
    Bigint p = 0;
    int num = 0;
    bool operator < (const no b) const{
        return p<b.p;
    }
} dp[55][510];
inline void print(__int128 x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
    return ;
}
int main(){
    Bigint zero;
   // cout<<zero.len<<endl;
    cin>>d4>>d6>>d8>>d12>>d20;
    for(int j = 1;j<=50;j++){
        for(int i = 1;i<=500;i++){
        dp[j][i].num = i;
        dp[j][i].p=zero;
    }
    }
    Bigint one(1); 
   // cout<<one.len<<endl;
    dp[0][0].p=one;
    int cnt = 0;
    for(int i = 1;i<=d4;i++){
        for(int j = 1;j<=4;j++){
            for(int k = 500;k>=0 && k-j>=0;k--){
                dp[i][k].p = dp[i][k].p + dp[i-1][k-j].p;
            }
        }
    }
    cnt+=d4;
    for(int i = 1;i<=d6;i++){
        for(int j = 1;j<=6;j++){
            for(int k = 500;k>=0 && k-j>=0;k--){
                dp[cnt+i][k].p=dp[cnt+i][k].p + dp[cnt + i -1][k-j].p;
            }
        }
    }
    cnt += d6;
    for(int i = 1;i<=d8;i++){
        for(int j = 1;j<=8;j++){
            for(int k = 500;k>=0 && k-j>=0;k--){
                dp[cnt+i][k].p=dp[cnt+i][k].p + dp[cnt + i -1][k-j].p;
            }
        }
    }
    cnt += d8;
    for(int i = 1;i<=d12;i++){
        for(int j = 1;j<=12;j++){
            for(int k = 500;k>=0 && k-j>=0;k--){
               dp[cnt+i][k].p=dp[cnt+i][k].p + dp[cnt + i -1][k-j].p;
            }
        }
    }
    cnt+=d12;
    for(int i = 1;i<=d20;i++){
        for(int j = 1;j<=20;j++){
            for(int k = 500;k>=0 && k-j>=0;k--){
                dp[cnt+i][k].p=dp[cnt+i][k].p + dp[cnt + i -1][k-j].p;
            }
        }
    }
    cnt+=d20;
   // int cntt=0;
    sort(dp[cnt]+1,dp[cnt]+501);
    for(int i = 500;i>=0;i--){
        if(!(dp[cnt][i].p.check0())) {cout<<dp[cnt][i].num<<" ";}
    }
  //  cout<<cntt<<endl;
    // for(int i = 500;i>=0;i--){
    //     if(!(dp[cnt][i].p==zero)) {cout <<dp[cnt][i].p;cout<<" ";}
    // }
}