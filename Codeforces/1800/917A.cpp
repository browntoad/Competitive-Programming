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
#define PI 3.14159265
//#define TOAD
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define bug(...)
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=5e3+5;
ll pw(ll x, ll p){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return ret;
}

ll inv(ll a, ll b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}

signed main (){
    IOS();
    string str; cin>>str;
    int n=SZ(str);
    int ans=0;
    REP(i,n){
        int l=0, r=0;
        FOR(j,i,n){
            if (str[j]=='('){
                l++;
                r++;
            }
            else if (str[j]==')'){
                r--;
                if (l<=0){
                    if (r!=1){
                        l=1;
                    }
                    else l=r;
                }
                else l--;
            }
            else {
                r++;
                if (l<=0) l++;
                else l--;
            }
            if (r<0) break;

            if (l==0){
                ans++;
            }
        }   
        //cout<<ans<<endl;

    }
    cout<<ans<<endl;
}