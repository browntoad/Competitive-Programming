#include <bits/stdc++.h>
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
ll pow(ll a, ll p){
  ll ret=1;
  while (p>0){
    if (p&1){
      ret*=a;
      ret%=mod;
    }
    a*=a;
    a%=mod;
    p>>=1;
  }
  return ret;
}
ll inv (ll b){
  return pow(b, mod-2);
}
int ant[16][maxn];
int level[maxn];
pii LCA(int x, int y){
  pii ret;
  int orx=x, ory=y;
  if (level[x]<level[y]) swap(x,y);
  int lev=level[x]-level[y], a=0;

  while (lev>0){
    if (lev & 1){
      x=ant[a][x];
    }
    a++;
    lev>>=1;
  }
  int tiao=16;

  while (tiao>0){
    tiao--;
    //bug(tiao);
    //bug(ant[tiao][x]);
    //bug(ant[tiao][y]);
    if (ant[tiao][x]!=ant[tiao][y]){
      x=ant[tiao][x];
      y=ant[tiao][y];
    }
  }
  if (x!=y){
    x=ant[0][x];
    y=x;
  }
  return {x, level[orx]-level[x]+level[ory]-level[x]};

}
signed main (){
  IOS();
  int n,q; cin>>n>>q;
  level[1]=1;
  REP1(i,n){
    int in; //direct children of node i
    while (cin>>in, in){
      ant[0][in]=i;
      level[in]=level[i]+1;
    }    
  }
  ant[0][1]=1;
  REP1(i,15){
    REP1(j,n){
      ant[i][j]=ant[i-1][ ant[i-1][j] ];
    }
  }
  while (q--){
    int x,y; cin>>x>>y;
    pii rett=LCA(x,y);
    cout<<rett.f<<' '<<rett.s<<endl; //rett.f=index of LCA, rett.s=distance 
  }
}