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
int sum(int x, int y){
	return (x+y)*(y-x+1)/2;
}
signed main(){
	IOS();
	int n,x; cin>>n>>x;
	vector<int> vc(n);
	REP(i,n) cin>>vc[i];
	vector<int> pf(n), sf(n), pfsum(n), sfsum(n);
	REP(i,n){
		if (i==0){
			pf[i]=vc[i];
			pfsum[i]=sum(1,vc[i]);
		}
		else {
			pf[i]=pf[i-1]+vc[i];
			pfsum[i]=pfsum[i-1]+sum(1,vc[i]);
		}
		if (i==n-1){
			sf[i]=vc[i];
			sfsum[i]=sum(1,vc[i]);
		}
		else {
			sf[i]=sf[i+1]+sf[i];
			sfsum[i]=sfsum[i+1]+sum(1,vc[i]);
	}


	pii cur={0,0}; //index, amount remaining
	int ans=0;
	RREP(i,n){
		if (sf[i]>=x-vc[0]){
			int k=sf[i+1]-
			cnt+=sum(vc[i]-k+1, vc[i]);
			ans=max(cnt, ans);
			break;
		}
		cnt+=sum(1,vc[i]);
	}
	if (cnt==0){
		cur={0,}
	}
	cnt=0;



}
