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
const ll mod = 1e10;
const ll maxn=1005;
const double pi=acos(-1);
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
int n,m;
char arr[maxn][maxn];
struct Seg1d{
    Seg1d *l, *r;
    int val;
    Seg1d(){
        val=0; l=r=nullptr;
    }
};
struct Seg2d{
    Seg2d *l; Seg2d *r;
    Seg1d *val;
};
 
Seg1d* build1d(int l,int r){
    Seg1d* ret=new Seg1d();
    if (l==r){
        return ret;
    }
    int mid=(l+r)/2;
    ret->l=build1d(l,mid); ret->r=build1d(mid+1, r);
    return ret;
}
Seg2d* build2d(int l, int r){
    Seg2d* ret=new Seg2d();
    ret->val=build1d(0,n-1); // n is # of rows
    if (l==r){
        return ret;
    }
    int mid=(l+r)/2;
    ret->l=build2d(l,mid); ret->r=build2d(mid+1, r);
    return ret;
}
int query1d(Seg1d *rt, int qL, int qR, int nL, int nR){
    if (nL>=qL&&nR<=qR){
        return rt->val;
    }
    if (nR<qL||nL>qR){
        return 0;
    }
    int mid=(nL+nR)/2;
    return query1d(rt->l, qL, qR, nL, mid)+query1d(rt->r, qL, qR, mid+1, nR);
}
int query2d(Seg2d *rt, int qL,  int qR, int nL, int nR, int qU, int qD){
    if (nL>=qL&&nR<=qR){
        return query1d(rt->val, qU, qD, 0,n-1);
    }
    if (nR<qL||nL>qR){
        return 0;
    }
    int mid=(nL+nR)/2;
    return query2d(rt->l, qL,  qR, nL, mid, qU, qD)+query2d(rt->r, qL,  qR, mid+1, nR, qU, qD);
}
void update1d(Seg1d* rt, int pos, int delta, int nL, int nR){
    rt->val += delta;
    
    if (nL == nR) return;
    
    int mid=(nL+nR)/2;
    if (nL<=pos&&pos<=mid){
        update1d(rt->l, pos, delta, nL, mid);
    }
    else update1d(rt->r, pos, delta, mid+1, nR);
}
void update2d(Seg2d* rt, int posx, int posy, int delta, int nL, int nR){
    update1d(rt->val, posy, delta, 0,n-1);
    if (nL==nR){
        return;
    }
    int mid=(nL+nR)/2;
    if (nL<=posx&&posx<=mid){
        update2d(rt->l, posx, posy, delta, nL, mid);
    }
    else update2d(rt->r, posx, posy, delta, mid+1, nR);
}
signed main(){
    IOS();
    
 
}