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
const ll maxn=5e3+5;
const double PI=acos(-1);
 
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
 
ll inv(ll a, ll m=mod){
    return pw(a,m-2);
}
ll inv2(ll a, ll md){
    return pw(a,md-2);
}
 
 
//=======================================================================================
 
int c(int n){
	return n%mod*(n-1)%mod*inv(2)%mod;
}
signed main (){
    IOS();
	int n; cin>>n;
	vector<pii> vc(n+1);
	REP(i,n) cin>>vc[i].f; //height
	REP(i,n) cin>>vc[i].s; //width
	vc[n]={0,0};
	stack<pii> st;
	int ans=0;
	REP(i,n+1){
		//if (!st.empty()) cout<<i<<"   "<<st.top().f<<' '<<st.top().s<<endl;
		//else cout<<"Blancko "<<i<<endl;
		if (st.empty()||st.top().f<vc[i].f){
			st.push(vc[i]);
			continue;
		}
		if (st.top().f==vc[i].f){
			int k=vc[i].s+st.top().s;
			k%=mod;
			st.pop();
			st.push({vc[i].f, k});
			continue;
		}
		while(st.size()){
			if (st.top().f<vc[i].f){
				break; 
			}
			if (st.top().f==vc[i].f){
				vc[i].s+=st.top().s;
				vc[i].s%=mod;
				st.pop();
				break;
			}
			if (st.size()==1){
				int m=st.top().f-vc[i].f;
				int k=vc[i].f;
				ans+=(m+2*k+1)%mod*m%mod*inv(2)%mod*c(st.top().s+1)%mod;
				ans%=mod;
				vc[i].s+=st.top().s;
				vc[i].s%=mod;
				st.pop();
				break;
			}
			pii tmp=st.top();
			st.pop();
			pii lef=st.top();
			st.pop();
			int m=tmp.f-lef.f;
			int k=lef.f;
			if (lef.f<vc[i].f){
				m=tmp.f-vc[i].f;
				k=vc[i].f;
			}
			ans+=(m+2*k+1)%mod*m%mod*inv(2)%mod*c(tmp.s+1)%mod;
			ans%=mod;
			//cout<<ans<<endl;
			if (lef.f>=vc[i].f){
				st.push({lef.f, (tmp.s+lef.s)%mod});
			}
			else {
				st.push({lef.f, lef.s%mod});
				vc[i].s+=tmp.s;
				vc[i].s%=mod;
			}
		}
		st.push({vc[i].f, vc[i].s%mod});
	}
	cout<<ans%mod<<endl;
}
/*
10
16 9 28 23 17 6 28 21 7 11
1 1 1 1 1 1 1 1 1 1 
 
should be 3645
*/
