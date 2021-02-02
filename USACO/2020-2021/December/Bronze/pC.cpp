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
vector<int> ans;
struct Point{
	char dir;
	int x;
	int y;
	int id;
};


vector<Point> vc;
int n;
int rec(Point p){
	int ans=inf;
	REP(i,n){
		if (i==p.id||vc[i].dir==p.dir){
			continue;
		}

		if (p.dir=='E'){
			if (vc[i].y>p.y||vc[i].x<p.x||(p.y-vc[i].y)>=(vc[i].x-p.x)) continue;
			int v=rec(vc[i]);
			if (v+vc[i].y>=p.y){
				ans=min(ans, (vc[i].x-p.x));
			}
		}
		else {
			if (vc[i].y<p.y||vc[i].x>p.x||(p.x-vc[i].x)>=(vc[i].y-p.y)) continue;
			int v=rec(vc[i]);
			if (v+vc[i].x>=p.x){
				ans=min(ans, (vc[i].y-p.y));
			}
		}
	}
	return ans;
}
signed main(){
	IOS();
	cin>>n;
	vc=vector<Point> (n);
	ans=vector<int> (n);
	REP(i,n){
		ans[i]=inf;
		cin>>vc[i].dir>>vc[i].x>>vc[i].y;
		vc[i].id=i;
	} 
	//sort(ALL(vc), cmp1);
	
	REP(i,n){
		int val=rec(vc[i]);
		if (val==inf) cout<<"Infinity"<<endl;
		else cout<<val<<endl;
	}
	
}
