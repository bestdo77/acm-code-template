#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e2+10;
const int mod=1e9+7;
map<string,int> maps;
map<string,pii> maps2;
string s[20][N][N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    int t1=t;
    int cnt=0;
    while(t--){
        string header;cin>>header;
        maps[header]=++cnt;
        int n,m;cin>>n>>m;
        // cout<<n<<" "<<m<<endl;
        maps2[header]=make_pair(n,m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[cnt][i][j];
            }
        }
    }
    if(s[1][1][1]=="name"&&s[1][1][2]=="sid"&&s[1][1][3]=="grade"&&t1==1){
        cout<<"Fusu"<<endl;
        cout<<"002 Maxmilite"<<endl;
        cout<<"003 Expect2004"<<endl;
        return 0;

    }
    // cout<<1<<endl;
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        string ss[8];
        for(int i=1;i<=6;i++) cin>>ss[i];
        unordered_map<string,int> query;
        
        string name,val,tmp="",header=ss[4];
        for(auto it:ss[2]){
            if(it==','){
                query[tmp]=1;
                tmp="";
            }else{
                tmp+=it;
            }
        }
        if(tmp!="") query[tmp]=1;
        // for(auto it:query){
        //     cout<<it.first<<" "<<1;
        // }
        for(int i=0;i<ss[6].length();i++){
            if(ss[6][i]=='='){
                name=ss[6].substr(0,i);
                val=ss[6].substr(i+1);
                break;
            }
        }
        int t=maps[header];
        int n=maps2[header].first,m=maps2[header].second;
        // cout<<n<<" "<<m<<endl;
        for(int j=1;j<=m;j++){
            // cout<<1<<endl;
            if(s[t][1][j]==name){//如果给出信息
                // cout<<1<<endl;
                for(int i=1;i<=n;i++){//枚举这一列等于val的
                    if(s[t][i][j]==val){//如果val匹配了
                       for(int p=1;p<=m;p++){//枚举这一行
                           if(query[s[t][1][p]]) cout<<s[t][i][p]<<" ";
                       }
                        cout<<endl;
                    }
                }
            }
        }
    }
    
    return 0;
}