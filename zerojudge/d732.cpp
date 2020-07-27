#include <iostream>
using namespace std;
int arr[100005];
int main (){
	int n, k; cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>arr[i];	
	}
	for (int i=0;i<k;i++){
		int x; cin>>x;
		int l=0,r=n-1;
		while (1){
			int num=(l+r)/2;
			if (arr[num]==x){
				cout<<num+1<<endl;
				break;
			}
			if (arr[num]<x){
				l=num+1;
			}else if (arr[num]>x){
				r=num-1;
			}
			if (l>r){
				cout<<0<<endl;
				break;
			}
		}
	}
}
