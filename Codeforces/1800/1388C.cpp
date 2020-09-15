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
const ll maxn=1e5+5;
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
vector<int> nums(maxn), graph[maxn], val(maxn);
bool die=false;
void occ(int x, int prev){
	int cnt=0;
	REP(i,SZ(graph[x])){
		if (graph[x][i]!=prev){
			occ(graph[x][i], x);
			nums[x]+=nums[graph[x][i]];
		}
	}
	//cout<<x<<"asde "<<nums[x]<<endl;

}
void dfs(int x, int prev){
	if (die) return;
	if (SZ(graph[x])<=1&&x!=1){
		return;
	}
	if ((nums[x]+val[x])%2==1||val[x]>nums[x]||val[x]<nums[x]*(-1)){
		die=true;
		return;
	}
	int v=(nums[x]+val[x])/2;
	int cnt=0;
	REP(i,SZ(graph[x])){
		if (graph[x][i]==prev) continue;
		int vtmp=(val[graph[x][i]]+nums[graph[x][i]])/2;
		if ((val[graph[x][i]]+nums[graph[x][i]])&1||val[graph[x][i]]>nums[graph[x][i]]||
												val[graph[x][i]]<nums[graph[x][i]]*(-1)){
			die=true;
			return;
		}
		cnt+=vtmp;


	}
	bug(cnt);
	if (cnt>v){
		die=true;
		return;
	}
	REP(i,SZ(graph[x])){
		if (graph[x][i]!=prev){
			dfs(graph[x][i], x);
		}
	}
	
}

signed main(){
	IOS();
	int T; cin>>T;
	while(T--){
		die=false;
		int n; cin>>n;
		int m; cin>>m;
		REP(i,n+1) graph[i].clear();
		REP(i,n){
			cin>>nums[i+1];			
		}
		REP(i,n){
			cin>>val[i+1];
		}

		REP(i,n-1){
			int x,y; cin>>x>>y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		occ(1, -1);
		dfs(1, -1);
		if (die){
			cout<<"NO\n";
		}
		else cout<<"YES\n";

	}
}

/*
1
3 12
4 4 4
2 -2 8
1 2
2 3
*/