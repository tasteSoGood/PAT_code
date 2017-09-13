#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mat[1001];
bool vis[1001];
int N, M, K, t;
void dfs(int i){
	vis[i] = true;
	for(auto it : mat[i])
		if(!vis[it])
			dfs(it);
}
int main(){
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		mat[a - 1].push_back(b - 1);
		mat[b - 1].push_back(a - 1);
	}
	for(int i = 0; i < K; i++){
		fill(vis, vis + N, false);
		cin >> t;
		int cm = 0;
		vis[t - 1] = true;//相当于删除了图中t位置的节点
		for(int i = 0; i < N; i++)
			if(!vis[i])
				dfs(i), cm++;
		cout << cm - 1 << endl;
	}
	return 0;
}