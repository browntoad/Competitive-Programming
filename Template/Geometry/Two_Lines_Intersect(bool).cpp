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
};
double distance (Point a, Point b){
	return sqrt(SQ(b.x-a.x)+SQ(b.y-a.y));
}
int cross(Point a, Point b){
	return a.x*b.y-b.x*a.y;
}
Point subtract(Point a, Point b){
	return {a.x-b.x, a.y-b.y};
}
ll sign(ll a){
	if (a<0) return -1;
	return a>0;
}

// code only works if two segments are not collinear
signed main(){
	IOS();
	int t; cin>>t;
	while(t--){
		Point a,b; cin>>a.x>>a.y>>b.x>>b.y; //same segment
		Point c,d; cin>>c.x>>c.y>>d.x>>d.y; // same segment
		if (sign(cross(subtract(a,c), subtract(d,c)))*sign(cross(subtract(b,c), subtract(d,c)))>0||
		sign(cross(subtract(c,a), subtract(b,a)))*sign(cross(subtract(d,a), subtract(c,a)))>0){
			cout<<"No\n"<<endl; // they  do not intersect
		}									
		else {
			cout<<"Yes\n"<<endl; // they intersect
		}			
	}
					


}
