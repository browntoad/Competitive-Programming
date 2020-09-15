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
signed main(){
	IOS();
	int T; cin>>T;
	while(T--){
		int n,l,r; cin>>n>>l>>r;
		vector<int> dp(n);
		REP1(i,n-1){
			dp[i]=dp[i-1]+2*(n-i);
		}
		dp[n]=dp[n-1]+1;
		int a=lower_bound(ALL(dp), l)-dp.begin();
		int b=lower_bound(ALL(dp), r)-dp.begin();
		bug(a);
		bug(b);
		int vala=dp[a-1];
		vector<int> ans;
		FOR(i,a,b+1){
			
			if (i<=1){
				vala++; 
				if (l<=vala&&r>=vala){
					ans.pb(1);
				}
				continue;
			}
			for (int j=i+1; j<=n;j++){
				vala++;
				if (l<=vala&&r>=vala){
					ans.pb(i);
				}
				vala++;
				if (l<=vala&&r>=vala){
					ans.pb(j);
				}
				bug(vala);
			}
			vala++;
			if (l<=vala&&r>=vala){
				ans.pb(i);
			}
			vala++;
			if (l<=vala&&r>=vala){
				ans.pb(1);
			}
			bug(vala);
			
		}
		REP(i,SZ(ans)){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
}
