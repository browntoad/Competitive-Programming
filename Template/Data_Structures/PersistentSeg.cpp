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
const ll inf = (1ll<<60);
const int iinf=2147483647;
const ll mod = 998244353;
const ll maxn=2e5+5;
const double PI=acos(-1);
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return ret;
}
 
ll inv(ll a){
    return pw(a,mod-2);    
}
vector<int> vc(maxn+1);
struct Seg{
    Seg* l, *r;
    int val;
    Seg(){
        val=0;
        l=r=nullptr;
    }
};
Seg* build(int l,int r){
    Seg* ret=new Seg();
    if (l==r){
        ret->val=vc[r];
        return ret;
    }
    int mid=(l+r)/2;
    ret->l=build(l,mid); ret->r=build(mid+1, r);
    ret->val=ret->l->val+ret->r->val;
    return ret;
}
int query(Seg* rt, int qL, int qR, int nL, int nR){
    if (nL>=qL&&nR<=qR){
        return rt->val;
    }
    if (nR<qL||nL>qR){
        return 0;
    }
    int mid=(nL+nR)/2;
    return query(rt->l, qL, qR, nL, mid)+query(rt->r, qL, qR, mid+1, nR);
}
Seg* update(Seg* rt, int pos, int va, int nL, int nR){
    Seg* ret=new Seg();
    *ret=*rt;
    if (nL==nR){
        ret->val=va;
        return ret;
    }
    int mid=(nL+nR)/2;
    if (nL<=pos&&pos<=mid){
        ret->l=update(ret->l, pos, va, nL, mid);
    }
    else ret->r=update(rt->r, pos, va, mid+1, nR);
    ret->val=ret->l->val+ret->r->val;
    return ret;
}
 
signed main(){
    IOS();
    int n,q; cin>>n>>q;
    REP1(i,n) cin>>vc[i];
    vector<Seg*> segs;
    segs.pb(nullptr);
    segs.pb(build(1,n));
    
}