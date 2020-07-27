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
#define IOS() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
int a,m,k, ans; 
int gg;
vector<int> primefac;
void pai(int x, int prod, int ispos){
  if (x==SZ(primefac)){
    ans+=k/prod*ispos;
    return;
  }
  pai(x+1, prod*primefac[x], ispos*(-1));
  pai(x+1, prod, ispos);
}
signed main (){
  //IOS();
  int T; cin>>T;
  while (T--){
    ans=0;
    cin>>a>>m;
    k=m/__gcd(a,m);
    gg=__gcd(a,m);
    primefac.clear();
    int ff=k;
    //cout << "OAO\n";
    for (int i=2; i*i<=ff; i++){
      bug(i);
      if (ff%i==0){
        primefac.pb(i);
        while (ff%i==0){
          ff/=i;
        }
      }
    }
    if (ff!=1){
      primefac.pb(ff);
    }
    //cout <<"HI  "<< primefac.size() << endl;
    pai(0,1,1);    
    cout<<ans<<endl;
   }
 }
