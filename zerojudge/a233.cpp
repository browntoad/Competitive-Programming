#include <iostream>
using namespace std;
int arr[1000000];
int tmp[1000000];
void merge (int x, int y){
	if (x==y){
		return;
	}
	int m=(x+y)/2;
	merge(x,m);
	merge(m+1,y);
	int ha=x,hb=m+1;
	int tb=x;
	while (ha!=m+1&&hb!=y+1){
		if (arr[ha]>arr[hb]){
			tmp[tb++]=arr[hb++];
		}else {
			tmp[tb++]=arr[ha++];
		}
	}
	while (ha!=m+1) tmp[tb++]=arr[ha++];
	while (hb!=y+1) tmp[tb++]=arr[hb++];
	for (int i=x;i<=y;i++){
		arr[i]=tmp[i];
	}

}
int main (){
	int n; cin>>n;
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	merge(0,n-1);
	for (int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}
