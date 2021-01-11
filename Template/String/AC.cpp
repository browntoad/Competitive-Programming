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
struct Node{
	array<Node*, 26> ch;
	Node* fail;
	int cnt;
	Node(){
		fill(ALL(ch), nullptr);
		fail=nullptr;
		cnt=0;
	}
};


Node* walk(Node* ptr, char c){
	if (ptr->ch[c-'a']) return ptr->ch[c-'a'];
	return walk(ptr->fail, c);
}
struct AC{
	Node* rt;
	AC(){
		rt=new Node();
	}
	vector<Node*> nodes;

	Node* insert(const string &s){
		Node *now=rt;
		REP(i,SZ(s)){
			if (now->ch[s[i]-'a']) now=now->ch[s[i]-'a'];
			else now=now->ch[s[i]-'a']=new Node();
		}		
		return now;
	}
	void make_fail(){
		Node* star=new Node();
		REP(i,26) star->ch[i]=rt;
		rt->fail=star;
		queue<Node*> qu;
		qu.push(rt);
		while(qu.size()){
			Node* u=qu.front();
			qu.pop();
			REP(i,26){
				if (u->ch[i]){
					qu.push(u->ch[i]);
					nodes.pb(u->ch[i]);
					u->ch[i]->fail=walk(u->fail, i+'a');
				}
			}
		}
	}
	void count(const string &s){
		Node*ptr=rt;
		REP(i,SZ(s)){
			ptr=walk(ptr, s[i]);
			ptr->cnt++;
		}
		RREP(i,SZ(nodes)){
			nodes[i]->fail->cnt+=nodes[i]->cnt;
		}
	}
};
vector<int> match(const string &s, const vector<string>& targets){
	AC ac;
	vector<Node*> link;
	REP(i,SZ(targets)){
		link.pb(ac.insert(targets[i]));
	}
	vector<int> res;
	ac.make_fail();
	ac.count(s);
	for (auto i:link){
		res.pb(i->cnt);
	}
	return res;
}

signed main(){
	IOS();
}