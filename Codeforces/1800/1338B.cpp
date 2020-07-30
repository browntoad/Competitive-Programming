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
#define pcc pair<char, char> 
#define endl '\n'
#define PI 3.14159265
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=1e5+5;
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
vector<int> graph[maxn];
int par=3;
bool ooof=false;
int ans=0;
void dfs(int x, int prev, int curdis){
    if (SZ(graph[x])==1){
        if (par==3) par=curdis%2;
        if (curdis%2!=par){
            ooof=true;
        }
        return;
    }
    REP(i,SZ(graph[x])){
        if (graph[x][i]!=prev) {
            dfs(graph[x][i], x, curdis+1);
        }
    }

}
void dfs2(int x, int prev){
    if (SZ(graph[x])==1) return;
    int cnt=0;
    REP(i,SZ(graph[x])){
        if (graph[x][i]==prev) continue;
        if (SZ(graph[graph[x][i]])==1) cnt++;
        if (cnt<2||SZ(graph[graph[x][i]])!=1) ans++;
        dfs2(graph[x][i], x);
    }
    //cout<<cnt<<endl;
}
signed main (){
    IOS();
    int n; cin>>n;
    REP(i,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);

    }
    REP1(i,n){
        if (SZ(graph[i])>1){
            dfs(i,-1, 0);
            dfs2(i, -1);
            if (ooof){
                cout<<3<<' ';
            }
            else cout<<1<<' ';
            cout<<ans<<endl;
            break;
        }
    }

}