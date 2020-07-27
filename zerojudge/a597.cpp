#include <iostream>
#include <queue>
using namespace std;

char mp[505][505];
int n,m,ans,ansb;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int bfs(int x, int y){
//	cout << "in bfs" << endl;
	int ans=1;
	queue<int> qx;
	queue<int> qy;
	mp [x][y]='X';
	qx.push(x);
	qy.push(y);
	while (qx.empty()==0){
		int xx = qx.front();
		int yy=qy.front ();
		qx.pop();
		qy.pop();
		for (int i=0;i<4;i++){
			int newx=xx+dx[i], newy=yy+dy[i];
			//printf("%d %d\n",newx,newy);
			if (newx>=0 && newx<=m-1 && newy<=n-1 && newy >=0 ){
				//printf("%d %d %c\n",newx,newy,mp[newx][newy]);
				if (mp [newx][newy]== 'J'){
					qx.push(newx);
					qy.push (newy);
					ans++;
					mp [newx][newy]='X';
				}
			}
		}
	
	}
	return ans;
}
void print() {
	for(int i = 0 ; i < m ; i++ )	 {
		for(int j = 0; j < n; j++)		 {
			cout << mp[i][j];
		}
		cout << endl;
	}

}
int main (){
	while (~scanf("%d %d",&m,&n)){
	
		
		ansb=0;
		for (int i=0;i<m;i++){
			/*for (int j=0;j<n;j++){
				cin>>mp[i][j];
			}*/
			scanf("%s",mp[i]);
		}
		int big=0;
		for (int i=0;i<m;i++){
			//cout<<"i"<<endl;
			for (int j=0;j<n;j++){
				//cout<<"j"<<endl;
				if (mp[i][j]=='J'){
					int k=bfs(i,j);
					if (k>big){
						big=k;
					}
				//	cout<<"pass"<<i <<j<< endl;
				//	print();
				//	cout<<"pass"<<endl;
					ansb++;
				}
			}
		
		}
		cout<<ansb<<' '<<big<<endl;
	}
}
