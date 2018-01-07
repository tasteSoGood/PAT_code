#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
vector< vector<int> > mat;
int deep = 100000, cnt = 0;
void dfs(int root, int dep, bool flag) {
	if(mat[root].size() == 0){
		if(dep < deep && flag)
			deep = dep;
		if(dep == deep && !flag)
			cnt++;
		return;
	}
	for(int i = 0; i < mat[root].size(); i++)
		dfs(mat[root][i], dep + 1, flag);
}
int main(){
	int n, t_row;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	vector<int> t;
	mat.resize(n, t);
	for(int i = 0; i < n; i++){
		scanf("%d", &t_row);
		mat[i].resize(t_row);
		for(int j = 0; j < t_row; j++)
			scanf("%d", &mat[i][j]);
	}
	dfs(0, 0, true), dfs(0, 0, false);
	printf("%.4f %d\n", p * pow(r / 100 + 1, deep), cnt);
	return 0;
}
/*浮点数据类型要设为double，不然会产生错误*/
/**
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
*/
/*
retailers
distributors
suppliers

supplier -> distributor -> ... -> distributor -> retailer
   p         (1+r%)p               (1+r%)^n*p
*/