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
const ll mod = 998244353;
const ll maxn=1e3+5;
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
    int n; cin>>n;
    vector<int> ans(n);
    REP1(i,n){
        ans[i-1]=0;
        int k=n-i+1;
        int a=pw(10,k-1), b=pw(10, k-2);
        if (k==1){
            ans[i-1]=10;
            continue;
        }
        int tmpa=a*18;
        tmpa%=mod;
        ans[i-1]+=tmpa;
 
        k-=2;
        int tmp=b*81;
        tmp%=mod;
        tmp*=k;
        tmp%=mod;
        ans[i-1]+=tmp;
        ans[i-1]%=mod;
    }
    REP(i,n) cout<<ans[i]<<' ';
    cout<<endl;
    
}
 
