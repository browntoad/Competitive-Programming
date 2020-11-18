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
const ll maxn=2005;
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
int dp[maxn][maxn];
int n;
vector<int> vc, ans;
/*string vc;
string dp[maxn][maxn];
void DP(int l, int r){
	if (dp[l][r]!=""){
		return;
	}
	if (l==r){
		dp[l][r]=vc[l];
		return;
	}
	if (r-l==1){
		if (vc[l]==vc[r]){
			dp[l][r]=vc[l]+vc[r];
			return;
		}
		else {
			if (vc[l]<vc[r]){
				dp[l][r]=vc[l]+vc[r]+vc[l];
			}
			else {
				dp[l][r]=vc[r]+vc[l]+vc[r];
			}
		}
		return;
	}
	if (vc[l]==vc[r]){
		dp[l][r]=vc[l]+dp[l+1][r-1]+vc[r];
		return;
	}
	//if (SZ())
	if (vc[l]<vc[r]){
		dp[l][r]=vc[l]+dp[l+1][r]+vc[l];
	}
	else {
		dp[l][r]=vc[r]+dp[l][r-1]+vc[r];
	}
}
*/
void DP(int l, int r){
	if (r==l){
		ans.pb(vc[l]);
		return;
	}
	if (r-l==1){
		if (vc[l]==vc[r]){
			ans.pb(vc[l]); ans.pb(vc[r]);

		}
		else {
			if (vc[l]<vc[r]){
				ans.pb(vc[l]); ans.pb(vc[r]); ans.pb(vc[l]);
			}
			else {
				ans.pb(vc[r]); ans.pb(vc[l]); ans.pb(vc[r]);
			}
			
		}
		return;
	}
	if (vc[l]==vc[r]){
		ans.pb(vc[l]);
		DP(l+1, r-1);
		ans.pb(vc[r]);
	}
	else {
		if (dp[l+1][r]<dp[l][r-1]||(vc[l]<vc[r]&&dp[l+1][r]==dp[l][r-1])){
			ans.pb(vc[l]); DP(l+1, r); ans.pb(vc[l]);
		}
		else {
			ans.pb(vc[r]); DP(l, r-1); ans.pb(vc[r]);
		}
		
	}


}
signed main(){
	IOS();
	cin>>n;
	vc=vector<int> (n+1); 
	REP1(i,n) cin>>vc[i];
	for (int i=n;i>=1;i--){
		FOR(j,i,n+1){
			if (i==j){
				dp[i][j]=1;
				continue;
			}
			if (j-i==1){
				if (vc[i]==vc[j]) dp[i][j]=2;
				else dp[i][j]=3;
				continue;
			}
			if (vc[i]==vc[j]) dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=min(dp[i+1][j], dp[i][j-1])+2;

		}
	}

	DP(1,n);
	/*int cnt=0;
	cout<<vc<<endl;
	REP(i,SZ(dp[1][n])){
		cnt^=dp[1][n][i]+(i+1);
	}
	cout<<cnt<<endl;
	*/
	int cnt=0;
	REP(i,SZ(ans)){
		cnt^=ans[i]+i+1;
		//cout<<ans[i]<<' ';
	}
	//cout<<endl;
	cout<<cnt<<endl;
}