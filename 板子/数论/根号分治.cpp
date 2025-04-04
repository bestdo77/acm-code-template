    int lim=min((int)sqrt(n)+10,k);
    for(int i=2;i<=lim;i++){
        /*计算sqrt(n)以内的*/    
    }
    for(int l=lim+1,r;l<=k;l=r+1){
        int x=n/l;
        r=min(k,n/x);
        /*计算n/i结果一样的所有*/
        ans=ans+(pre[r]-pre[l-1]);
    }