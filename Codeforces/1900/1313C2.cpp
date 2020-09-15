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
const int maxn=1e6+5;
signed main (){
  IOS();
  int n; cin>>n;
  vector<int> vc(n), con(n);
  REP(i,n) cin>>vc[i];
  stack<pair<int, int>> st;
  st.push({0, 1});
  int cnt=0;
  REP(i,n){
    int add=0;
    while (vc[i]<=st.top().f){
      cnt-=st.top().s*st.top().f;
      add+=st.top().s;
      st.pop();
    }
    st.push({vc[i], add+1});
    cnt+=(add+1)*vc[i];
    con[i]+=cnt;
  }
  cnt=0;
  while (!st.empty()){
    st.pop();
  }
  st.push({0, 1});
  RREP(i,n){
    int add=0;
    while (vc[i]<=st.top().f){
      cnt-=st.top().s*st.top().f;
      add+=st.top().s;
      st.pop();
    }
    st.push({vc[i], add+1});
    cnt+=(add+1)*vc[i];
    con[i]+=cnt;
    con[i]-=vc[i];
  }
  int mx=0, id=0;
  REP(i,n){
    if (con[i]>mx) {
      id=i;
      mx=con[i];
    }
  }
  int i=id;
  int sf=vc[i];
  cnt=0;
  vector<int> can(n);
  for (int j=i; j>=0; j--){
    sf=min(sf, vc[j]);
    can[j]=sf;
    cnt+=sf;
  }
  for (int j=i+1; j<n; j++){
    can[j]=min(vc[j], can[j-1]);
    cnt+=can[j];
  }
  REP(i,n) cout<<can[i]<<' ';
  cout<<endl;
 
 
}