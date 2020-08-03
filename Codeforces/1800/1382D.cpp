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
const ll maxn=4e3+5;
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
bool dp[maxn][maxn];
signed main (){
    IOS();
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<int> vc(2*n);
        REP(i,2*n) cin>>vc[i];
        n*=2;
        vector<int> seg;
        int l=n;
        for (int i=n; i>=1; i--) {
            FOR(j,0,n){
                if (vc[j]==i) {
                    if (j<l){
                        seg.pb(l-j);
                        l=j;
                    }

                }
            }
        }
        // i is index, j is val;
        int k=SZ(seg);
        REP(i,k+1){
            dp[i][0]=1;
            REP1(j,n/2){
                dp[i][j]=0;
            }
        }
        REP1(i,k){
            //cout<<seg[i-1]<<' ';
            REP1(j,n/2){
                if (seg[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else {
                    dp[i][j]=(dp[i-1][j]|dp[i-1][j-seg[i-1]]);
                }
            }
        }
        //cout<<endl;
        if (dp[k][n/2]){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}