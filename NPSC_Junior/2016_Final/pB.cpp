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
	//IOS();
	int n; cin>>n;
	vector<int> vc(n);
	REP(i,n) cin>>vc[i];
	REP(cs, n){
		int l=0, r=100;
		while(l<r){
			int mid=(l+r)/2;
			//cout<<mid<<endl<<flush;
			bool no = false;
			int cnt=mid;
			int curi=cs;
			FOR(i,cs+1,n){
				if (vc[i]-vc[curi]>cnt){
					cnt--;
					if (vc[i]-vc[i-1]>cnt){
						no=true;
						break;
					}
					curi=i-1;
				}
			}
			cnt=mid;
			curi=cs;
			for (int i=cs-1;i>=0;i--){
				if (vc[curi]-vc[i]>cnt){
					cnt--;
					if (vc[i+1]-vc[i]>cnt){
						no=true;
						break;
					}
					curi=i+1;
				}
			}
			//cout<<mid<<' '<<no<<endl;
			if (no){
				l=mid+1;
			}
			else r=mid;
		}
		cout<<l<<endl;
	}
}
