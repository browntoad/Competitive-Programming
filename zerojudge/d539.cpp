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
const ll mod = 1e9+7;
vector<int> vc(500005);
vector<int> tre(500005*4);
int find(int l, int r, int nl, int nr, int x){
   if (nl>r||nr<l){
      return -1;
   }
   if (nl>=l&&nr<=r){
      return tre[x];
   }
   int md=(nl+nr)/2;
   return max(find(l,r,nl,md,x+x), find(l,r,md+1,nr,x+x+1));
}
void build(int nl, int nr, int x){
   if (nl==nr){
      tre[x]=vc[nl];
      return;
   }
   int md=(nl+nr)/2;
   build(nl, md, x+x);
   build(md+1,nr,x+x+1);
   tre[x]=max(tre[x+x], tre[x+x+1]);
}
signed main (){
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   int n; cin>>n;
   REP1(i,n) cin>>vc[i];
   int q; cin>>q;
   build(1,n,1);
   REP(i,q){
      int x,y; cin>>x>>y;
      if (x>y) swap(x,y);
      cout<<find(x,y,1,n,1)<<endl;
   }
}
