#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
void binary_tree(string mid,string last){
    if(mid.size() > 0){
        char ch = last[last.size()-1];//后序遍历最后一个就是树根，然后把树分成了两个子树，这样再去找子树的根，递归求解。
        cout << ch;
        int cur = mid.find(ch);
        binary_tree(mid.substr(0,cur),last.substr(0,cur));
        binary_tree(mid.substr(cur+1),last.substr(cur,last.size()-cur-1));
    }
}   
int main(){
    string a,b;     
    cin >> a >> b;
    binary_tree(a,b);
    return 0;
}