#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long
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
//#define int ll
using namespace std;
const ll inf = 1ll<<60;
const int iinf=1e9;
const ll mod = 1e9+7;

#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#else
#define bug(...)
#endif

signed main (){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n,m; cin>>n>>m;
  vector<int> vc[n];
  vector<int> out;
  int cnt=0;
  REP(i,n){
    vc[i].resize(m);
    int mx=0;
    REP(j,m) {
      cin>>vc[i][j];
      mx=max(mx, vc[i][j]);
    }
    cnt+=mx;
    out.pb(mx);
  }
  bool notneg=false;
  cout<<cnt<<endl;
  REP(i,SZ(out)){
    if (cnt%out[i]==0){
      if (notneg) cout<<' '<<out[i];
      else cout<<out[i];
      notneg=true;
    }

  }
  if (!notneg) cout<<-1;
  cout<<endl;


}
