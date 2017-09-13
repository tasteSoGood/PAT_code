#include <cstdio>
#include <algorithm>
using namespace std;
struct node { int data, id; };
node re[100001], res[100001];
bool cmp(node a, node b){ return a.data < b.data; }
int main(){
	int N, start;
	scanf("%d %d", &N, &start);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		re[a] = {b, c};
	}
	int cnt = 0;
	while(start != -1){
		res[cnt++] = {re[start].data, start};
		start = re[start].id;
	}
	if(cnt == 0)
		printf("0 -1");//注意，题目只说链表中不含环，但链表可能长度为0
	else{
		sort(res, res + cnt, cmp);
		printf("%d %05d\n", cnt, res[0].id);
		for(int i = 0; i < cnt - 1; i++)
			printf("%05d %d %05d\n", res[i].id, res[i].data, res[i + 1].id);
		printf("%05d %d -1\n", res[cnt - 1].id, res[cnt - 1].data);
	}
	return 0;
}