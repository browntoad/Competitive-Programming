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
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=5e3;
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
ll inv(ll x){
    return pw(x, mod-2);
}
 
signed main(){
    IOS();
    int n,k,p; cin>>n>>k>>p;
    vector<int> vc(n), b(k);
    REP(i,n) cin>>vc[i];
    REP(i,k) cin>>b[i];
    sort(ALL(vc));
    sort(ALL(b));
    int mn=inf;
    REP(i,k-n+1){
        int mx=0;
        FOR(j,i,i+n){
            mx=max(mx, abs(vc[j-i]-b[j])+abs(b[j]-p));
            //cout<<abs(vc[j-i]-b[j])+abs(vc[j-i]-p)<<' ';
        }
        //cout<<endl;
        mn=min(mx, mn);
    }
    cout<<mn<<endl;
}