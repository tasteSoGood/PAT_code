#include <iostream>
#include <vector>
using namespace std;
const int inf = 100000, MAX = 501;
int N, M, C1, C2;
int rescue[MAX];//点权
struct road { int weight = inf; };
road map[MAX][MAX];
vector<int> dist(MAX, inf), path_cnt(MAX, 0), ver_cnt(MAX, 0);
void dijkstra(int start){
	vector<bool> visit(N, false);
	dist[start] = 0;
	path_cnt[start] = 1;
	ver_cnt[start] = rescue[start];
	for(int i = 0; i < N; i++){
		int min = MAX - 1;
		for(int j = 0; j < N; j++)
			if(dist[j] < dist[min] && !visit[j])
				min = j;
		if(min == MAX - 1)
			break;
		visit[min] = true;
		for(int j = 0; j < N; j++)
			if(dist[j] > dist[min] + map[min][j].weight){
				dist[j] = dist[min] + map[min][j].weight;
				path_cnt[j] = path_cnt[min];
				ver_cnt[j] = ver_cnt[min] + rescue[j];
			}
			else if(dist[j] == dist[min] + map[min][j].weight){
				path_cnt[j] += path_cnt[min];
				if(ver_cnt[j] < ver_cnt[min] + rescue[j])
					ver_cnt[j] = ver_cnt[min] + rescue[j];
			}
	}
}
int main(){
	cin >> N >> M >> C1 >> C2;
	for(int i = 0; i < N; i++)
		cin >> rescue[i];
	for(int i = 0; i < M; i++){
		int a, b, t;
		cin >> a >> b >> t;
		map[b][a].weight = map[a][b].weight = t;
	}
	dijkstra(C1);
	cout << path_cnt[C2] << " " << ver_cnt[C2] << endl;
	return 0;
}