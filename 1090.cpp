#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int deep = 0, num = 0;
vector<int> tree[100001];//这里如果用vector< vector<int> > 会出现一大堆错误
void dfs_deep(int root, int dep = 0){
	if(tree[root].size() == 0){
		if(dep > deep)
			deep = dep;
		return;
	}
	for(auto it : tree[root])
		dfs_deep(it, dep + 1);
}
void dfs_num(int root, int dep = 0){
	if(tree[root].size() == 0 && dep == deep){
		num++;
		return;
	}
	for(auto it : tree[root])
		dfs_num(it, dep + 1);
}
int main(){
	int N, t, root;
	double P, r;
	scanf("%d %lf %lf", &N, &P, &r);
	for(int i = 0; i < N; i++){
		scanf("%d", &t);
		if(t == -1) root = i;
		else tree[t].push_back(i);
	}
	dfs_deep(root);
	dfs_num(root);
	printf("%.2lf %d", pow(1 + r / 100.0, deep) * P, num);
	return 0;
}