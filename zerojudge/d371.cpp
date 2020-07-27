#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main (){
	priority_queue <int, vector<int>, greater<int> > pq;
	int n; cin>>n;
	int sum=0;
	for (int i=0;i<n;i++){
		int a; cin>>a;
		pq.push(a);
	}
	while (pq.size()>=2){
		int top=pq.top();
		pq.pop();
		int topb=pq.top();
		pq.pop();
		sum+=top+topb;
		pq.push(top+topb);
	}
	cout<<sum<<endl;
}
