#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[26],cur[26];
int check(){
	int n=s.length(),i;
	for(i=0;i<26;i++)
	{
		cnt[i]=0;
		cur[i]=0;
	}
	for(i=0;i<n;i++) cnt[s[i]-'a']++;
    // cout<<s<<endl;
	for(i=0;i<n;i++)
	{
		cur[s[i]-'a']++;
		if(cur[s[i]-'a']*2>cnt[s[i]-'a']) return n-i;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,p,ans;
	for(cin>>T;T>0;T--){
		cin>>s;
		n=s.length();
        int l=0,r=n-1;
        while(l<=r){
            if(s[l]==s[r]) l++,r--;
            else break;
        }
        if(l>r){
            cout<<0<<endl;
            continue;
        }
		s=s.substr(l,r-l+1);
        ans=s.size();
		ans=min(ans,check());
        reverse(s.begin(),s.end());
        ans=min(ans,check());
		cout<<ans<<'\n';
	}
	return 0;
}