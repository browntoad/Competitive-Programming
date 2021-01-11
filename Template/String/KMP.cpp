#include <bits/stdc++.h>
using namespace std;
vector<int> build_fail(string &a){
    vector<int> res;
    res.push_back(0);
    int w=0;
    for (int i=1;i<a.size();i++){
        while(w>=0&&a[i]!=a[w]){
            if (!w) w=-1;
            else w=res[w-1];
        }
        w++;
        res.push_back(w);
    }
    return res;
}
int KMP(string &a, string &b){
    vector<int> f=build_fail(b);
    int w=0, ans=0;
    for (int i=0;i<a.size();i++){
        while(w>=0&&b[w]!=a[i]){
            if (!w) w=-1;
            else w=f[w-1];
        }
        w++;
        if (w==b.size()) {
            ans++;
            w=f[w-1];
        }
    }
    return ans;
}
signed main(){
    
}