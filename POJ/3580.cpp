#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
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
#define nullptr NULL
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
//const double PI=acos(-1);
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

struct Treap{
	int val;
	int pri;
	int mn;
	int sz;
	int ad;
	int sm;
	bool rev;
	Treap *l, *r;
	Treap(int x=0){
		val=x;
		mn=x;
		sz=1;
		ad=0;
		pri=rand();
		rev=false;
		l=r=nullptr;
		sm=x;
	}
	friend int min(Treap *t){
		if (t==nullptr) return inf;
		return t->mn;
	}
	friend int size(Treap *t){
		if (t==nullptr) return 0;
		return t->sz;
	}
	friend int sum(Treap *t){
		if (t==nullptr) return 0;
		return t->sm;
	}
	void pull(){
		sz=size(l)+size(r)+1;
		mn=min(min(min(l), min(r)), val);
		sm=sum(l)+sum(r)+val;
	}
	void push(){
		if (rev){
			swap(l,r);
			if (l) l->rev^=1;
			if (r) r->rev^=1;
			rev=0;
		}
		if (l) {
			l->ad+=ad;
			l->mn+=ad;
			l->val+=ad;
			l->sm+=ad*sz;
		}
		if (r){
			r->ad+=ad;
			r->mn+=ad;
			r->val+=ad;
			l->sm+=ad*sz;
		} 
		ad=0;

	}

};
Treap* merge(Treap*a, Treap*b){
	if (a==nullptr) return b;
	if (b==nullptr) return a;
	if (a->pri>b->pri){
		a->push();
		a->r=merge(a->r, b);
		a->pull();
		return a;
	}
	else {
		b->push();
		b->l=merge(a, b->l);
		b->pull();
		return b;
	}
}


void split(Treap*t, int k, Treap*& a, Treap*& b){
	if (t==nullptr){
		a=b=nullptr;
		return;
	}
	t->push();
	if (size(t->l)+1<=k){
		a=t;
		split(t->r, k-size(t->l)-1, a->r, b);
		a->pull();
	}
	else {
		b=t;
		split(t->l, k, a, b->l);
		b->pull();
	}
}

signed main(){
	IOS();
	srand(35576);
	Treap *rt=nullptr;
	int n; cin>>n;
	REP(i,n) {
		int x; cin>>x;
		rt=merge(rt, new Treap(x));
	}
	int q; cin>>q;
	while(q--){
		string cmd; cin>>cmd;
		if (cmd=="INSERT"){
			int x,P; cin>>x>>P;
			Treap* a,*b;
			split(rt, x,a,b);
			rt=merge(merge(a,new Treap(P)),b);

		}
		if (cmd=="DELETE"){
			int x; cin>>x;
			Treap *a, *b, *trash;
			split(rt, x, a, b);
			split(a,x-1, a, trash);
			rt=merge(a,b);
		}
		if (cmd=="MIN"){
			int l,r; cin>>l>>r;
			Treap *a, *b, *c;
			split(rt, l-1, a,b);
			split(b, r-l+1, b,c);
			cout<<min(b)<<endl;
			b=merge(a,b);
			rt=merge(b,c);
		}
		if (cmd=="REVOLVE"){
			int l,r,T; cin>>l>>r>>T;
			T%=r-l+1;
			Treap *a, *b, *c, *d;
			split(rt, r, c, d);
			split(c, l-1, a, b);
			split(b, r-l+1-T, b, c);
			c=merge(a,c);
			b=merge(c,b);
			rt=merge(b,d);
		}
		if (cmd=="REVERSE"){
			int l,r; cin>>l>>r;
			Treap *a, *b, *c;
			split(rt, l-1, a,b);
			split(b, r-l+1, b,c);
			b->rev^=1;
			b=merge(a,b);
			rt=merge(b,c);
		}
		if (cmd=="ADD"){
			int l,r,D; cin>>l>>r>>D;
			Treap *a, *b, *c;
			split(rt, l-1, a,b);
			split(b, r-l+1, b,c);
			b->ad+=D;
			b->mn+=D;
			b->val+=D;
			b->sm+=D*size(b);
			b=merge(a,b);
			rt=merge(b,c);
		}
	}

}
