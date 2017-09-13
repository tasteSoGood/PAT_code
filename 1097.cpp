#include <cstdio>
#include <algorithm>
using namespace std;
struct node { int id, data; };
node f[100001], r[100001], r1[100001], r2[100001];
int h[10001], h_t[100001];
int main(){
	int start, N;
	fill(h, h + 10001, 0);
	fill(h_t, h_t + 10001, 0);
	scanf("%d %d", &start, &N);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		f[a] = {c, b};
		h[abs(b)]++, h_t[abs(b)] = 1;
	}
	int cnt = 0;
	while(start != -1){
		r[cnt++] = {start, f[start].data};
		start = f[start].id;
	}
	int tag1 = 0, tag2 = 0;
	for(int i = 0; i < cnt; i++){
		if(h[abs(r[i].data)] > 1 && h_t[abs(r[i].data)] == 1)
			r1[tag1++] = r[i], h_t[abs(r[i].data)] = 2;
		else if(h[abs(r[i].data)] > 1 && h_t[abs(r[i].data)] == 2)
			r2[tag2++] = r[i];
		else
			r1[tag1++] = r[i];
	}
	for(int i = 0; i < tag1 - 1; i++)
		printf("%05d %d %05d\n", r1[i].id, r1[i].data, r1[i + 1].id);
	if(tag1)
		printf("%05d %d -1\n", r1[tag1 - 1].id, r1[tag1 - 1].data);
	for(int i = 0; i < tag2 - 1; i++)
		printf("%05d %d %05d\n", r2[i].id, r2[i].data, r2[i + 1].id);
	if(tag2)//有可能出现0结果的情况，记得排除
		printf("%05d %d -1\n", r2[tag2 - 1].id, r2[tag2 - 1].data);
	return 0;
}