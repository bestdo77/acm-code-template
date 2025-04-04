- rt，要求$|a_{i+1}-a_i|\leq w $
- 再给定每个a的范围，问是否可以满足上述条件。
- 可以当成一个板子了，首先左区间和右区间等于a1.l-x，a1.r+x，然后一直往右合并取交集，如果最后区间长度大于等于一说明可以。 
```cpp
bool check(int H){
    int l=max(0ll,H-d[1]),r=min(h[1],H);
    for(int i=2;i<=n;i++){
        int mx=min(h[i],H);
        int mn=max(0ll,H-d[i]);
        l-=x;
        r+=x;
        l=max(0ll,l);
        if(l>mx||r<mn) return 0;
        l=max(l,mn);
        r=min(r,mx);
    }
    return 1;
}
```