#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=6;
const int mod=1e9+7;
int a[N];

struct tea{
    string name;
    int t,p;
    bool operator < (tea& a) const{
        if(p>a.p) return 1;
        else if(p==a.p&&t<a.t){
            return 1;
        }
        else return 0;
    }
}team1[N],team2[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    map<string ,int > mp;
    int cnt1=0;
    for(int i=1;i<=n;i++){
        //getchar();
        string t;
        int time,p;
        cin>>t;
        cin>>p>>time;
            team1[++cnt1].name=t;
            team1[cnt1].p=p;
            team1[cnt1].t=time;
            mp[t]++;
        
    }
    int cnt2=0;
    cin>>m;
    for(int i=1;i<=m;i++){
        //getchar();
         string t;
        int time,p;
        cin>>t;
        cin>>p>>time;
        team2[++cnt2].name=t;
        team2[cnt2].p=p;
        team2[cnt2].t=time;
        mp[t]+=2;
    }
    sort(team1+1,team1+cnt1+1);
    sort(team2+1,team2+cnt2+1);
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        if(team1[i].name=="lzr010506") {
            ans1++;break;
        }
        if(mp[team1[i].name]==3) continue;
        else ans1++;
    }
    for(int i=1;i<=m;i++){
        if(team2[i].name=="lzr010506") {
            ans2++;break;
        }
        if(mp[team2[i].name]==3) continue;
        else ans2++;
    }
    cout<<min(ans1,ans2)<<endl;
    return 0;

}