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

struct Treap{
	int key;
	int pri;
	int h;
	int sz;
	Treap *l, *r;
	Treap(int x=0){
		key=x;
		h=1;
		sz=1;
		pri=rand();
		l=r=nullptr;
	}
	friend int height(Treap *t){
		if (t==nullptr) return 0;
		return t->h;
	}
	friend int size(Treap *t){
		if (t==nullptr) return 0;
		return t->sz;
	}
	void pull(){
		h=max(height(l), height(r))+1;
		sz=size(l)+size(r)+1;
	}

};
Treap* Merge(Treap*a, Treap*b){
	if (a==nullptr) return b;
	if (b==nullptr) return a;
	if (a->pri>b->pri){
		a->r=Merge(a->r, b);
		a->pull();
		return a;
	}
	else {
		b->l=Merge(a, b->l);
		b->pull();
		return b;
	}
}

void Split(Treap*t, int k, Treap*& a, Treap*& b){
	if (t==nullptr){
		a=b=nullptr;
		return;
	}
	if (a->key<=k){
		a=t;
		Split(t->r, k, a->r, b);
		a->pull();
	}
	else {
		b=t;
		Split(t->l, k, a, b->l);
		b->pull();
	}
}
void Splitbysz(Treap*t, int k, Treap*& a, Treap*& b){
	if (t==nullptr){
		a=b=nullptr;
		return;
	}
	if (size(t->l)+1<=k){
		a=t;
		Splitbysz(t->r, k-size(t->l)-1, a->r, b);
		a->pull();
	}
	else {
		b=t;
		Splitbysz(t->l, k, a, b->l);
		b->pull();
	}
}
/*void print(Treap*root){
	if (root==nullptr) return;
	print(root->l);
	cout<<root->key<<' ';
	print(root->r);

}
int depth(Treap*root){
	if (root==nullptr) return 0;
	return max(depth(root->l), depth(root->r))+1;
}
*/
signed main(){
	IOS();
	srand(clock());
	/*Treap* rt=nullptr;
	REP1(i,1000000){
		rt=Merge(rt, new Treap(i));
	}
	//print(rt);
	cout<<depth(rt)<<endl;
	cout<<height(rt)<<endl;
	cout<<size(rt)<<endl;
	*/
}
