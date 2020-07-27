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
const ll maxn=1e5+5;
ll pow(ll x, ll p){
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
    return pow(x, mod-2);
}
int dp[1<<22];
int n;
int val[21][21];
int d(int x){
    if (dp[x]!=iinf) return dp[x];
    for (int i=0;i<n; i++){
        if ((1<<i|x)!=x) continue; 
        for (int j=i+1;j<n;j++){
            if ((1<<j|x)!=x) continue;
            for (int k=j+1; k<n; k++){
                if ((1<<k|x)==x){
                    int nw=val[i][j]+val[j][k]+val[k][i];
                    dp[x]=min(d(x-((1<<i)+(1<<j)+(1<<k)))+nw, dp[x]);
                }
            }
        }
        break;
    }
    return dp[x];
}
signed main(){
    IOS();
    int T; cin>>T;
    while (T--){
        cin>>n;
        fill(dp, dp+(1<<22), iinf);
        dp[0]=0;
        REP(i,n) REP(j,n) cin>>val[i][j];
        cout<<d((1<<n)-1)<<endl;
    }
}

