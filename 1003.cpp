#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <conio.h>
using namespace std;

const int Max = INT_MAX;

int Dijkstra(vector< vector<int> > map, int from, int to){
	//Dijkstra
	int N = map.size();
	struct vertex{
		int data;
		bool flag;
	};
	vector<vertex> dist(N, {Max, false});
	vector<int> V;
	V.push_back(from);
	dist[from] = { 0, true };
	while(V.size() <= N){
		int min = Max, min_pos = from;
		for(int i = 0; i < V.size(); i++){
			for(int j = 0; j < N; j++){
				if(map[V[i]][j] == 0 || dist[j].flag)
					continue;
				int temp = dist[V[i]].data + map[V[i]][j];;
				if(temp < dist[j].data)
					dist[j].data = temp;
				if(dist[j].data < min)
					min = dist[j].data, min_pos = j;
			}
		}
		if(min_pos != from)
			dist[min_pos] = { min, true };
		V.push_back(min_pos);
	}
	return dist[to].data;
}

int main(){
	int N, M, C1, C2, row, col;
	cin >> N >> M >> C1 >> C2;
	vector<int> rescue(N, 0);
	vector< vector<int> > map(N, rescue);
	for(int i = 0; i < N; i++)
		cin >> rescue[i];
	for(int i = 0; i < M; i++){
		cin >> row >> col;
		cin >> map[row][col];
	}
	int max = Dijkstra(map, C1, C2);
	cout << max << endl;
	getch();
	return 0;
}