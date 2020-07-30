#include <bits/stdc++.h>
#define int long long
using namespace std;
string str;
int dp[20][2][2];
int dfs(int pos, bool same_prefix, bool parityof1){
	if (pos==str.size()) return !parityof1;
	if (dp[pos][same_prefix][parityof1]!=-1) return dp[pos][same_prefix][parityof1];
	int &res=dp[pos][same_prefix][parityof1];
	res=0;
	if (parityof1){
		if (same_prefix){
			if (str[pos]=='1') res+= dfs(pos+1, 1, 0);
			else if (str[pos]>'1') res+= dfs(pos+1, 0, 0);
		}
		else {
			res+= dfs(pos+1, 0, 0);
		}
		return res;
	} 
	if (same_prefix){
		for (int i=0; i<=str[pos]-'0'; i++){

			res+=dfs(pos+1, i==str[pos]-'0', i==1);
		}
	}
	else {
		for (int i=0;i<=9; i++){
			res+=dfs(pos+1, 0, i==1);
		}
	}
	return res;
}
signed main(){
	for (int i=0; i<20; i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) dp[i][j][k]=-1;
	cin>>str;
	cout<<dfs(0, 1, 0)<<endl;
}