#include <bits/stdc++.h>
const int maxn=5e6+10;
int next[maxn];

int main(){
    std::string s,t;
    std::cin>>s>>t;
    s= " " + s;
    t = " " + t;
    next[1] = 0;
    for(int i = 2 ,j = 0;i < t.size() ;i++){
        while(j && t[i] != t[j+1]) j=next[j];
        if(t[i] == t[j + 1]) j++;
        next[i]=j;
    }

    for(int i = 1,j = 0;i < s.size();i++){
        while(j && (j == t.size()-1 || s[i] != t[j+1])) j = next[j];
        if(s[i] == t[j + 1]) j++;
        if(j == t.size() - 1) printf("%d\n",i - t.size() + 2);
    }

    for(int i = 1;i <= t.size() - 1;i++){
        if(i != 1) std::cout<< " ";
        std::cout<<next[i];
    }
    std::cout<<std::endl;
}