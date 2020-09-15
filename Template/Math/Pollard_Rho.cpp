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
using pii = pair<int, int>;
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
int F(int n){
	if (n>2&&n%2==0) return 2;
	int x=rand()%n;
	int y=x;
	int d=1;
	auto g=[&](int x){
		return (x*x-5)%n;
	};
	while (d==1){
		x=g(x);
		y=g(g(y));
		 d=gcd(abs(x-y), n);
	}
	if (d==n){
		return -1;
	}
	return d;
}
signed main(){
	IOS();
	int N; cin>>N;
	srand(time(0));
	cout<<F(N)<<endl;

}