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
#define bug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" is "<<x<<endl;
#define IOS() 
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
const ll mod = 998244353;
const ll inf=1ll<<60;
const ll maxn=100005;
 
signed main(){
    //IOS();
    int T; cin>>T;
    while (T--){
        int n, k, sum=0; cin>>k>>n;
        vector<int> vc(n), bin, cnt(maxn);
        REP(i,n){
            cin>>vc[i];
            sum+=vc[i];
            int j=log2(vc[i]);
            cnt[j]++;
        }
        if (sum<k){
            cout<<-1<<endl;
            continue;
        }
        int ans=0;
        int i=0;
        while (k>0){
            if (k&1){
                if (cnt[i]==0){
                    bug(k);
                    int cc=i;
                    FOR(j,i,31){
                        if (cnt[j]>0){
                            cnt[j]--;
                            cc=j;
                            break;
                        }
                        cnt[j]=1;
                    }
                    ans+=cc-i;
                    k>>=1;
                    i++;
                    continue;
 
                }
                cnt[i]--;
 
            }
             cnt[i+1]+=cnt[i]/2;
            i++;
            k>>=1;
            bug(k);
        }
        cout<<ans<<endl;
    }
}
/*204 6
64 16 32 32 32 64
6   4  5  5  5  6
11001100
*/