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
const int MaxN = 1000000+5;
const int MaxQ = 100000+5;
vector<int> tre(MaxN*4);
vector<int> tr(MaxN*4);

int A[MaxN];
bool C[MaxQ];
int X[MaxQ] , Y[MaxQ];
int k,m,N,Q;
void gen_dat()
{
    int i,j;
    for( i=k+1; i<=max(Q,N); ++i )
         A[i] = ( A[i-2]*97 + A[i-1]*3 )%m+1;
    for(i=1,j=max(Q,N); i<=Q; ++i,--j)
    {
        C[i] = A[i]&1;
        X[i] = (A[i]+A[j])%N+1;
        if(C[i]) Y[i] = X[i]+ ( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 );
        else Y[i] = ((A[i]<<3)+(A[j]<<5))%m+1;
    }
}
int fin(int l, int r, int nl, int nr, int x){
   if (nl>r||nr<l){
      return -1;
   }
   if (nl>=l&&nr<=r){
      return tre[x];
   }
   int md=(nl+nr)/2;
   return max(fin(l,r,nl,md,x+x), fin(l,r,md+1,nr,x+x+1));
}
int find2(int l, int r, int nl, int nr, int x){
   if (nl>r||nr<l){
      return 1e9;
   }
   if (nl>=l&&nr<=r){
      return tr[x];
   }
   int md=(nl+nr)/2;
   return min(find2(l,r,nl,md,x+x), find2(l,r,md+1,nr,x+x+1));
}
void build(int nl, int nr, int x){
   if (nl==nr){
      tre[x]=A[nl];
      tr[x]=A[nl];
      return;
   }
   int md=(nl+nr)/2;
   build(nl, md, x+x);
   build(md+1,nr,x+x+1);
   tre[x]=max(tre[x+x], tre[x+x+1]);
   tr[x]=min(tr[x+x], tr[x+x+1]);
}

void change(int nl, int nr, int pos, int value, int x){
   if (nl==nr){
      tre[x]=value;
      tr[x]=value;
      return;
   }
   int md=(nl+nr)/2;
   if (pos>=nl&&pos<=md){
      change(nl,md,pos,value, x+x);
   }
   else {
      change(md+1,nr,pos,value, x+x+1);
   }
   tre[x]=max(tre[x+x], tre[x+x+1]);
   tr[x]=min(tr[x+x], tr[x+x+1]);
}
signed main (){
   //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   cin >> k >> m;
   REP1(i, k){
      cin >> A[i];
   }
   cin >> N >> Q;
   gen_dat();


   build(1,N,1);
   REP1(i, Q) {
   // cout << C[i] << " " << X[i] << " " << Y[i]<< endl;
    if(C[i] == 0){
        if(X[i] == 0 ) continue;
         A[X[i]]=Y[i];
         change(1,N,X[i], Y[i], 1);
         // modify
      }else {
         cout<<fin(X[i], Y[i], 1, N, 1)-find2(X[i], Y[i], 1, N, 1)<<endl;
         // find
      }
   }

}
