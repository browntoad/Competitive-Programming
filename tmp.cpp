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
const ll maxn=2e5+5;
const double PI=acos(-1);
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

ll inv(ll a){
    return pw(a,mod-2); 
}
struct Dinic{
    static const int maxn=105;
    struct Edge{
        int to, cap, rev;
        Edge(){}
        Edge(int _to, int _cap, int _rev): to(_to), cap(_cap), rev(_rev){}
    };
    vector<Edge> G[maxn];
    void add_edge(int from, int to, int cap){
        G[from].pb(Edge(to, cap, SZ(G[to])));
        G[to].pb(Edge(from, 0, SZ(G[from])-1));
    }
    int n,s,t;
    void init(){
        REP(i,maxn) G[i].clear();
    }
    int lev[maxn], cur[maxn];
    void bfs(){
        fill(lev, lev+maxn, -1);
        lev[s]=0;
        queue<int> qu; qu.push(s);
        while(!qu.empty()){
            int tmp=qu.front();
            qu.pop();
            for (Edge e:G[tmp]){
                if (e.cap>0&&lev[e.to]==-1){
                    lev[e.to]=lev[tmp]+1;
                    qu.push(e.to);
                }
            }
        }
    }
    int dfs(int now, int flow){
        if (now==t||flow==0){
            return flow;
        }
        int fl=0;
        for (int &i=cur[now];i<SZ(G[now]);i++){
            Edge &e=G[now][i];
            if (lev[e.to]!=lev[now]+1||e.cap<=0) continue;
            int ret=dfs(e.to, min(flow, e.cap));
            if (ret>0){
                e.cap-=ret;
                G[e.to][e.rev].cap+=ret;
                fl+=ret;
                flow-=fl;
                if (flow==0) break; 
            }
            
        }
        return fl;
    }
    int flow(int _s, int _t){
        s=_s; t=_t;
        int fl=0;
        while(1){
            bfs();
            if (lev[t]==-1) break;
            fill(cur, cur+maxn, 0);
            int tmp;
            while((tmp=dfs(s,inf))>0){
                fl+=tmp;
            }
        }
        return fl;
    }
}flow;
signed main(){
    IOS();
    int n, z=0;
    while(cin>>n){
        if (n==0) break;
        z++;
        cout<<"Network "<<z<<endl;
        flow.init();
        int beg,en, m; cin>>beg>>en>>m;
        REP(i,m){
            int u,v,c; cin>>u>>v>>c;
            flow.add_edge(u,v,c);
            flow.add_edge(v,u,c);
        }
        cout<<"The bandwidth is "<<flow.flow(beg, en)<<'.'<<endl;
    }
}