#include <iostream>
#include <queue>

using namespace std;

int map[105][105];
int n,m,ans,ansb,abc,abd;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};


int bfs(int x, int y){
	queue<int> quex;
	queue<int> quey;
	ansb=map[x][y];
	map [x][y]=0;
	quex.push(x);
	quey.push(y);
	while (quex.empty()==0){
		int xx = quex.front();
		int yy=quey.front ();
		quex.pop();
		quey.pop();
		for (int i=0;i<4;i++){
			int nx=xx+dx[i], ny=yy+dy[i];
			if (nx>=0 && nx<=n-1 && ny<=m-1 && ny >=0 ){
				if (map [nx][ny]!= 0){
					quex.push(nx);
					quey.push (ny);
					ansb=ansb+map[nx][ny];
					map [nx][ny]=0;
				}
			}
		}
	}
	return ansb;
}

int main (){
	while(cin>>n>>m){
		ans=0;
		abd=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>map[i][j];
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (map[i][j]!=0){
					abc=bfs(i,j);
					ans++;
					if (abc>abd){
						abd=abc;
					}
				}
			}
	
		}
		cout<<ans<<endl;
		cout<<abd<<endl;
	}
}
