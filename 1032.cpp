#include <cstdio>
#include <vector>
using namespace std;
struct node {
	char data;
	int next;
	bool flag = false;
} record[100000];
int main(){
	int start1, start2, N, a, b;
	char c;
	scanf("%d %d %d", &start1, &start2, &N);
	for(int i = 0; i < N; i++){
		scanf("%d %c %d", &a, &c, &b);
		record[a].data = c, record[a].next = b;
	}
	for(int i = start1; i != -1; i = record[i].next)
		record[i].flag = true;
	for(int i = start2; i != -1; i = record[i].next)
		if(record[i].flag){
			printf("%05d", i);
			return 0;
		}
	printf("-1");
	return 0;
}