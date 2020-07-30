#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
int dp[20][2][2];
int dfs(int pos, bool same_prefix, bool previs1){
	if (pos==str.size()) return 1;
	if (dp[pos][same_prefix][previs1]!=-1) return dp[pos][same_prefix][previs1];
	int res=0;
	if (same_prefix){
		for (int i=0; i<=str[pos]-'0'; i++){
			if (previs1&&i==1) continue;
			res+=dfs(pos+1, i==str[pos]-'0', i==1);
		}
	}
	else {
		for (int i=0;i<=9; i++){
			if (previs1&&i==1) continue;
			res+=dfs(pos+1, 0, i==1);
		}
	}
	return dp[pos][same_prefix][previs1]=res;
}
signed main(){
	for (int i=0; i<20; i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) dp[i][j][k]=-1;
	cin>>str;
	cout<<dfs(0, 1, 0)<<endl;
}