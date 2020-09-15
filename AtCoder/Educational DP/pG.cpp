#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast", "unroll-loops")
using namespace std;
#define ll long long
//#define int ll
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
bool cmp(pii x, pii y) {
    return x.s<y.s;
}
signed main(){
    IOS();
    int n,m; cin>>n>>m;
    vector<int> graph[n+1], in(n+1), pointing[n+1];
    REP(i,m){
        int x,y; cin>>x>>y;
        graph[x].pb(y);
        pointing[y].pb(x);
        in[y]++;
    }
    vector<int> res;
    queue<int> qu;
    REP1(i,n){
        //cout<<in[i]<<' ';
        if (in[i]==0) qu.push(i);
    }
    //cout<<endl;
    while(qu.size()){
        int j=qu.front();
        res.pb(j);
        REP(i,graph[j].size()){
            in[graph[j][i]]--;
            if (in[graph[j][i]]==0){
                qu.push(graph[j][i]);
            }
        }
        qu.pop();
    }
    vector<int> dp(n+1);
    int ans=0;
    //cout<<res.size()<<endl;
    REP(i,n){
    	bug(i);
        int k=res[i];
        REP(j,pointing[k].size()){
        	//cout<<pointing[k][j]<<' ';
            dp[k]=max(dp[k], dp[pointing[k][j]]+1);
        }
        ans=max(ans, dp[k]);
        //cout<<endl;
        //cout<<ans<<endl;
    }
 
    cout<<ans<<endl;
 
 
}