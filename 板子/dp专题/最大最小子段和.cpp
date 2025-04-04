int qmx(int l,int r){
    int dp=0;
    int res=0;
    for(int i=l;i<=r;i++){
        dp+=a[i];
        res=max(dp,res);
        dp=max(dp,0ll);
    }
    return res;
}
int qmn(int l,int r){
    int dp=0;
    int res=0;
    for(int i=l;i<=r;i++){
        dp+=-a[i];
        res=max(dp,res);
        dp=max(dp,0ll);
    }
    return -res;
}