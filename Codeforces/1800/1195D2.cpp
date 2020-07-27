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
int st(string x){
  int sz=SZ(x);
  int ret=0, ten=1;
  RREP(i,sz){
    ret+=(x[i]-'0')*ten;
    ten*=10;
    ten%=mod;
    ret%=mod;
  }
  return ret%mod;
}
bool cmp(string x, string y){
    return stoll(x)>stoll(y);
}
string rep(string in){
     string k;
    for (int j=0; j<(int)(in.size()); j++){
        k+=in[j];
        k+=in[j];
    }
 
    return k;
}
 
signed main(){
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n; cin>>n;
    vector<string> vc(n);
    for (int i=0;i<n;i++){
        cin>>vc[i];
    }
    sort(vc.begin(), vc.end(), cmp);
    vector<int> val(15);
    int ans=0;
    for (int i=0; i<n; i++){
        ans+=st(rep(vc[i]))*(i);
        ans%=mod;
        string tmp=vc[i], tmp2;
        for (int j=vc[i].size()-1; j>=0; j--){
            tmp2=vc[i][j]+tmp2;
            int asdf=0;
            int ad=st(rep(tmp2));
            asdf+=ad;
            asdf%=mod;
            tmp[j]='0';
            tmp+='0';
            ad=st(tmp);
            ad*=2;
            ad%=mod;
            asdf+=ad;
            asdf%=mod;
            val[vc[i].size()-j-1]+=asdf;
            //cout<<asdf<<' '<<tmp<<endl;
        }
        ans+=val[vc[i].size()-1];
        ans%=mod;
 
    }
    cout<<ans%mod<<endl;
    return 0;
}
