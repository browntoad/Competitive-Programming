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
const ll maxn=5005;
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

struct Point{
	int x; 
	int y;
	int val;
	bool type;
};
int gold[maxn][maxn], val[maxn][maxn];
vector<Point> vc;
int n,m, k;
void Discrete(){
	vector<int> Xs, Ys;
	REP(i,n+m){
		Xs.pb(vc[i].x);
		Ys.pb(vc[i].y);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	REP(i,n+m){
		vc[i].x=lower_bound(ALL(Xs), vc[i].x)-Xs.begin()+1;
		vc[i].y=lower_bound(ALL(Ys), vc[i].y)-Ys.begin()+1;

	}
}
void GPf(){
	REP(i,n){
		gold[vc[i].x][vc[i].y]=1;
	}
	REP1(i,n+m){
		REP1(j,n+m){
			gold[i][j]+=gold[i-1][j]+gold[i][j-1]-gold[i-1][j-1];
		}
	}

}
void ValPf(){
	REP(i,m+n){
		val[vc[i].x][vc[i].y]=vc[i].val;
	}
	REP1(i,n+m){
		REP1(j,n+m){
			val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
		}
	}
}
bool can(int x0, int y0, int x1, int y1){
	if (x0>x1) swap(x0, x1);
	if (y0>y1) swap(y0, y1);
	int cnt=gold[x1][y1]-gold[x0-1][y1]-gold[x1][y0-1]+gold[x0-1][y0-1];
	if (cnt>k) return 0;
	else return 1;
}
int GetVal(int x0, int y0, int x1, int y1){
	if (x0>x1) swap(x0, x1);
	if (y0>y1) swap(y0, y1);
	int cnt=val[x1][y1]-val[x0-1][y1]-val[x1][y0-1]+val[x0-1][y0-1];
	return cnt;
}
signed main(){
	IOS();
	cin>>n>>m>>k;
	REP(i,n){
		int x,y, val; cin>>x>>y>>val;
		vc.push_back({x, y, val, 1});
	}
	REP(i,m){
		int x,y, val; cin>>x>>y>>val;
		vc.push_back({x, y, val, 0});
	}
	Discrete();
	GPf();
	ValPf();
	int ans=0;
	REP(i,n+m){
		FOR(j,i,n+m){
			if (!can(vc[i].x, vc[i].y, vc[j].x, vc[j].y)) continue;
			ans=max(ans, GetVal(vc[i].x, vc[i].y, vc[j].x, vc[j].y));
		}
	}
	cout<<ans<<endl;
}
/*signed main(){
	IOS();
	int n,m,k; cin>>n>>m>>k;
	map<int, bool> X, Y, rX, rY;
	map<pii, bool> isgold, V;
	REP1(i,n+m){
		cin>>vc[i].x>>vc[i].y>>vc[i].v;
		X[vc[i].x]=1; Y[vc[i].y]=1;
		isgold[{vc[i].x, vc[i].y}]=1;
		V[{vc[i].x, vc[i].y}]=vc[i].v;
	}
	int cnt=0;
	for (auto i:X){
		cnt++;
		rX[cnt]=i.f;
		//cout<<i.f<<endl;
	}
	int N=cnt;
	cnt=0;
	for (auto i:Y){
		cnt++;
		rY[cnt]=i.f;
		//cout<<i.f<<endl;
	}
	int M=cnt;
	cout<<endl;
	REP1(i,N){
		REP1(j,M){
			gold[i][j]=gold[i][j-1]+gold[i-1][j]-gold[i-1][j-1]+(isgold[{rX[i], rY[j]}]);
			val[i][j]=val[i][j-1]+val[i-1][j]-val[i-1][j-1]+V[{rX[i], rY[j]}];
			cout<<gold[i][j]<<' '<<i<<' '<<j<<endl<<endl;
		}

	}
	int ans=0;
	REP1(i,n+m){
		int ii=rX[vc[i].x], jj=rY[vc[i].y];
		REP1(j,n+m){
			int indi=rX[vc[j].x], indj=rY[vc[j].y];
			int tnp=gold[indi][indj]+gold[ii][jj]-gold[indi][jj]-gold[ii][indj];
			if (tnp>k||tnp<0) continue;
			tnp=val[indi][indj]+val[ii][jj]-val[indi][jj]-val[ii][indj];
			if (tnp<0) continue;
			int ans=max(ans, tnp);
		}
	}
	cout<<ans<<endl;
	//sort(ALL(X)); sort(ALL(y));

}
*/
