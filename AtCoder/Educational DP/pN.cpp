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
#define endl '\n'
#define PI 3.14159265
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
const ll inf = 1ll<<60;
const int iinf=1ll<<60;
const ll mod = 1e9+7;
const ll maxn=5e3+5;
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
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
 
int dp[405][405];
signed main (){
    IOS();
    int n; cin>>n;
    vector<int> vc(n+1);
    REP1(i,n) cin>>vc[i];
    vector<int> pf(n+1);
    pf[1]=vc[1];
    REP1(i,n-1){
        pf[i+1]=pf[i]+vc[i+1];
    }
    /*REP1(i,n) cout<<pf[i]<<' ';
 
    cout<<endl;
    */
    REP(i,n+1) REP(j,n+1) dp[i][j]=iinf;
    for (int i=n;i>=1;i--) {
        FOR(j,i,n+1){
            if (i==j){
                dp[i][j]=0;
                continue;
            }
            FOR(k,i,j){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+pf[j]-pf[i-1]);
            }
            bug(i);
            bug(j);
            bug(dp[i][j]);
        }
    }
 
    cout<<dp[1][n]<<endl;
}