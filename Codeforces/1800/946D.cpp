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
const ll maxn=1e3+5;
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
ll inv(ll x){
    return pw(x, mod-2);
}
int twop(string str, int val){
    int l=0, r=0, ans, n=SZ(str), sum=0;
    ans=n;
    while(l<=r&&r<n){
        while(sum<val){
            if (r>=n) break;
            sum+=str[r]-'0';             
            r++;
        }
        while(l<=r&&sum>=val){
            sum-=str[l]-'0';
            l++;
        }
        ans=min(ans, r-l+1);
    }
    return ans;
}
signed main(){
    IOS();
    int n,m,k; cin>>n>>m>>k;
    vector<string> vc(n);
    REP(i,n) cin>>vc[i];
    vector<int> S[n+1];
    REP(i,n){
        S[i].resize(m+1);
        REP(j,m+1) S[i][j]=inf;
    }
    vector<int> can(n);
    REP(i,n){
        int cnt=0;
        REP(j,m){
            cnt+=vc[i][j]-'0';
        }
        can[i]=cnt;
        REP(j,cnt+1){
            S[i][cnt-j]=twop(vc[i], j);
 
        }
    }
    vector<int> dp[n+1];
    REP(i,n+1) {
        dp[i].resize(k+1);
    }
    //REP(i,n+1) dp[0][i]=inf;
    /*REP(i,n){
        REP(j,m){
            cout<<S[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    REP1(i,n){
        dp[i][0]=dp[i-1][0]+S[i-1][0];
        REP1(j,k){
            dp[i][j]=dp[i-1][j]+S[i-1][0];
            //cout<<can[i-1]<<endl;
            REP(l,can[i-1]+1){
                if (j-l<0) break;
                //if (i==1) dp[i-1][j-l]=0; 
                dp[i][j]=min(dp[i-1][j-l]+S[i-1][l], dp[i][j]);
            }
            //cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    /*REP(i,n+1){
        REP(j,k+1){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    cout<<dp[n][k]<<endl;
 
 
}
