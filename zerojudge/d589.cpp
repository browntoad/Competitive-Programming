#include <iostream>
#include <algorithm>
using namespace std;
int main (){
	int dp[50][3];
	int n;
	while (cin>>n){
		int arr[50];
		if (n==0){
			break;
		}
		for (int i=0;i<n;i++){
			cin>>arr[i];
		}
		dp[0][0] = 0;
		dp[0][1] = arr[0];
		dp[0][2] = arr[0]*2;
		for (int i=1;i<n;i++){
			dp[i][0] =dp[i-1][2];
			dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + arr[i];
			dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + arr[i]*2;
		}
		cout<<max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]))<<endl;
	}
}
