#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct node {
	string name;
	vector<int> course;
};
bool cmp(node a, node b){ return a.name < b.name; }
int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	vector<node> record(N);
	for(int i = 0; i < N; i++){
		int t;
		char t_name[5];
		scanf("%s %d", &t_name, &t);
		record[i].name = t_name;
		record[i].course.resize(t);
		for(int j = 0; j < t; j++)
			scanf("%d", &record[i].course[j]);
	}
	sort(record.begin(), record.end(), cmp);
	vector< vector<string> > result(K);
	for(auto i : record)
		for(auto j : i.course)
			result[j - 1].push_back(i.name);
	for(int i = 0; i < K; i++){
		printf("%d %d\n", i + 1, result[i].size());
		for(auto j : result[i])
			printf("%s\n", j.c_str());
	}
	return 0;
}