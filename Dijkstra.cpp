#include <iostream>
#include <vector>
#include <climits>
#include <conio.h>
using namespace std;

const int Max = INT_MAX;

int Dijkstra(vector< vector<int> > map, int from, int to){
	int N = map.size();
	struct vertex{
		int data;
		bool flag;
	};
	vector<vertex> dist(100, {Max, false});
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
	for(int i = 0; i < N; i++)
		cout << dist[i].data << " ";
	cout << endl;
	return dist[to].data;
}

int main(){
	int N;
	cin >> N;
	vector<int> t(N, 0);
	vector< vector<int> > map(N, t);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];
	cout << Dijkstra(map, 0, 5) << endl;
	getch();
	return 0;
}
/**
7
0 1 5 0 0 0 0
1 0 0 4 0 2 0
5 0 0 9 0 6 0
0 4 9 0 3 1 0
0 0 0 3 0 0 8
0 2 6 1 0 0 10
0 0 0 0 8 10 0
**/