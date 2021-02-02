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
const ll maxn=1005;
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
int n; 
int arr[maxn][maxn];
signed main(){
	IOS();
	cin>>n;
	REP(i,n) REP(j,n) cin>>arr[i][j];
	int ans=0;
	REP(j,n){
		int cura=0, curb=0;
		REP(i,n){
			if (i%2) curb+=arr[i][j];
			else cura+=arr[i][j];
		}
		ans+=max(cura, curb);
	}
	int cnt=0;
	REP(i,n){
		int cura=0, curb=0;
		REP(j,n){
			if (j%2) curb+=arr[i][j];
			else cura+=arr[i][j];
		}
		cnt+=max(cura, curb);
	}
	cout<<max(cnt, ans)<<endl;
}