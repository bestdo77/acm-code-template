#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
string s[N];
vector<int> G[N];
int nextcol[6][N];
int frcol[6][N];
bool eq(int i,int j){
    if(s[i][0]==s[j][0]||s[i][0]==s[j][1]||s[i][1]==s[j][0]||s[i][1]==s[j][1]) return true;
    else return false;
}
int cal1(int l,int r,int p){
    // cout<<"| "<<p<<endl;
    if(p==0) return inf;
    else if(p>=l&&p<=r) return r-l;
    else return 2*p-l-r;
}
int cal2(int l,int r,int p){
    if(p==0) return inf;
    else if(p>=l&&p<=r) return r-l;
    else return l+r-2*p;
}
void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int j=0;j<6;j++){
        for(int i=1;i<=n+1;i++){
            frcol[j][i]=nextcol[j][i]=0;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<6;j++){
            nextcol[j][i]=nextcol[j][i+1];
        }
        if(s[i]=="BG") nextcol[0][i]=i;
        if(s[i]=="BR") nextcol[1][i]=i;
        if(s[i]=="BY") nextcol[2][i]=i;
        if(s[i]=="GR") nextcol[3][i]=i;
        if(s[i]=="GY") nextcol[4][i]=i;
        if(s[i]=="RY") nextcol[5][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++){
            frcol[j][i]=frcol[j][i-1];
        }
        if(s[i]=="BG") frcol[0][i]=i;
        if(s[i]=="BR") frcol[1][i]=i;
        if(s[i]=="BY") frcol[2][i]=i;
        if(s[i]=="GR") frcol[3][i]=i;
        if(s[i]=="GY") frcol[4][i]=i;
        if(s[i]=="RY") frcol[5][i]=i;
    }
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        if(l>r) swap(l,r);
        if(eq(l,r)) cout<<r-l<<endl;
        else{
            if(s[l]=="BG"||s[l]=="RY"){//0,5
                int ans=inf;
                ans=min({cal1(l,r,nextcol[1][l]),cal1(l,r,nextcol[2][l]),cal1(l,r,nextcol[3][l]),cal1(l,r,nextcol[4][l])});
                ans=min({cal2(l,r,frcol[1][r]),cal2(l,r,frcol[2][r]),cal2(l,r,frcol[3][r]),cal2(l,r,frcol[4][r]),ans});
                if(ans==inf) cout<<-1<<endl;
                else cout<<ans<<endl;
            }
            if(s[l]=="BR"||s[l]=="GY"){//1,4
                int ans=inf;
                // cout<<11111<<endl;
                ans=min({cal1(l,r,nextcol[0][l]),cal1(l,r,nextcol[2][l]),cal1(l,r,nextcol[3][l]),cal1(l,r,nextcol[5][l])});
                // cout<<"|"<<ans<<endl;
                ans=min({cal2(l,r,frcol[0][r]),cal2(l,r,frcol[2][r]),cal2(l,r,frcol[3][r]),cal2(l,r,frcol[5][r]),ans});
                if(ans==inf) cout<<-1<<endl;
                else cout<<ans<<endl;
            }
            if(s[l]=="BY"||s[l]=="GR"){//2,3
                int ans=inf;
                ans=min({cal1(l,r,nextcol[1][l]),cal1(l,r,nextcol[0][l]),cal1(l,r,nextcol[5][l]),cal1(l,r,nextcol[4][l])});
                ans=min({cal2(l,r,frcol[1][r]),cal2(l,r,frcol[0][r]),cal2(l,r,frcol[5][r]),cal2(l,r,frcol[4][r]),ans});
                if(ans==inf) cout<<-1<<endl;
                else cout<<ans<<endl;
            }
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}