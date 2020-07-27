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
int dp[100005][5];
signed main (){
  IOS();
  int n; cin>>n;
  string str; cin>>str;
  vector<int> vc(n);
  REP(i,n) cin>>vc[i];
  string t="hard";
  REP(i,n+1){
    REP(j,5){
      dp[i][j]=inf;
    }
  }
  dp[0][0]=0;
  REP(i,n){
    REP(j,4){
      if (t[j]==str[i]){
        dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]);
      }
      else dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
      dp[i+1][j] = min(dp[i+1][j], dp[i][j] + vc[i]);
    
    }
  }
  cout<<min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]})<<endl;
}
