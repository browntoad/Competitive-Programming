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
const ll mod = 1e9+7;
const ll maxn=1e6+5;
ll pow(ll x, ll p){
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
ll inv(ll x){
    return pow(x, mod-2);
}
bool cmp(int x, int y){
    return x>y;
}
 
signed main(){
    IOS();
    int a,b,c,d; cin>>a>>b>>c>>d;
    int st=a+b, en=b+c;
    int smal=min(b-a+1, c-b+1);
    //cout<<st<<en<<endl;
    vector<int> sf(en+2), tmp(en-st+1);
    int cnt=1;
    REP(i, en-st+1){
        tmp[i]=min(cnt, smal);
        int tm=en-st+1;
        if (tm%2){
            if (i>=tm/2) cnt--;
            else cnt++;
        }
        else {
            if (i>=tm/2) cnt--;
            else if (i!=tm/2-1) cnt++;
        }
    //cout<<tmp[i]<<' ';
    }
   // cout<<endl;
    REP(i,SZ(sf)){
        if (i==0) continue;
        sf[SZ(sf)-1-i]=sf[SZ(sf)-i];
        if (i-1<en-st+1) sf[SZ(sf)-1-i]+=tmp[i-1];
    }
 
    int ans=0;
    //REP(i,SZ(sf)) cout<<sf[i]<<' '<<i<<endl;
    FOR(i,c,d+1){
        if (i>en) break;
        ans+=sf[i+1];
    }
    cout<<ans<<endl;
 
}
 
 
