#include <iostream>
using namespace std;

char map[105][105];
int n,m,ans;
int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
void dfs(int x, int y) {
	map[x][y] = '*';
	for(int i = 0; i < 8; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && nx<=n-1 && ny<=m-1 && ny >=0 ){
			if (map[nx][ny]=='@'){
				dfs (nx,ny);
			}
		}
	}
	
}

int main (){
	while (1){
	cin>>n>>m;
	ans=0;
	if (n==m&&n==0){
		break;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (map[i][j]=='@'){
				dfs(i,j);
				ans++;
			}
		}

	}
	cout<<ans<<endl;
	}
}
