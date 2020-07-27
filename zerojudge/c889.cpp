#include <vector>
#include <iostream>
using namespace std;
vector <int> vt [100005];
int color[100005];  // 0 for no color, 1 for black, -1 for white
int a,b,n,m,outb;
int num_1, num_2;
bool GG = false;
void dfs (int now){
	for (int i=0; i < vt[now].size();i++){
		
		if(GG) return ;

		int next = vt[now][i];
		if (color[next]==0){
			color [next]=color[now]*(-1);
			if (color[next]==1){
				num_1++;
			}
			else {
				num_2++;
			}
			dfs (next);
		} else {
			if (color[next] == color [now]){
				GG = true;
				return ;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a>>b;
		vt[b].push_back(a);
		vt[a].push_back(b);
	}
	int outb = 0;
	for (int i =1; i <= n; i++) {
		if(color[i] == 0) {
			num_1 = num_2 = 0;
			color[i] = 1;
			num_1++;
			dfs(i);
			if (num_1>num_2){
				outb+=num_2;
			}else outb+=num_1;
			
		}
	}
	if(GG) cout << "0\n";
	else cout << outb << '\n';
		
}
