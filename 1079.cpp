#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> tree[100001];
double P, R, amount = 0.0;
int N, t;
void dfs(int root = 0, int dep = 0){
	if(tree[root][0] < 0){
		amount = amount + P * pow(1 + R / 100.0, dep) * (-tree[root][0]);
		return;
	}
	for(auto i : tree[root])
		dfs(i, dep + 1);
}
int main(){
	scanf("%d %lf %lf", &N, &P, &R);
	for(int i = 0; i < N; i++){
		scanf("%d", &t);
		if(t == 0){
			tree[i].resize(1);
			scanf("%d", &tree[i][0]);
			tree[i][0] = -tree[i][0];
		} else {
			tree[i].resize(t);
			for(int j = 0; j < t; j++)
				scanf("%d", &tree[i][j]);
		}
	}
	dfs();
	printf("%.1f", amount);
	return 0;
}