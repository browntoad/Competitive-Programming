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

	int n; cin>>n;
	int N=(n+1)*n/2;
	int q; cin>>q;
	vector<int> bsearch(n+1);
	REP(i,n+1){
		bsearch[i]=i*(i+1)/2;
	}
	REP(i,q){
		int x; cin>>x;
		x=N-x;
		int cnt=0;
		string res;
		if (x==0){
			REP(i,n) res+='1';
			cout<<res<<endl;
			continue;
		}
		if (x==N){
			REP(i,n) res+='0';
			cout<<res<<endl;
			continue;
		}
		while(x>0&&cnt<=n){
			if (cnt!=0){
				cnt++;
				res+='1';
			}
			int v=lower_bound(ALL(bsearch), x)-bsearch.begin();
			if (v==n||bsearch[v]!=x){
				v--;
			}
			x-=bsearch[v];
			REP(i,v) res+='0';
			cnt+=v;
			//cout<<x<<endl;

		}
		if (cnt>n){
			cout<<"No\n";
			continue;
		}
		REP(i,n-cnt){
			res+='1';
		}
		cout<<res<<endl;
	}

}
