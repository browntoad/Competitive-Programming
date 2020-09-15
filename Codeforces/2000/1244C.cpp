#include <iostream>
#include <vector>
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
#define int ll
using namespace std;
const ll inf = 1ll<<60;
//int d[100050][105];  
long long d[105];
signed main (){  
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
   	ll n,p,d,w; cin>>n>>p>>w>>d;
   	REP(i,w+1){
   		int store=p-i*d;
   		if (store%w==0&&store/w+i<=n&&store>=0){
   			cout<<store/w<<' '<<i<<' '<<n-(store/w+i)<<endl;
   			return 0;
   		}
   	}
   	cout<<-1<<endl;
 
}