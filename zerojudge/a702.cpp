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
#define PI 3.14159265
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
const ll maxn=2e7+5;
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return ret;
}

ll inv(ll a, ll b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}
vector<int> sieve(maxn), nums;
signed main (){
    //IOS();
    REP(i,maxn+1) sieve[i]=1;
    for (int i=2; i<=maxn; i++){
    	if (sieve[i]){
    		for (int j=i*i; j<=maxn; j+=i){
    			sieve[j]=0;
    		}
    	}
    }
    int cnt=0;
    for (int i=2; i<=2e7; i++){
    	if (cnt>100000) break;
    	if (sieve[i]&&sieve[i+4]){
    		nums.pb(i);
    		cnt++;
    	}
    }
    int n; 
    //cout<<nums[0]<<endl;
    while (cin>>n){
    	cout<<'('<<nums[n-1]<<", "<<nums[n-1]+4<<')'<<endl;
    }
}