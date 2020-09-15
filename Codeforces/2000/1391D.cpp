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
const ll maxn=1e6+5;
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
int dp[maxn][(1<<3)];
bool valid[2][8][8];
void init(){
	REP(i,4){
		int cnt=0;
		if (i==3) cnt=2;
		else if (i!=0) cnt=1;  
		REP(j,4){
			int c=0;
			if (j==3) c=2;
			else if (j!=0) c=1; 
			if ((cnt+c)%2){
				valid[0][i][j]=1;
			}
			else valid[0][i][j]=0;
		}
	}
	REP(i,8){
		REP(j,8){

			valid[1][i][j]=((valid[0][i>>1][j>>1])&(valid[0][i-(i&4)][j-(j&4)]));
		}
	}
	//int i=0, j=5;
	//cout<<i-(i&1)<<endl;
	//cout<<j-(j&1)<<endl;
	//cout<<valid[0][i-(i&1)][j-(j&1)]<<endl;
}
int match(int x, int y){
	int cnt=0;
	REP(i,3){
		char a,b;
		if ((1<<i)>x||(((1<<i)&x)==0)) a='0';
		else a='1';
		if ((1<<i)>y||(((1<<i)&y)==0)) b='0';
		else b='1';
		if (a!=b){
			cnt++;
		}

	}
	
	return cnt;
}
signed main(){
	IOS();
	init();
	int n,m; cin>>n>>m;
	if (n>=4&&m>=4){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> vc(max(n,m));
	if (n>m){
		REP(i,n){
			string str; cin>>str;
			REP(j,m){
				int k=str[j]-'0';

				vc[i]+=(1<<(m-j-1))*(k);
			}
		}
		swap(n,m);
	}
	else {
		REP(i,n){
			string str; cin>>str;
			REP(j,m){
				int k=str[j]-'0';
				vc[j]+=(1<<(n-i-1))*(k);
			}

		}
		//REP(i,m) cout<<vc[i]<<endl;
	}
	//n < m
	if (n==1){
		cout<<0<<endl;
		return 0;
	}
	REP1(i,m){
		REP(j,(1<<(n))){
			dp[i][j]=INT_MAX;
			REP(k,(1<<(n))){
				if (valid[n-2][j][k]){
					//cout<<match(vc[i-1], j)<<' '<<j<<' '<<vc[i-1]<<endl;
					dp[i][j]=min(dp[i][j], dp[i-1][k]+match(j, vc[i-1]));
				}
			}
		}
	}
	int ans=INT_MAX;
	REP(i,(1<<n)){
		ans=min(ans, dp[m][i]);
	}
	cout<<ans<<endl;
	/*REP(i,(1<<n)){
		REP(j,(1<<n)){
			cout<<valid[n-2][i][j]<<' ';
		}
		cout<<endl;
	}
	*/
}