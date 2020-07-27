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
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=5e3+5;
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
    
 
signed main(){
    IOS();
    int n,m,k; cin>>n>>m>>k;
    if (2*n*m%k!=0){
        cout<<"NO\n";
        return 0;
    }
    int N=n, M=m, K=k;
    bool kodd=true;
    if (k%2==0) {
        k/=2;
        kodd=false;
    }
    cout<<"YES\n";
    int gcd=__gcd(n,k);
    N=n/gcd;
    K=k/gcd;
    M=m/K;
    if(kodd){
        if (N<n){
            N*=2;
        }
        else M*=2;
    }
    cout<<0<<' '<<0<<endl;
    cout<<0<<' '<<M<<endl;
    cout<<N<<' '<<0<<endl;
 
}
