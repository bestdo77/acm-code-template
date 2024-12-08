
#define ls k<<1
#define rs k<<1|1
/*
#define ls t[k].ls
#define rs t[k].rs
*/
const int N=10;
int a[N];
struct node{
    int /*ls,rs,*/sum,lz;
}t[N<<2];

void build(int k,int l,int r){
    if(l==r) {
        t[k].sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    t[k].sum=t[ls].sum+t[rs].sum;
}
//查询
int query(int k,int l,int r,int p,int q){
    //k在查询时直接输入1（即root）
    //l,r是整个线段树的范围
    if(l==p&&r==q) return t[k].sum;
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q);
    if(p>mid) return query(rs,mid+1,r,p,q);
    else return query(ls,l,mid,p,mid)+query(rs,mid+1,r,mid+1,q);
}
//单点修改
void modify(int k,int l,int r,int pos,int val){
    if(l==r) {t[k].sum+=val;return;}
    int mid=l+r>>1;
    if(pos<=mid) modify(ls,l,mid,pos,val);
    else modify(rs,mid+1,r,pos,val);
    t[k].sum=t[ls].sum+t[rs].sum;
}
//区间修改，懒标记，有下放的

int put_tag(int k,int l,int r,int val){
    t[k].lz=val;
    t[k].sum+=1ll*(r-l+1)*val;
}

int pushdow(int k,int l,int r){
    if(t[k].lz){//这里如果全局都变long long 不可以，要不就把val改了
        int mid=l+r>>1;
        t[ls].lz=t[k].lz;
        t[rs].lz=t[k].lz;
        t[ls].sum+=1ll*(mid-l+1)*t[k].lz;
        t[rs].sum+=1ll*(r=mid)*t[k].lz;
        t[k].lz=0;//懒标记及得归零
    }
}

int pushup(int k){
    t[k].sum=t[ls].sum+t[rs].sum;
}

void modifylz(int k,int l,int r,int p,int q,int val){
    if(p==l&&r==r) { put_tag(k,l,r,val);return;}
    pushdow(k,l,r);
    int mid=l+r>>1;
    if(q<=mid) modifylz(ls,l,mid,p,q,val);
    else if(p>mid) modifylz(rs,mid+1,r,p,q,val);
    else{
        modifylz(ls,l,mid,p,mid,val);
        modifylz(rs,mid+1,r,mid+1,q,val);
    }
    pushup(k);
}

//永久化懒标记，测试过的
typedef long long ll;

void modify(int k,int l,int r,int p,int q,ll val){
    t[k].sum+=val*(q-p+1);
    if(p==l&&q==r) {
        t[k].lz+=val;//一定是+=
        return;
    }
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,val);
    else if(p>mid) modify(rs,mid+1,r,p,q,val);
    else{
        modify(ls,l,mid,p,mid,val);
        modify(rs,mid+1,r,mid+1,q,val);
    }
}

ll query(int k,int l,int r,int p,int q,ll lz){//掉用的时候应该lz是0，懒标记是下面的节点，自身已经维护好了
    if(p==l&&q==r) return t[k].sum+lz*(q-p+1);
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q,lz+t[k].lz);//这里有变动
    else if(p>mid) return query(rs,mid+1,r,p,q,lz+t[k].lz);
    else return query(ls,l,mid,p,mid,lz+t[k].lz)+query(rs,mid+1,r,mid+1,q,lz+t[k].lz);
}

//动态开点


int cnt=1;//maybe
#define int long long
const int N=5e5+10;
int a[N];
struct node{
    int sum,lz,ls,rs;
}t[N<<2];
#define ls t[k].ls
#define rs t[k].rs
typedef long long ll;

//动态开点
void modify(int& k,int l,int r,int p,int q,ll val){
    if(!k)k=++cnt;
    t[k].sum+=val*(q-p+1);
    if(p==l&&q==r) {t[k].lz+=val;return;}
    int mid=l+r>>1;
    if(q<=mid) modify(ls,l,mid,p,q,val);//及得改一下
    else if(p>mid) modify(rs,mid+1,r,p,q,val);
    else {
        modify(ls,l,mid,p,mid,val);
        modify(rs,mid+1,r,mid+1,q,val);
    }
}

ll query(int k,int l,int r,int p,int q,ll lz){
    if(!k) return 0;
    if(p==l&&q==r) return t[k].sum+lz*(r-l+1);
    int mid=l+r>>1;
    if(q<=mid) return query(ls,l,mid,p,q,lz+t[k].lz);
    else if(p>mid) return query(rs,mid+1,r,p,q,lz+t[k].lz);
    else{
        return query(ls,l,mid,p,mid,lz+t[k].lz)+query(rs,mid+1,r,mid+1,q,lz+t[k].lz);
    }
}


