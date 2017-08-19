#include <iostream>
#include <vector>
using namespace std;
struct road {
	int dist;
	int cost;
};
const int inf = 10000;
void dijkstra(vector<road> &distance, vector< vector<road> > n_map, vector< vector<bool> > &edge, int from){
	vector<bool> visit(distance.size(), false);
	distance[from] = { 0, 0 };
	for(int i = 0; i < distance.size(); i++){
		int min = inf;
		for(int j = 0; j < visit.size(); j++)
			if(distance[j].dist < distance[min].dist && !visit[j])
				min = j;
		visit[min] = true;
		for(int j = 0; j < distance.size(); j++)
			if(n_map[min][j].dist != inf && !visit[j])
				if(distance[min].dist + n_map[min][j].dist < distance[j].dist){
					distance[j].dist = distance[min].dist + n_map[min][j].dist;
					edge[min][j] = false;
				}
	}
}
vector<bool> dfs_visit(510, false);
vector<int> path_record;
bool flag = false;
void dfs(vector< vector<road> > n_map, vector< vector<bool> > short_edge, int from, int to){
	dfs_visit[from] = true;
	if(from == to || flag){
		dfs_visit.push_back(from);
		flag = true;
		return;
	}
	for(int i = 0; i < n_map.size(); i++)
		if(n_map[from][i].dist != inf && short_edge[from][i] && !dfs_visit[i])
			dfs(n_map, short_edge, i, to);
}
int main(){
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	vector<road> t(N, { inf, inf });
	vector< vector<road> > road_map(N, t);
	vector<bool> s(N, false);
	vector< vector<bool> > edge_record(N, s);
	for(int i = 0; i < M; i++){
		int c1, c2, di, co;
		cin >> c1 >> c2 >> di >> co;
		road_map[c1][c2] = road_map[c2][c1] = { di, co };
		edge_record[c1][c2] = edge_record[c2][c1] = true;
	}
	dijkstra(t, road_map, edge_record, S);
	dfs(road_map, edge_record, S, D);
	cout << path_record[path_record.size() - 1];
	int total_dist = 0, total_cost = 0; 
	for(int i = path_record.size() - 2; i >= 0; i--){
		cout << " " << path_record[i];
		total_cost += road_map[i - 1][i].cost;
	}
	cout << " " << t[D].dist << " " << total_cost << endl;
	return 0;
}
/**
6 8 0 3
0 1 1 12
1 5 4 20
0 5 2 9
5 2 9 30
2 4 3 13
0 4 5 2
0 3 6 46
4 3 2 42
 */