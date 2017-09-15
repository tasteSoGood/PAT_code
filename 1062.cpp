#include <cstdio>
#include <algorithm>
using namespace std;
struct node { int id, vi, ta, rank; } r[100001];
bool cmp(node a, node b){
	return a.rank == b.rank ? (a.vi + a.ta == b.vi + b.ta ? (a.vi == b.vi ? a.id < b.id : a.vi > b.vi) : a.vi + a.ta > b.vi + b.ta) : a.rank < b.rank;
}
int main(){
	int N, L, H, cnt = 0;
	scanf("%d %d %d", &N, &L, &H);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(b >= L && c >= L)
			r[cnt++] = {a, b, c};
	}
	for(int i = 0; i < cnt; i++){
		if(r[i].vi >= H && r[i].ta >= H)
			r[i].rank = 1;
		else if(r[i].vi >= H && r[i].ta < H)
			r[i].rank = 2;
		else if(r[i].vi < H && r[i].ta < H && r[i].ta <= r[i].vi)//这个等号记得写！
			r[i].rank = 3;
		else
			r[i].rank = 4;
	}
	sort(r, r + cnt, cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
		printf("%08d %d %d\n", r[i].id, r[i].vi, r[i].ta);
	return 0;
}