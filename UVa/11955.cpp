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
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=2e5+5;
const double PI=acos(-1);
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
signed main(){
	IOS();
	int T; cin>>T;
	REP(cs, T){
		string input, a,b, num;
		cin>>input;
		bool p=false;
		int val; 
		REP(i,SZ(input)){
			if (input[i]=='+') p=true;
			else if (input[i]<='z'&&input[i]>='a'){
				if (p){
					b+=input[i];
				}
				else a+=input[i];
			}
			else if (input[i]=='('||input[i]==')')
			{

			}
			else if (input[i]!='^'){
				num+=input[i];
			}
		}
		val=stoi(num);
		vector<int> C(val+1);
		C[0]=1;
		REP1(i,val){
			C[i]=C[i-1]*(val-i+1)/i;
		}
		cout<<"Case "<<cs+1<<": ";
		REP(i,val+1){
			if (i!=0) cout<<'+';

			int co=C[i];
			if (co!=1){
				cout<<co<<'*';
			}
			if (i==0){
				cout<<a;
				if (val>1) cout<<'^'<<val; 
				bug(i);
			}
			else if (i==val){
				cout<<b;
				if (val>1) cout<<'^'<<val; 
				bug(i);
			}
			else {
				int pa=val-i, pb=i;
				cout<<a;
				if (pa>1) cout<<'^'<<pa;
				cout<<'*';
				cout<<b;
				if (pb>1) cout<<'^'<<pb;
			}
		}
		cout<<endl;
	}
}
