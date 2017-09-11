#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct node { int id, score; };
bool cmp(node a, node b){ return a.score > b.score; }
int main(){
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	vector<int> ques(K);
	map<int, vector<int> > m;
	for(int i = 0; i < K; i++)
		scanf("%d", &ques[i]);
	for(int i = 0; i < M; i++){
		int id, a, b;
		scanf("%d %d %d", &id, &a, &b);
		if(!m[id].size()){
			m[id].resize(K + 1, -1);
			m[id][0] = 0;
		}
		if(b != -1){
			int t = m[id][a];
			if(t < b && t != -1)
				m[id][a] = b, m[id][0] = m[id][0] - t + b;
			else if(t < b && t == -1)
				m[id][a] = b, m[id][0] += b;
		}
	}
	vector<node> temp;
	for(auto it : m)
		if(it.second[0])
			temp.push_back({ it.first, it.second[0] });
	sort(temp.begin(), temp.end(), cmp);
	int cnt = 1, pre = m[temp[0].id][0];
	for(int it = 0; it < temp.size(); it++){
		if(m[temp[it].id][0] == pre)
			printf("%d ", cnt);
		else{
			pre = m[temp[it].id][0];
			printf("%d ", ++cnt);
		}
		printf("%05d", temp[it].id);
		for(int i = 0; i < K + 1; i++){
			if(m[temp[it].id][i] != -1)
				printf(" %d", m[temp[it].id][i]);
			else
				printf(" -");
		}
		printf("\n");
	}
	return 0;
}