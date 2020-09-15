#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long 
#define int ll
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pb push_back
#define f first
#define s second
#define pii pair<int, int>
//#define TOAD
#ifdef TOAD
#define IOS() 
#define bug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" is "<<x<<endl
#else 
#define IOS() ios::sync_with_stdio(false), cin.tie(0);
#define bug(x)
#endif
 
const ll inf=(1ll<<60);
const double PI=acos(-1);
const int maxn=1e4+5;
const int iinf=2147483647;
const ll mod=1e9+7;
 
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while(p>0){
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
 
signed main(){
    IOS();
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> vc(n);
        map<int, int> mp;
        REP(i,n) {
            cin>>vc[i];
            mp[vc[i]]++;
        }
        map<int, int> cur;
        int ans=0;
        REP(i,n){
            map<int, int> c;
            
            cur[vc[i]]++;
            FOR(j,i+1,n){
                c[vc[j]]++;
                ans+=(cur[vc[j]]-(vc[j]==vc[i]))*(mp[vc[i]]-(cur[vc[i]]+c[vc[i]]));
                //cout<<j<<' '<<i<<' '<<ans<<endl;
            }
        }
 
        cout<<ans<<endl;
 
    }
 
}