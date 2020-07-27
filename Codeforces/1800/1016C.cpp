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
    vector<int> a(n), b(n);
    REP(i,n){
        cin>>a[i];
    }
    REP(i,n) cin>>b[i];
    vector<int> sf(n+1), uR(n+1), dR(n+1);
    RREP(i,n){
        sf[i]=sf[i+1]+a[i]+b[i];
    }
    int cnt=1;
    RREP(i,n){
        dR[i]=dR[i+1]+sf[i+1]+cnt*a[i];
        uR[i]=uR[i+1]+sf[i+1]+cnt*b[i];
        //cout<<uR[i]<<' ';
        cnt+=2;
    }
    //cout<<endl;
    int sum=0, ans=0;
    REP(i,n){
        if (i==0){
            ans=max(ans, uR[i]);
            continue;
        }
        if (i%2){
            sum+=a[i-1]*((i-1)*2)+b[i-1]*((i-1)*2+1);            
            ans=max(ans,sum+dR[i]+(i*2)*sf[i]);
        }
        else {
            sum+=b[i-1]*((i-1)*2)+a[i-1]*((i-1)*2+1);            
            ans=max(ans, sum+uR[i]+(i*2)*sf[i]);
        }
 
    }
    cout<<ans<<endl;
 
 
}
