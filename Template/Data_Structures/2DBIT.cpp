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
#define pdd pair<double ,double>
#define pcc pair<char, char> 
#define endl '\n'
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
const ll inf = (1ll<<60);
const int iinf=2147483647;
const ll mod = 1e10;
const ll maxn=1005;
const double pi=acos(-1);
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return ret;
}
 
ll inv(ll a){
    return pw(a,mod-2);    
}
int bit[maxn][maxn];
char arr[maxn][maxn];
int n,m;
void update1d(int val, int i, int j){
    int cur=j;
    while(cur<=m){
        bit[i][cur]+=val;
        cur+=(cur&(-cur));
    }
}
void update2d(int val, int i, int j){
    int cur=i;
    while(cur<=n){
        update1d(val, cur, j);
        cur+=(cur&(-cur));
    }
}
int query1d(int i, int j){
    int cur=j, res=0;
    while(cur>0){
        res+=bit[i][cur];
        cur-=(cur&(-cur));
    }
    return res;
}
int query2d(int i, int j){
    int cur=i, res=0;
    while(cur>0){
        res+=query1d(cur, j);
        cur-=(cur&(-cur));
    }
    return res;
}
signed main(){
    IOS();
    
}