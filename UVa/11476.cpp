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
const int mask=255;
ll mul(ll x, ll y, ll M){
	if (y<(1<<8)){
		return x*y%M;
	}
	else {
		ll hi=y>>7, low=y%256;
		return (mul(x,hi, M)*256+x*low)%M;
	}
}

ll inv(ll a){
	return pw(a,mod-2);	
}
int F(int n){
	if (n>2&&n%2==0){
		return 2;
	}
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int x,y,d=1;
	x=rng()%n;
	y=x;
	auto g=[&](int x){
		return (mul(x,x,n)+1)%n;
	};
	int cnt=10*pow(n,0.25);
	while (d==1){
		x=g(x);
		y=g(g(y));
		 d=__gcd(abs(x-y), n);
		cnt--;
		if (cnt<0) {
			return -1;
		}
	}
	if (d==n){
		return -1;
	}
	return d;
}
map<int, int> mp;
void rec(int a){
	if (F(a)==-1) mp[a]++;
	else {
		int t=F(a);
		rec(t);
		rec(a/t);
	}

}
signed main(){
	//IOS();
	int T; cin>>T;
	while(T--){
		mp.clear();
		int n; cin>>n;
		int N=n;
		rec(n);

		vector<pii> ans;
		for (auto i:mp){
			ans.pb(i);

					//		cout<<"asdf"<<endl;

		}
		sort(ALL(ans));
		cout<<N<<" = ";
		if (SZ(ans)==1) {
			cout<<N<<endl;
			continue;
		}
		REP(i,SZ(ans)){
			if (ans[i].f==1||ans[i].f==N) continue;
			if (i!=0) cout<<"* ";
			if (ans[i].s==1) cout<<ans[i].f<<' ';
			else cout<<ans[i].f<<'^'<<ans[i].s<<' ';
				//			cout<<"asdf"<<endl;


		}
		cout<<endl;
		

	}
}