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
int n,m;
vector<int> vc, posa, posb;
 
void reca(int x, int sum){
//run to n/2-1
    posa.pb(0);
    REP(i,n/2){
        int s=SZ(posa);
        REP(j,s){
            posa.pb((posa[j]+vc[i])%m);
        }
    }
 
 
}
void recb(int x, int sum){
//run to n-1
    posb.pb(0);
    FOR(i,n/2, n){
        int s=SZ(posb);
        REP(j,s){
            posb.pb((posb[j]+vc[i])%m);
        }
    }
 
}
signed main(){
    IOS();
    cin>>n>>m;
    vc.resize(n);
    REP(i,n){
        cin>>vc[i];
        vc[i]%=m;
    }
    reca(0, 0);
    sort(ALL(posa), greater<int> ());
    posa.resize(unique(ALL(posa)) - posa.begin());
    recb(n/2, 0);
    sort(ALL(posb));
    posb.resize(unique(ALL(posb))-posb.begin());
    int r=0, ans=vc[0];
    int ma=SZ(posa), mb=SZ(posb);
    REP(i,ma){
        while(r+1<mb&&(posa[i]+posb[r+1])<m){
            r++;
        }
        ans=max(ans, (posa[i]+posb[r])%m);
    }
    cout<<ans<<endl;
 
 
}
