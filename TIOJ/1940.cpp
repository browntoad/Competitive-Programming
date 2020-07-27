#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n);
#define REP1(i,n) FOR(i,1,n+1);
#define RREP(i,n) for (int i=(n)-1;i>=0; i--)
#define SZ(x) (int)(x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define endl '\n'
#ifdef TOAD
#define IOS()
#define bug(x) cerr<<"Line"__LINE__<<": "<<#x<<" is "<<x<<endl
#else
#define IOS() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define bug(x)
#endif
int rec(int x){
    if (x==0||x==2) return 0;
    if (x==1) return 1;
    if (x%2==0) return x/2;
    return rec(x/2);
}
signed main(){
    IOS();
    int k,n; cin>>k>>n;
    if (k==1 ) cout<<n<<endl;
    else cout<<rec(n);
}
