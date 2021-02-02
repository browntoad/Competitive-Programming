#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define pdd pair<double ,double>
#define pcc pair<char, char>
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
 
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=135;
const double PI=acos(-1);
 
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
 
ll inv(ll a, ll m=mod){
    return pw(a,m-2);
}
 
vector<pii> seg(4*maxn);
vector<int> vc(maxn);
vector<int> l1(4*maxn), l2(4*maxn);
void push(int x){
    if (l2[x]){
        seg[x+x].f=seg[x].f;
        seg[x+x].s=seg[x].s;
        seg[x+x+1].f=seg[x].f;
        seg[x+x].s=seg[x].s;
        l2[x+x]=l2[x+x+1]=1;
        l2[x]=0;
    }
    if (l1[x]){
        l1[x+x]+=l1[x];
        seg[x+x].f+=l1[x];
        seg[x+x].s+=seg[x].s;
        l1[x+x+1]+=l1[x];
        seg[x+x+1].f+=l1[x];
        seg[x+x+1].s+=l1[x];
        l1[x]=0;
    }
}
void build(int l, int r, int x){
    if (l==r){
        seg[x].f=vc[l];
        seg[x].s=vc[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid, x+x);
    build(mid+1, r, x+x+1);
    seg[x].f=max(seg[x+x].f, seg[x+x+1].f);
    seg[x].s=seg[x+x].s+seg[x+x+1].s;
}
int QU(int l, int r, int nl, int nr, int x, bool tp){
    if (tp){
        if (nl>r||nr<l){
            return 0;
        }
        if (nl>=l&&nr<=r){
            return seg[x].s;
        }
        push(x);
        int mid=(nl+nr)/2;
        return max(QU(l,r,nl, mid, x+x, tp), QU(l, r, mid+1, nr, x+x+1, tp));
    }
    else {
        if (nl>r||nr<l){
            return (-1)*iinf;
        }
        if (nl>=l&&nr<=r){
            return seg[x].f;
        }
        push(x);
        int mid=(nl+nr)/2;
        return QU(l,r,nl, mid, x+x, tp)+QU(l, r, mid+1, nr, x+x+1, tp);
    }
    
}

void MO(int l, int r, int nl, int nr, int val, int x, bool tp){
    if (tp){ // change values
        if (nl==nr){
            seg[x].f+=val;
            seg[x].s+=val;
            l1[x]+=val;
            return;
        }
        int mid=(nl+nr)/2;
        push(x);
        MO(l, min(r, mid), nl, mid, val, x+x, tp);
        MO(max(l, mid+1), r, mid+1, nr, val, x+x+1, tp);
        seg[x].f=seg[x+x].f+seg[x+x+1].f;
        seg[x].s=max(seg[x+x].s, seg[x+x+1].s);
    }
    else { // assign values
        if (nl==nr){
            seg[x].f=val;
            seg[x].s=val;
            l2[x]=1;
            return;
        }
        int mid=(nl+nr)/2;
        push(x);
        push(x);
        MO(l, min(r, mid), nl, mid, val, x+x, tp);
        MO(max(l, mid+1), r, mid+1, nr, val, x+x+1, tp);
        seg[x].f=seg[x+x].f+seg[x+x+1].f;
        seg[x].s=max(seg[x+x].s, seg[x+x+1].s);
    }
    
}

signed main (){
    IOS();
    int n,q; cin>>n>>q;
    REP1(i,n) cin>>vc[i];
    build(1, n, 1);
    REP(i,q){
        int c; cin>>c;
        int l,r; cin>>l>>r;
        if (c==1){
            int x; cin>>x;
            MO(l, r, 1, n, x, 1, 1);
        }
        if (c==2){
            int x; cin>>x;
            MO(l,r, 1, n, x, 1, 0);
        }
        if (c==3){
            cout<<QU(l, r, 1, n, 1, 1)<<endl;
        }
        if (c==4){
            cout<<QU(l, r, 1, n, 1, 0)<<endl;
        }
    }
    

}