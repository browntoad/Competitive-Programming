#include <bits/stdc++.h>
using namespace std;

signed main(){
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        int n=str.size();
        int sum=0; bool ok=false;
        for (int i=0;i<n;i++) sum+=str[i]-'0';
        if (n==1) {
            cout<<'S'<<endl;
            continue;
        }
        for (int i=0;i<n;i++) {
            if ((sum-(str[i]-'0'))%3==0) ok=true;
        }        
        bool ans=n%2;
        if (ok) ans^=1;
        if (ans) cout<<'T'<<endl;
        else cout<<'S'<<endl;
    }
}