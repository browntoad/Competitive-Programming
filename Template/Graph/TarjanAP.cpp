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
const ll PI=acos(-1);
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
vector<int> D(maxn), L(maxn), graph[maxn], ans;
vector<bool> occ(maxn);
void dfs(int x, int prev, int cnt){
    D[x]=cnt;
    L[x]=D[x];
    occ[x]=1;
    REP(i,SZ(graph[x])){
        if (graph[x][i]!=prev){
            if (occ[graph[x][i]]){
                L[x]=min(L[x], D[graph[x][i]]);
            } 
            else {
                dfs(graph[x][i], x, cnt+1);
                L[x]=min(L[x], L[graph[x][i]]);
            }
            
        }
    }
    //cout<<L[x]<<endl;

}
void ap(int x, int prev){
    occ[x]=1;
    int nums=0, bg=0;
    REP(i,SZ(graph[x])){
        if (graph[x][i]==prev) {
            nums++;
            continue;
        }
        if (occ[graph[x][i]]) continue;
        nums++;
        bg=max(bg, L[graph[x][i]]);
        ap(graph[x][i], x);
        
    }

    //cout<<x<<' '<<nums<<endl;
    if (bg>=D[x]&&nums>=2){
        ans.pb(x);

    }




}
signed main(){
    //IOS();
    int T; cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        REP(i,n+1){
            graph[i].clear();
            D[i]=0;
            L[i]=iinf;
            occ[i]=0;
        }
        ans.clear();
        REP(i,m){
            int x,y; cin>>x>>y;
            if (x==y) {
                continue; //if self loop
            }
            graph[x].pb(y);
            graph[y].pb(x);
        }
        dfs(1,-1,0);
        REP(i,n+1) occ[i]=0;
        ap(1,-1);
        cout<<SZ(ans)<<endl;
        if (SZ(ans)==0){
            cout<<0<<endl;
        }
        else {
            sort(ALL(ans));
            for (auto i:ans){
                cout<<i<<' '; //indexes of Articulation Points
            }
            cout<<endl;
        }
        
        


    }
}