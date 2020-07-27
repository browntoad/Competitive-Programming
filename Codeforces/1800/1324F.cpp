#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
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
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS() 
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 998244353;
const int maxn=2*1e5+5;
vector<int> vc(maxn), noe(maxn);
vector<pii> tre[maxn];
int dfs(int x, int prev){
    int ret=vc[x];
    REP(i,SZ(tre[x])){
        if (tre[x][i].f!=prev){
            tre[x][i].s=dfs(tre[x][i].f, x);
            if (tre[x][i].s>0){
                ret+=tre[x][i].s;
            }
        }
    }
    return noe[x]=ret;
 
 
}
vector<int> ans(maxn);
void dfs2(int x, int prev, int cnt){
    ans[x] = noe[x]+cnt;
 
    REP(i,SZ(tre[x])){
        if (tre[x][i].f!=prev) {
            int tmp=ans[x];
            if(tre[x][i].s >0) tmp-=tre[x][i].s;
            dfs2(tre[x][i].f, x, max(0ll,tmp) );
        }
    }
}
signed main(){
    IOS();
    int n; cin>>n;
    REP1(i,n){
        cin>>vc[i];
        if (!vc[i]) vc[i]=-1;
    } 
    REP(i,n-1){
        int x,y; cin>>x>>y;
        tre[x].pb({y,0});
        tre[y].pb({x,0});
    } //1 as root
    ans[1]=dfs(1,0);
    /*REP1(i,n){
        cout<<noe[i]<<endl;
    }
    */
    dfs2(1,0,0);
    REP1(i,n){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
