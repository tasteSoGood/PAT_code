#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int trans(char *id){
	int res = 0;
	for(int i = 0; i < 4; i++)
		res = res * 26 + id[i] - 'A';
	return res;
}
int main(){
	int N, K, cid, num;
	char s[5];
	scanf("%d %d", &N, &K);
	map<int, vector<int> > record;
	for(int i = 0; i < K; i++){
		scanf("%d %d", &cid, &num);
		for(int j = 0; j < num; j++){
			scanf("%s", s);
			record[trans(s)].push_back(cid);
		}
	}
	for(int i = 0; i < N; i++){
		scanf("%s", s);
		int t = trans(s);
		sort(record[t].begin(), record[t].end());
		printf("%s %d", s, record[t].size());
		for(vector<int>::iterator j = record[t].begin(); j != record[t].end(); j++)
			printf(" %d", *j);
		printf("\n");
	}
	return 0;
}