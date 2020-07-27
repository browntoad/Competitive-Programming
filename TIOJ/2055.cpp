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
#define endl '\n'
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const int maxn=1000005;
vector<int> vc(maxn);
vector<int> tre(maxn*4);
int find(int l, int r, int nl, int nr, int x){
    if (nl>r||nr<l){
        return iinf;
    }
    if (nl>=l&&nr<=r){
        return tre[x];
    }
    int mid=(nl+nr)/2;
    return min(find(l, r, nl, mid, x+x), find(l, r, mid+1, nr, x+x+1));
}
void build (int nl, int nr, int x){
    if (nl==nr){
       tre[x]=vc[nl];
       return;
    }
    int mid=(nl+nr)/2;
    build(nl, mid, x+x);
    build(mid+1, nr, x+x+1);
    tre[x]=min(tre[x+x], tre[x+x+1]);
}
signed main (){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n; cin>>n;
  REP1(i,n) cin>>vc[i];
  build(1,n,1);
  int q=n;
  //REP1(i,n*4) tre[i]=iinf;
  while (q--){
    int x,y; cin>>x>>y;
    cout<<find(x, y, 1, n, 1)+1<<endl;
  }
}
