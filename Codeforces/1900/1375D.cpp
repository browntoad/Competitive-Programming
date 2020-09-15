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
#define pdd pair<double, double>
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
const ll maxn=1e5+5;
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
    //IOS();
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<int> vc(n);
        REP(i,n) cin>>vc[i];
        vector<int> op;
        while (1){
            int mx=0;
            map<int, bool> mp;
            REP(i,n){
                mp[vc[i]]=1;
            }
            REP(i,n){
                if (!mp[i]) break;
                mx++;
            }
            if (mx==n){
                bool done=true;
                REP(i,n){
                    if (vc[i]!=i) {
                        done=false;
                        op.pb(i+1);
                        vc[i]=n;
                        break;
                    }
                }
                if (done) {
                    break;
                }
            }
            else {
                op.pb(mx+1);
                vc[mx]=mx;
            }
            //cout<<mx<<endl;
        }
        cout<<SZ(op)<<endl;
        REP(i,SZ(op)) cout<<op[i]<<' ';
        cout<<endl;
    }
 
}