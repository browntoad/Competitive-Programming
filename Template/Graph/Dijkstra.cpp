#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define ss second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define endl '\n'
#define int ll
using namespace std;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
signed main (){
   //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   int n,e,s,g; cin>>n>>e>>s>>g;
   s--; g--;
   vector<pii> vc[n];
   vector<bool> seen(n);
   fill(ALL(seen),false);
   REP(i,e){
      int a,b,w; cin>>a>>b>>w;
      vc[a-1].pb({w,b-1});
   }
   priority_queue<pii, vector<pii>, std::greater<pii> > pq;
   pq.push({0,s});
   bool ans = false;
   while (pq.empty() == false){
      //cout << pq.top().f << " " << pq.top().ss<< endl;
      if (pq.top().ss==g){
         cout<<pq.top().f<<endl;
         ans = true;
         break;
      }
      if (seen[pq.top().ss]==true){
         pq.pop();
         continue;
      }
      seen[pq.top().ss]=true;
      int pos=pq.top().ss;
      REP(i,SZ(vc[pos])){
         pq.push({pq.top().f+vc[pos][i].f,vc[pos][i].ss});
      }
      pq.pop();
   }
   if(!ans) {
      cout << "-1" << endl;
   }
}