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
const ll maxn=105;
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
struct Edge{
	int v;
	int cap;
	Edge* rev;
};
vector<Edge*> vc[maxn];
void add_edge(int u, int v, int cap){
	Edge *e=new Edge(), *re=new Edge();
	*e={v,cap,re};
	*re={u,0,e};
	vc[u].pb(e);
	vc[v].pb(re);
}
vector<bool> visited(maxn);
int dfs(int u, int t, int f){
	if (u==t){
		return f;
	}
	visited[u]=1;
	REP(i,SZ(vc[u])){
		Edge *e=vc[u][i];
		if (!visited[e->v]){
			if (!(e->cap)) continue; 
			int res=dfs(e->v, t, min(f, e->cap));
			if (res!=0){
				e->cap-=res;
				e->rev->cap+=res;
				return res;
			}
		}
	}
	return 0;
}
int FordFulkerson(int s, int t){
	int ans=0;
	while(1){
		fill(ALL(visited), 0);
		int res=dfs(s, t, inf);
		if (!res) break;
		ans+=res;
	}
	return ans;
}
signed main(){
	IOS();
	/*int n; 
	while(cin>>n, n>0){
		int m; 
		int s,t; cin>>s>>t>>m;
		REP(i,n+1){
			vc[i].clear();
		}
		REP(i,m){
			int u,v,cp; cin>>u>>v>>cp;
			add_edge(u,v,cp);
			add_edge(v,u,cp);
		}
		cout<<"Network "<<z<<endl;
		cout<<"The bandwidth is "<<FordFulkerson(s,t)<<'.'<<endl;
	}
	*/
	
}