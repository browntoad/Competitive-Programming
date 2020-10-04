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
struct Point{
	double x,y;
}
double dis(Point a, Point b){
	return sqrt(SQ(a.x-b.x)+SQ(a.y-b.y))
}
Point cc(Point a, Point b, Point c){
	// complete 
}
signed main(){
	IOS();
	int n; cin>>n;
	vector<Point> vc(n);
	REP(i,n) cin>>vc[i];
	random_shuffle(ALL(vc));
	int r=0
	Point cent=0;
	REP(i,n){
		if (dis(vc[i], cent)<=r) continue;
		cent=vc[i];
		REP(j,n){
			if (i==j) continue;
			if (dis(vc[j], cent)<=r) continue;
			cent.x=(vc[j].x+cent.x)/2.0;
			cent.y=(vc[j].y+cent.y)/2.0;
			r=dis(vc[j], cent);
			REP(k,n){
				if (dis(vc[k], cent)<=r){
					continue;
				}
				cent=cc(vc[i], vc[j], vc[k]);
				r=dis(vc[k], cent);
			}
		}
	}
}
