typedef long long ll;
int tre[maxn];
int lowbit(int a)
{
    return a&(-a);
}

void add (int x,int d)
{
    while(x<=maxn)
    {
        tre[x]+=d;
        x+=lowbit(x);
    }
}

ll getsum(int x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=tre[x];
        x-=lowbit(x);
    }
    return ans;
}
