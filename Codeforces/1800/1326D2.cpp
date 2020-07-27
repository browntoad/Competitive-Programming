#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast", "unroll-loops")
using namespace std;
#define ll long long
//#define int ll
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
const ll maxn=20;
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
string LPS(string in){
    string tmp=in+'$';
    reverse(ALL(in));
    tmp+=in;
    int k=SZ(tmp);
    vector<int> lps(k);
    REP1(i,k){
        int len=lps[i-1];
        while (len>0&&tmp[len]!=tmp[i]){
            len=lps[len-1];
        }
        if (tmp[i]==tmp[len]) len++;
        lps[i]=len;
 
    }
    return tmp.substr(0,lps[k-1]);
}
signed main(){
    IOS();
    int T; cin>>T;
    while (T--){
        string str; cin>>str;
        string a="",b="";
        int n=SZ(str);
        int l=0, r=n-1;
        REP(i,n/2+(n%2)){
            if (str[i]==str[n-i-1]) {
                a+=str[i];
                if (n%2!=1||i!=n/2) b+=str[i];
            }
            else break;
            l++;
            if (n%2!=1||i!=n/2) r--;
        }
        reverse(ALL(b));
        string nw=str.substr(l,r-l+1);
        string c=LPS(nw);
        reverse(ALL(nw));
        string d=LPS(nw);
        if (SZ(c)>SZ(d)){
            cout<<a+c+b<<endl;
        }
        else {
            cout<<a+d+b<<endl;
        }
        
 
    }
}
