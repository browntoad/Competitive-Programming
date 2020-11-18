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
const ll B=131;
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
string str; int n;
vector<int> s, b;
bool NaiveS(int i, int j, int l){
	 if (j+l>n){
		return 0;
	}

	FOR(t, 0, l){
		if (str[i+t]!=str[j+t]) {
			return 0;
		}
	}
	return 1; 

}
bool S(int i, int j, int l){
	if (j+l>n) return 0;
	int cnt=s[i+l-1];
	if (i!=0) cnt-=s[i-1];
	cnt=(cnt%mod+mod)%mod;
	int h2=s[j+l-1]-s[j-1];
	h2=(h2%mod+mod)%mod;
	if (cnt*b[j-i]%mod==h2){
		return 1;
	}
	else return 0;
}
bool isPPAP(int ai, int bi){
	if (S(ai, bi, bi-ai)&&S(ai,3*(bi-ai)+ai, bi-ai)){
		return 1;
	}
	return 0;
}
void build(){

	REP(i,n) {
		if (i==0) b[i]=1;
		else b[i]=b[i-1]*B%mod;
	}
	REP(i,n){
		if (i==0) s[i]=str[i];
		else s[i]=(s[i-1]+(str[i])*b[i]%mod)%mod;
	}
}
signed main(){
	IOS();
	cin>>str;
	n=SZ(str);
	s=b=vector<int> (n);
	build();
	string ans;
	REP(i,n){
		REP1(j,n){
			if (i+j*4>n) break;
			if (isPPAP(i, i+j)) {
				//cout<<str.substr(i, j*4)<<endl;
				if (j*4>SZ(ans)){
					ans=str.substr(i, j*4);
				}
				if (j*4==SZ(ans)){
					ans=min(ans, str.substr(i, j*4));
				}
			}
		}
	}
	if (ans=="") ans="===>{*}(*)<===";
	cout<<ans<<endl;
}