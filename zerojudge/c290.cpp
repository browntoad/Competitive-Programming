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

signed main (){
   //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   string str; 
   while (cin>>str){
   int cnt=0;
   REP(i,SZ(str)){
      if ((SZ(str)-i)%2==0){
         cnt+=str[i]-'0';
      }
      else cnt-=str[i]-'0';
   }
   cout<<abs(cnt)<<endl;
}
}
