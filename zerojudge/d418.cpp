#include <iostream>
#include <stack>
using namespace std;
int main (){
	stack <int> ar;
	int n; cin>>n;
	for (int i=0;i<n;i++){
		int a; cin>>a;
		if (a<10){
			cout<<a<<endl;
		}else {
			for (int j=9;j>1;j--){
				while (a%j==0){
					a=a/j;
					ar.push(j);
				}
			}
			if (a!=1){
				cout<<"-1"<<endl;
				while (!ar.empty()){
					ar.pop();
				}
				continue;
			}
			while (!ar.empty()){
				cout<<ar.top();
				ar.pop();
			}
			cout<<endl;
		}
	}	
}
