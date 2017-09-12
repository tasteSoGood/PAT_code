#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct node { int id, score, weight;};
bool cmp(node a, node b){ return a.score != b.score ? a.score > b.score : (a.weight != b.weight ? a.weight > b.weight : a.id < b.id); }
int main(){
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	vector<int> ques(K + 1);
	map<int, vector<int> > m;
	for(int i = 1; i <= K; i++)
		scanf("%d", &ques[i]);
	for(int i = 0; i < M; i++){
		int id, a, b;
		scanf("%d %d %d", &id, &a, &b);
		if(!m[id].size()){
			m[id].resize(K + 3, -1);
			m[id][0] = 0;//记录总分
			m[id][K + 1] = 0;//记录权重
			m[id][K + 2] = 0;//记录是否有效
		}
		m[id][a] = (m[id][a] > b ? m[id][a] : b);
		if(b != -1)
			m[id][K + 2] = 1;
		else if(m[id][a] == -1)
			m[id][a] = -2;
	}
	for(map<int, vector<int> >::iterator it = m.begin(); it != m.end(); it++)
		for(int i = 1; i <= K; i++){
			if(it->second[i] != -1 && it->second[i] != -2)
				it->second[0] += it->second[i];
			if(it->second[i] == ques[i])
				it->second[K + 1]++;
		}
	vector<node> temp;
	for(auto it : m)
		if(it.second[K + 2])
			temp.push_back({ it.first, it.second[0], it.second[K + 1] });
	sort(temp.begin(), temp.end(), cmp);
	int cnt = 1, pre = m[temp[0].id][0];
	for(int it = 0; it < temp.size(); it++){
		if(m[temp[it].id][0] == pre)
			printf("%d ", cnt);
		else{
			pre = m[temp[it].id][0], cnt = it + 1;
			printf("%d ", cnt);
		}
		printf("%05d", temp[it].id);
		for(int i = 0; i < K + 1; i++){
			if(m[temp[it].id][i] != -1 && m[temp[it].id][i] != -2)
				printf(" %d", m[temp[it].id][i]);
			else if(m[temp[it].id][i] == -1)
				printf(" -");
			else
				printf(" 0");
		}
		printf("\n");
	}
	return 0;
}