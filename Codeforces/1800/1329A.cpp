#include <bits/stdc++.h>
#pragma GCC optimize ('Ofast', 'unroll-loops')
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
const int maxn=30005;
ll poow(ll a, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=a;
        }
        a*=a;
        p>>=1;
    }
    return ret;
}
ll inv(ll x){
    return pow(x, mod-2);
}
 
signed main(){
    IOS();
    int n,q; cin>>n>>q;
    vector<int> vc(q), pf(q);
    int mx=0, lon=0;
    vector<int> covid(q);
    REP(i,q){
        cin>>vc[i];
        mx+=vc[i];
        lon=max(lon, vc[i]+i);
        pf[i]=lon;
        covid[i]=i+1;
    }
    if (lon>n||mx<n){
        cout<<-1<<endl;
        return 0;
    }
    if (lon==n){
        REP(i,q){
            cout<<covid[i]<<' ';
        }
        cout<<endl;
        return 0;
    }
    //REP(i,q) cout<<pf[i]<<endl;
    int cnt=0;
    RREP(i,q){
        if (i!=0){
            //cout<<pf[i-1]<<endl;
            //lon=pf[i-1]+1;
            cnt+=vc[i];
            covid[i]=n-cnt+1;
            //cout<<lon<<endl;
            //lon+=vc[i]-1;
            if (cnt+pf[i-1]>=n){
                break;
            }
            
        }
    }
    REP(i,q) cout<<covid[i]<<' ';
    cout<<endl;
    
}
