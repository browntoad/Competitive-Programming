#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
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
const ll mod = 1e9+7;
const int maxn=1000005;
int dp[300005][3];
int pos[300005][3];
int bee[300005];
signed main (){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int q; cin>>q;
  while (q--){
    int n; cin>>n;
    REP(i,n+1){
        REP(j,3){
            dp[i][j]=0;
        }
    }
    REP(i,n) {
        int x,y; cin>>x>>y;
        pos[i][0]=x;
        pos[i][1]=x+1;
        pos[i][2]=x+2;
        bee[i]=y;
    }
    REP(i,3){
        dp[0][i]=i*bee[0];
    }
    REP1(i,n-1){
        REP(j,3){
            int mn=inf;
            REP(k,3){
                if (pos[i][j]!=pos[i-1][k]){
                    mn=min(mn, dp[i-1][k]);
                }
            }
            dp[i][j]=mn+bee[i]*j;
        }
    }
    cout<<min({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;
    /*REP(i,n){
        REP(j,3){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    
  }
}
