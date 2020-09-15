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
#define pdd pair<double, double>
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 998244353;
const ll maxn=1e5+5;
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
ll inv(ll x){
    return pw(x, mod-2);
}
signed main(){
    IOS();
    int n; cin>>n;
    vector<int> vc(n);
    int ans=0, ones=0;
    REP(i,n){
        cin>>vc[i];
        if (ones==0){
            ans+=vc[i]/3;
            ones+=vc[i]%3;
            continue;
        }
        int tmp=vc[i]/2;
        if (tmp<ones){
            ans+=tmp;
            ones-=(tmp);
            vc[i]=vc[i]%2;
        }
        else {
            ans+=ones;
            vc[i]-=ones*2;
            ones=0;
        }
        ans+=vc[i]/3;
        ones+=vc[i]%3;
 
    }
    cout<<ans<<endl;
 
}