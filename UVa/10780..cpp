#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
signed main(){
	freopen("output.txt", "w", stderr);
	ios::sync_with_stdio(false), cin.tie(0);
	vector<int> f(maxn+1);
	for (int i=0;i<=maxn;i++) f[i]=i;
	for (int i=2;i<=maxn;i++){
		if (f[i]==i){
			for (int j=i*2;j<=maxn;j+=i) f[j]=min(f[j], i);
		}
	}
	int t; cin>>t;
	for (int cs=1;cs<=t;cs++){
		int n,m; cin>>m>>n;
		int ans=INT_MAX;
		while (m>1){
			int p=f[m];
			int cnt=0;
			while(m%p==0){
				m/=p;
				cnt++;
			}
			int tmp=n, cn=0;
			while(tmp>=p){
				cn+=tmp/p;
				tmp/=p;
			}
			ans=min(ans, cn/cnt);
			//cout<<cnt<<' '<<p<<endl;

		}
		cout<<"Case "<<cs<<':'<<endl;
		if (ans!=0) cout<<ans<<endl;
		else cout<<"Impossible to divide"<<endl;
	}



}