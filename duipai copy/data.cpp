#include <bits/stdc++.h>

using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	freopen("in.txt", "w", stdout); //生成 使两份基本代码 将要读入的数据
	int t = 5;
	cout <<t<<endl;
	while (t--){

			int n = RNG()%3+2,m = RNG()%3+2,k = RNG()%10+5;
			cout <<n<<" "<<m<<" "<<k<<endl;
			for (int i = 1;i<=n;i++){
				for (int j = 1;j<=m;j++){
					int num = RNG()%13;
					if (num == 10)cout <<'+';
					else if (num == 11)cout <<'-';
					else if (num == 12)cout <<'*';
					else cout <<num;
				}
				cout <<endl;
			}
		cout <<endl;
	}
}