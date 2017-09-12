#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int main(){
	int N, K, M, t, a, b;
	scanf("%d", &N);
	vector< set<int> > record(N);
	for(int i = 0; i < N; i++){
		scanf("%d", &M);
		for(int j = 0; j < M; j++){
			scanf("%d", &t);
			record[i].insert(t);
		}
	}
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d", &a, &b);
		float n_t = 0, n_c = 0;
		for(auto it : record[a - 1])
			if(record[b - 1].count(it))
				n_c++;
		n_t = record[a - 1].size() + record[b - 1].size() - n_c;//并 = 和 - 交
		printf("%.1f%\n", n_c / n_t * 100);
	}
	return 0;
}
/**
 * 哈哈哈哈哈，特么的函数调用还有时间差，就不让过
 * 这里不能把similarity()函数放在外面，这样最后一个测试点肯定过不了
 */