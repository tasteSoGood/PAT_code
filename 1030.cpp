#include <iostream>
#include <vector>
using namespace std;
const int inf = 100000;
const int MAX = 501;
int N, M, S, D;//题目所给的信息
struct road {
	int length = inf;
	int cost;
};//用结构体存储两权值信息
road edge[MAX][MAX];//权值邻接表
vector<int> dist(MAX, inf);
vector<int> dijk[MAX];//dijkstra需要更改的邻接链表（向量数组）
vector<int> temppath, path;//供DFS使用
void dijkstra(int start){
	vector<bool> visit(MAX, false);
	dist[start] = 0;
	for(int i = 0; i < N; i++){
		int min = MAX - 1;
		for(int i = 0; i < N; i++)
			if(dist[i] < dist[min] && !visit[i])
				min = i;
		if(min == MAX - 1)
			break;
		visit[min] = true;
		for(int i = 0; i < N; i++)
			if(edge[min][i].length != inf && !visit[i]){
				if(dist[i] > dist[min] + edge[min][i].length){
					dist[i] = dist[min] + edge[min][i].length;
					dijk[i].clear();
					dijk[i].push_back(min);
				}else if(dist[i] == dist[min] + edge[min][i].length)
					dijk[i].push_back(min);
			}
	}
}
int min_cost = inf;
void DFS(int node){
	if(node == S){
		temppath.push_back(node);
		int cost_cnt = 0;
		for(int i = temppath.size() - 1; i > 0; i--)
			cost_cnt += edge[temppath[i]][temppath[i - 1]].cost;
		if(cost_cnt < min_cost)
			min_cost = cost_cnt, path = temppath;
		temppath.pop_back();
		return;
	}
	temppath.push_back(node);
	for(int i = 0; i < dijk[node].size(); i++)
		DFS(dijk[node][i]);
	temppath.pop_back();
}
/**
 * 注释：这里的DFS必须从D到S回溯，反向并不能得到预期的结果。
 * 现在能给出的解释是，从D开始回溯能直接回溯到S（因为Djikstra
 * 会得到一棵最短路径树————当然，题目中会存在权值相同的简单环
 * 路————从叶子开始回溯可以最快得到需要的路径）
 */
int main(){
	cin >> N >> M >> S >> D;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cin >> edge[a][b].length >> edge[a][b].cost;
		edge[b][a] = edge[a][b];
	}
	dijkstra(S);
	DFS(D);
	for(int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << dist[D] << " " << min_cost << endl;
	return 0;
}