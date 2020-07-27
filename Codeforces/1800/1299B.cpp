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
#define endl '\n'
#define double long double
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS() 
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 998244353;
const ll maxn=1e3+5;
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
ll inv(ll x){
    return pw(x, mod-2);
}
double hypolen(pii x, pii y){
	return sqrt(SQ(y.s-x.s)+SQ(y.f-x.f));
}
double slope(pii x, pii y){
	if (x.f==y.f){
		return iinf;
	}
	return ((y.s-x.s)/(y.f-x.f));
}
signed main(){
    IOS();
    int n; cin>>n;
    vector<pii> vc(n);
    REP(i,n){
    	cin>>vc[i].f>>vc[i].s;
    }
    if (n%2) {
    	cout<<"No"<<endl;
    	return 0;
    }
    int div=n/2;
    bool qq=false;
    REP(i,n){
    	double ansa=hypolen(vc[i], vc[(i+1)%n]), ansb=slope(vc[i], vc[(i+1)%n]);
    	double tmpa=hypolen(vc[(i+div)%n], vc[(i+div+1)%n]), tmpb=slope(vc[(i+div)%n], vc[(i+div+1)%n]);
    	if (ansa!=tmpa||ansb!=tmpb){
    		qq=true;
    		break;
    	}
 
    }
    if (qq) cout<<"No"<<endl;
    else cout<<"YES"<<endl;
 
 
}
