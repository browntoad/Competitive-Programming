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
const ll mod = 1e9+7;
const ll maxn=1e5+5;
bool cmp(pii x, pii y){
    return x.s<y.s;
}
struct BIT{
    vector<int> vc;
    BIT(){
        vc.resize(maxn);
    }
    void MO(int pos, int val){
        while (pos<maxn){
             vc[pos]+=val;
             pos+=pos&(-pos);
        }
    }
    int QU(int pos){
        int ret=0;
        while (pos>0){
            ret+=vc[pos];
            pos-=pos&(-pos);
        }
        return ret;
    }

};
void go(){

    int n; 
    if( !(cin>>n) ) exit(0);
    vector<pii> vc(n);
    REP(i,n) {
        cin>>vc[i].f;
        vc[i].s=i+1;
    }
    sort(ALL(vc));
    REP(i,n){
        vc[i].f=i+1;
    }
    BIT bit;
    sort(ALL(vc), cmp);
    /*cout<<endl;
    REP(i,n) cout<<vc[i].f<<endl;
    cout<<endl;
    */
    REP(i,n){
        int fron=bit.QU(vc[i].f);
        cout<<i-fron+1<<endl;
        bit.MO(vc[i].f, 1);
    }

}
signed main(){
    IOS();
    while(1) go();


}


/*
6
0 0
0 2
2 0
1 1
2 2
0 3
*/
