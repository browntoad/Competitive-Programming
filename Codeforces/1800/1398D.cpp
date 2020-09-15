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
const ll maxn=205;
const double PI=acos(-1);
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
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
int dp[maxn][maxn][maxn];

signed main(){
	IOS();
	int r,g,b; cin>>r>>g>>b;
	vector<int> R(r), G(g), B(b);
	REP(i,r) cin>>R[i]; REP(i,g) cin>>G[i]; REP(i,b) cin>>B[i];
	sort(ALL(R), greater<int> ()); sort(ALL(G), greater<int> ()); sort(ALL(B), greater<int> ());

	int ans=-1;
	REP(i,r+1){
		REP(j,g+1){
			REP(k,b+1){
				if (i>0&&j>0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j-1][k]+R[i-1]*G[j-1]);
				if (k>0&&j>0) dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]+G[j-1]*B[k-1]);
				if (i>0&&k>0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]+R[i-1]*B[k-1]);
				if ((i+j+k)%2) dp[i][j][k]=-1;
				ans=max(ans, dp[i][j][k]);
			}
		}
	}
	cout<<ans<<endl;
}

