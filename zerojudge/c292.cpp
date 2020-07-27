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
int n; 
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int vc[50][50];
int seen[50][50];
void run(int x, int y, int dir){
   dir%=4;
   cout<<vc[x][y];
   seen[x][y]=true;
   int nx=dx[(dir+1)%4]+x;
   int ny=dy[(dir+1)%4]+y;
   if (!seen[nx][ny]){
      dir=(dir+1)%4;
      x=nx;
      y=ny; 
      run(nx,ny,dir);
      return;
   }
   int nnx=dx[dir]+x;
   int nny=dy[dir]+y;
   if ((nnx>=n||nnx<0||nny>=n||nny<0)){
      return;
   }
   if (seen[nx][ny]){
      run(nnx,nny,dir);
   }

}
signed main (){
   //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   while (cin>>n){
   int d; cin>>d;
   REP(i,n){
      REP(j,n){
         cin>>vc[i][j];
      }
   }
   run(n/2, n/2, d+3);
   cout<<endl;
}
}
