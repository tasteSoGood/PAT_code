#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct node {
	int id, score;
	char name[10];
};
int main(){
	int N, col;
	scanf("%d %d", &N, &col);
	vector<node> record(N);
	for(int i = 0; i < N; i++)
		scanf("%d %s %d", &record[i].id, &record[i].name, &record[i].score);
	if(col == 1)
		sort(record.begin(), record.end(), [](node a, node b){return a.id <= b.id;});
	else if(col == 2)
		sort(record.begin(), record.end(), [](node a, node b){return strcmp(a.name, b.name) <= 0;});
	else
		sort(record.begin(), record.end(), [](node a, node b){return a.score <= b.score;});
	for(auto i = record.begin(); i != record.end(); i++)
		printf("%06d %s %d\n", (*i).id, (*i).name, (*i).score);
	return 0;
}
/**
 * 注意：在涉及到速度方面，printf的高效输出 和 string速度较慢 这两个因素可能会起到决定性作用
 */