int quickpow(int a,int b,int m){
    int ans=1%m;
    while(b){
        if(b&1) {ans*=a;ans%=m;}
        a=a*a;
        a%=m;
        b>>=1;
    }
    return ans;
}
//注意longlong