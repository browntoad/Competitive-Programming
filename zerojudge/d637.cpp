#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    while (cin>>n){
        vector<pair<int, int> > vc(n);
        for (int i=0;i<n;i++){
            cin>>vc[i].first>>vc[i].second;
        }
        vector<int> dp(105);
        for (int i=0;i<n;i++){
            for (int j=100; j>=1; j--){
                if (j<vc[i].first) break;
                dp[j]=max(dp[j-vc[i].first]+vc[i].second, dp[j]);
            }
        }
        cout<<dp[100]<<endl;
    }
}
