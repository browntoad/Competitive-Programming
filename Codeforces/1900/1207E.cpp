#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
//#define int ll
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
//#define endl '\n'
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
signed main (){
  IOS();
  int resa, resb;
  cout<<"? ";
  REP1(i,100) cout<<i<<' ';
  cout<<endl<<flush;
  cin>>resa;
  cout<<"? ";
  REP1(i,100) cout<<(i<<7)<<' ';
  cout<<endl<<flush;
  cin>>resb;
  resa>>=7;
  resa<<=7;
  resb&=127; //00000001111111
  cout<<"! "<<(resa|resb)<<endl<<flush;
 
}