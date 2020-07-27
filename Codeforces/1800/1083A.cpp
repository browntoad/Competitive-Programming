#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define SZ(x) (int)(x.size())
#define ALL(x) x.begin(), x.end()
#define IOS() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const ll inf=1ll<<60;
const int iinf=2147483647;
const int mod=1e9+7;
const int maxn=3e5+5;
 
ll pow(ll x, ll p){
    ll res=1;
    while (p>0){
        if (p&1){
            res*=x;
            res%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return res;
}
ll inv(ll x){
    return pow(x, mod-2);
}
int n;
vector<pii> graph[maxn];
vector<int> val(maxn), dp(maxn), height(maxn);
void dfs(int x, int prev){
    int a=0, b=0;
    REP(i,SZ(graph[x])){
        if (graph[x][i].f==prev) continue;
        dfs(graph[x][i].f, x);
        int tmp=height[graph[x][i].f]+graph[x][i].s;
        //cout<<tmp<<endl;
        height[x]=max(height[x], tmp+val[x]);
        if (tmp>=a){
            b=a;
            a=tmp;
        }
        else if (tmp>=b){
            b=tmp;
        }
        //cout<<a<<' '<<b<<endl;
 
    }
    dp[x]=a+b+val[x];
 
 
}
 
signed main(){
    IOS();
    cin>>n;
    int mx=0;
    REP1(i,n){
        cin>>height[i];
        val[i]=height[i];
        mx=max(mx, height[i]);
    }
    REP(i,n-1){
        int a,b,w; cin>>a>>b>>w;
        graph[a].pb({b,(-1)*w});
        graph[b].pb({a,(-1)*w});
    }
    REP1(i,n){
        if (graph[i].size()>1) {
            dfs(i,-1);
            break;
        }
    }
    REP1(i,n){
        mx=max(mx, dp[i]);
        //cout<<dp[i]<<endl;
    }
    cout<<mx<<endl;
 
 
}
