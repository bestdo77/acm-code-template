- 题意是，给定几个鸟巢，和几个鸟，有时候换鸟巢位置，有时候换鸟的位置，在线问鸟在哪个巢
- 很抽象的题，首先换鸟巢这事肯定不能真去换鸟，只能换巢的位置。
- 设置一个rv表示鸟巢编号为i的现在在rv[i],vr表示i位置的鸟巢编号是vr[i]
- 肯定是要记录每个鸟的位置，无法直接记录鸟在哪个巢，但是可以记录鸟在哪个位置。
- 把鸟放到x巢，就是把鸟放在x位置
- 交换两个巢，就直接交换鸟巢位置和位置的鸟巢编号即可。
- 这样修改，相当于换巢，让鸟的实际位置没动，其实是巢在动，然后访问这个位置的巢是谁即可。
```cpp
int pos[N];
int vr[N],rv[N];
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        pos[i]=i;
        vr[i]=rv[i]=i;
    }
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int a,b;cin>>a>>b;
            pos[a]=rv[b];
        }else if(op==2){
            int a,b;cin>>a>>b;
            swap(vr[rv[a]],vr[rv[b]]);
            swap(rv[a],rv[b]);
        }else{
            int a;cin>>a;
            cout<<vr[pos[a]]<<endl;
        }
    }
}   
```