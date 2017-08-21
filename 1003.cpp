#include <iostream>
#include <vector>
using namespace std;
const int inf = 100000, MAX = 501;
int N, M, C1, C2;
int rescue[MAX];
struct road { int weigh = inf; };
road map[MAX][MAX];
vector<int> dist(MAX, inf), path_num(MAX), ver_cnt(MAX);
void dijkstra(int start){
	dist[start] = 0;
	path_num[start] = 1;
	ver_cnt[start] = rescue[start];
	vector<bool> visit(N, false);
	for(int i = 0; i < N; i++){
		int min = MAX - 1;
		for(int i = 0; i < N; i++)
			if(dist[i] < dist[min] && !visit[i])
				min = i;
		if(min == MAX - 1)
			break;
		visit[min] = true;
		for(int i = 0; i < N; i++)
			if(map[min][i].weigh != inf && !visit[i]){
				if(dist[i] > dist[min] + map[min][i].weigh){
					dist[i] = dist[min] + map[min][i].weigh;
					path_num[i] = path_num[min];//路径计数
					ver_cnt[i] = ver_cnt[min] + rescue[i];//点权计数
				}
				else if(dist[i] == dist[min] + map[min][i].weigh){
					path_num[i] += path_num[min];
					if(ver_cnt[i] < rescue[i] + ver_cnt[min])
						ver_cnt[i] = rescue[i] + ver_cnt[min];
				}
			}
	}
}
int main(){
	cin >> N >> M >> C1 >> C2;
	for(int i = 0; i < N; i++)
		cin >> rescue[i];
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cin >> map[a][b].weigh;
		map[b][a] = map[a][b];
	}
	dijkstra(C1);
	cout << path_num[C2] << " " << ver_cnt[C2] << endl;
	return 0;
}