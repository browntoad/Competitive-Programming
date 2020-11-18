#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long 
#define int ll
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pb push_back
#define f first
#define s second
#define pii pair<int, int>
#define pdd pair<double, double>
//#define TOAD
#ifdef TOAD
#define IOS() 
#define bug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" is "<<x<<endl
#else 
#define IOS() ios::sync_with_stdio(false), cin.tie(0);
#define bug(x)
#endif
 
const ll inf=(1ll<<60);
const double PI=acos(-1);
const int maxn=1e6+5;
const int iinf=2147483647;
const ll mod=1e9+7;
 
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while(p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
ll inv(ll a, ll m=mod){
    return pw(a,m-2);
}
 
signed main(){
    int n,k,p; cin>>n>>k>>p;
    k=min(k,n);
    p=min(p,n);
    vector<int> lug(n), pep(n);
    REP(i,n) cin>>lug[i];
    REP(i,n) cin>>pep[i];
    int l=0, r=0;
    map<int, int> oth; // for lug
    map<int, int> mp; //for pep
    int cntl=0, cntr=0;
    bool die=false;
    while(!die){
        die=true;
        while(l<n&&cntl<k){
            die=false;
            oth[lug[l]]=1;
            if (mp[lug[l]]) {
                cntl--;
                cntr--;
            }
            l++;
            cntl++;
        }
        while(r<n&&cntr<p){
            die=false;
            mp[pep[r]]=1;
            if (oth[pep[r]]) {
                cntl--;
                cntr--;
            }
            r++;
            cntr++;
        }

    }
    if (l==r&&r==n){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    //int clv=0;
    /*
    REP(i,p){
        mp[pep[i]]=1;
    }
    int curp=p;
    bool ooofed=false;
    REP(i,n){
        if (clv>=k){
            ooofed=true;
            break;
        }
        if (!mp[lug[i]]){
            clv++;
            oth[lug[i]]=1;
        }
        else {
            while(curp<n&&oth[pep[curp]]){
                clv--;
                curp++;
            }
            if (curp<n){
                mp[pep[curp]]=1;
                curp++;
            }

        }
        
    }
    */
    
    

}