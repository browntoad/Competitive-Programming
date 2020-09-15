#include <bits/stdc++.h>
#define ll long long 
#pragma GCC optimize("Ofast", "unroll-loops")
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define pii pair<int,int>
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define ull unsigned ll 
#define pb push_back
#define f first 
#define s second
using namespace std;
int arr[100005];
int dp[100005];
int main (){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin>>n;
	REP(i,n) cin>>arr[i];
	dp[0]=0;
	dp[1]=abs(arr[0]-arr[1]);
	FOR(i,2,n) {
		int a=abs(arr[i-2]-arr[i]);
		int b=abs(arr[i-1]-arr[i]);
		dp[i]=min(dp[i-2]+a,dp[i-1]+b);
	}
	cout<<dp[n-1]<<endl;
}