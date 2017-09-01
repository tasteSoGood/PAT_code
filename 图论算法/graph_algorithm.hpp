#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * 函数声明
 */
void DFS(Graph, int);
void DFS_inner(Graph, int, vector<bool> &);
void BFS(Graph, int);
void cnt_comp(Graph);

/**
 * 图遍历算法
 */
/*深度遍历*/
void DFS(Graph G, int v){
	vector<bool> visited(G.ver.size(), false);
	DFS_inner(G, v, visited);
}
void DFS_inner(Graph G, int v, vector<bool> &visited){
	cout << G.ver[v] << " ";
	visited[v] = true;
	for(int i = 0; i < G.ver.size(); i++)
		if(G.mat[v][i] != G.inf && !visited[i])
			DFS_inner(G, i, visited);
}/*广度遍历*/
void BFS(Graph G, int v){
	vector<bool> visited(G.ver.size(), false);
	cout << G.ver[v] << " ";
	visited[v] = true;
	queue<int> Q;
	Q.push(v);
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		for(int i = 0; i < G.ver.size(); i++)
			if(G.mat[t][i] != G.inf && !visited[i]){
				cout << G.ver[i] << " ";
				visited[i] = true;
				Q.push(i);
			}
	}
}
/*求一个图的连通分量*/
void cnt_comp(Graph G){
	vector<bool> visited(G.ver.size(), false);
	int cnt = 0;
	for(int i = 0; i < G.ver.size(); i++)
		if(visited[i] == false){
			cout << "No." << (++cnt) << " components is:" << endl;
			DFS_inner(G, i, visited);
			cout << endl;
		}
}