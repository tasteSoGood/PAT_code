#include <iostream>
#include <vector>
using namespace std;
void dfs(int n, vector< vector<int> > &edge, vector<bool> &visit){
	visit[n] = true;
	for(auto i = edge[n].begin(); i != edge[n].end(); i++)
		if(!visit[*i])
			dfs(*i, edge, visit);
}
int deep(int n, vector< vector<int> > &edge, vector<bool> &visit){
	if(edge[n].size() == 0)
		return 1;
	int max = 0;
	visit[n] = true;
	for(auto i = edge[n].begin(); i != edge[n].end(); i++)
		if(!visit[*i]){
			int t = deep(*i, edge, visit);
			if(t > max)
				max = t;
		}
	return 1 + max;
}
int main(){
	int N, a, b;
	cin >> N;
	vector< vector<int> > edge(N);
	vector<bool> visit(N, false);
	vector<int> root(N, 0);
	for(int i = 0; i < N - 1; i++){
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}
	int cnt = 0;
	for(int i = 0; i < edge.size(); i++)
		if(!visit[i]){
			cnt++;
			dfs(i, edge, visit);
		}
	if(cnt > 1)
		cout << "Error: " << cnt << " components" << endl;
	else{
		for(int i = 0; i < edge.size(); i++){
			fill(visit.begin(), visit.end(), false);
			root[i] = deep(i, edge, visit);
		}
		int max = 0;
		for(int i = 0; i < edge.size(); i++)
			if(root[i] > max)
				max = root[i];
		for(int i = 0; i < edge.size(); i++)
			if(root[i] == max)
				cout << i + 1 << endl;
	}
	return 0;
}