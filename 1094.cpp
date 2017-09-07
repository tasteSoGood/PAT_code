#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int N, M, pos, t;
	cin >> N >> M;
	vector< vector<int> > gene(N + 1);
	vector<int> record(N + 1, 0), result(10, 0);
	queue<int> q;
	for(int i = 0; i < M; i++){
		cin >> pos >> t;
		gene[pos].resize(t);
		for(int j = 0; j < t; j++)
			cin >> gene[pos][j];
	}
	record[1] = 1;
	int tag = 1, cnt, max, max_tag;
	q.push(1);
	result[1]++;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i = 0; i < gene[temp].size(); i++){
			record[gene[temp][i]] = record[temp] + 1;
			result[record[temp] + 1]++;
			q.push(gene[temp][i]);
		}
	}
	tag = 0, max = 0;
	for(int i = 1; i < result.size(); i++)
		if(result[i] > max)
			max = result[i], tag = i;
	cout << max << " " << tag << endl;
	return 0;
}