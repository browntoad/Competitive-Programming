#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
 
#ifdef TOAD
#define IOS()
#define bug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" is "<<x<<endl
#else 
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define bug(x)
#endif 
const ll inf=(1ll<<60);
const double PI=acos(-1);
const int iinf=2147483647;
const ll mod=1e9+7;
const ll maxn=5e5+5;
ll pw(ll x, ll p){
	ll ret=1;
	while(p>0){
		if (p&1){
			ret*=x;
			ret%=mod;
		}
		p>>=1;
		x*=x;
		x%=mod;
	}
	return ret;
}

// Kosaraju SCC 
vector<int> graph[maxn], rgraph[maxn], occ(maxn), kosocc(maxn);
stack<int> st;
 
void dfs(int x, int prev){
	occ[x]=1;
	REP(i,SZ(graph[x])){
		if (graph[x][i]==prev||occ[graph[x][i]]){
			continue;
		}
		dfs(graph[x][i], x);
	}
	st.push(x);
}

void Kosaraju(int x, int prev){
	kosocc[x]=1;
	cout<<x<<' ';
	REP(i,SZ(rgraph[x])){
		if (rgraph[x][i]==prev||kosocc[rgraph[x][i]]){
			continue;
		}
		Kosaraju(rgraph[x][i], x);
	}
}
signed main(){
	IOS();
	int n,m; cin>>n>>m;
	REP(i,m){
		int x,y; cin>>x>>y;
		graph[x].pb(y);
		rgraph[y].pb(x);
 
	}
	REP(i,n){
		if (!occ[i]){
			dfs(i,-1);
		}
	}
	while(st.size()){
		if (kosocc[st.top()]){
			st.pop();
			continue;
		}
		Kosaraju(st.top(), -1);
		cout<<endl;
	}
 
	
 
}