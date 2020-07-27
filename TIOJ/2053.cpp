#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
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
const ll mod = 1e9+7;
const int maxn=1000005;

struct matrix{
    int arr[2][2];
    matrix(){
        arr[0][0]=1;
        arr[0][1]=0;
        arr[1][0]=0;
        arr[1][1]=1;
    }
    void operator =(matrix A) {
        REP(i,2)REP(j,2) arr[i][j] = A.arr[i][j];
    }
};
matrix mul(matrix A, matrix B) {
    matrix ret;
    REP(i,2){
        REP(j,2){
            ret.arr[i][j]=0;
            REP(k, 2){
                ret.arr[i][j]+=A.arr[i][k]*B.arr[k][j];
                ret.arr[i][j]%=mod;
            }
        }
    }
    return ret;
}
matrix pow(matrix A, ll k){
    matrix ret;
    while (k){
        if (k&1){
            ret=mul(ret, A);
        }
        k>>=1;
        A=mul(A, A);
    }
    return ret;
}
signed main (){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int xa, xb, a, b, n;
    cin>>xa>>xb>>a>>b>>n;
    matrix vc;
    vc.arr[0][0]=b;
    vc.arr[0][1]=a;
    vc.arr[1][0]=1;
    vc.arr[1][1]=0;
    vc=pow(vc, n-2);
    ll ans=(vc.arr[0][0]*xb+vc.arr[0][1]*xa)%mod;
    cout<<ans<<endl;
}
