#include <bits/stdc++.h>
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
//#define TOAD
#define int ll
using namespace std;
const ll inf = 1ll<<60;
const int iinf=1e9+7;
const ll mod = 1e9+7;
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#else
#define bug(...)
#endif
int n;
vector<int> vc(500005);
struct Node{
  ll value;
  ll tag;
};
vector<Node> tre(500005*4);
void push(int lsiz, int rsiz, int x){
  tre[x+x].value+=lsiz*tre[x].tag;
  tre[x+x+1].value+=rsiz*tre[x].tag;
  tre[x+x].tag+=tre[x].tag;
  tre[x+x+1].tag+=tre[x].tag;
  tre[x].tag=0;
}
int find(int l, int r, int nl, int nr, int x){
   if (nl>r||nr<l){
      return 0;
   }
   if (nl>=l&&nr<=r){
      return tre[x].value;
   }
  
   int md=(nl+nr)/2;
  
   push((md-nl+1), (nr-md), x);

   return find(l,r,nl,md,x+x)+find(l,r,md+1,nr,x+x+1);
}
void build(int nl, int nr, int x){
   if (nl==nr){
      tre[x].value=vc[nl];
      return;
   }
   int md=(nl+nr)/2;
   build(nl, md, x+x);
   build(md+1,nr,x+x+1);
   tre[x].value=tre[x+x].value+tre[x+x+1].value;
}

void change(int l, int r, int nl, int nr, int x, int val){
  if (nl>r||nr<l){
    return;
  }
  if (nl>=l&&nr<=r) {
    tre[x].value+=val*(nr-nl+1);
    tre[x].tag+=val;
    return;               
  }
  int mid=(nl+nr)/2;
  
  push((mid-nl+1), (nr-mid), x);

  change(l,r,nl, mid, x+x, val);
  change(l,r,mid+1,nr,x+x+1, val);
  tre[x].value=tre[x+x+1].value+tre[x+x].value;
}
signed main (){
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin>>n;
  REP1(i,n) cin>>vc[i];
  int q; cin>>q;
  build(1,n,1);
  while (q--){
    int con,x,y; cin>>con>>x>>y;
    if (con==1){
      int p; cin>>p;
      change(x,y,1,n,1,p);
    }
    else {
      cout<<find(x,y,1,n,1)<<endl;
    }
  }
}
