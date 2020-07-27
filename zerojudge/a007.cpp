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
bool prim[100005];
vector<int> p;
signed main (){ 
   int joe=sqrt(2147483647);
   FOR(i,2,joe){
      if (prim[i]) continue;

      p.push_back(i);
      for (int j=2*i;j<joe; j+=(i)){
         prim[j]=1;
      }
   }
   int n; 
   p.push_back(2147483646);
   //cout << p.size() << endl;
   while (cin>>n){
      //bool g=false;
      REP(i,SZ(p)){
         if (p[i]>=sqrt(n)) {
            cout<<"質數\n";
            break;

         }
         if (n%p[i]==0) {
            cout<<"非質數"<<endl;
            break;
         }//g=true;
      }
   }
   

}
