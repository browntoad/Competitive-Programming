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
#define PI 3.14159265
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
const ll maxn=2e5+5;
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

ll inv(ll a, ll b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int tre[4*maxn];

int QU(int l, int r, int nl, int nr, int x){
    if (nl>r||nr<l){
        return 0;
    }
    if (nl>=l&&nr<=r){
        return tre[x];
    }
    int mid=(nl+nr)/2;
    return max(QU(l, r, nl, mid, x+x), QU(l, r, mid+1, nr, x+x+1));
}
void MO(int l, int r, int pos, int x, int val){
    if (l==r){
        tre[x]+=val;
        return;
    }
    int mid=(l+r)/2;
    if (l<=pos&&pos<=mid){
        MO(l, mid, pos, x+x, val);
    }
    else MO(mid+1, r, pos, x+x+1, val);
    tre[x]=max(tre[x+x], tre[x+x+1]);
}

signed main (){
    IOS();
    int n; cin>>n;
    vector<int> h(n), a(n);
    REP(i,n) cin>>h[i];
    REP(i,n) cin>>a[i];
    int ans=0;
    REP(i,n){
        int prev=QU(1, h[i], 1, n , 1); //can also do h[i]-1

        bug(prev);
        MO(1, n, h[i], 1, prev+a[i]);
    }
    cout<<QU(1, n, 1, n, 1)<<endl;
}