#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node{int id, r;};
bool cmp(node a, node b){return a.r > b.r;}
bool cmp2(node a, node b){return a.id < b.id;}
int main(){
	int N, G, t;
	scanf("%d %d", &N, &G);
	vector<int> temp(N), arr(N);
	vector<node> rank(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &temp[i]);
	for(int i = 0; i < N; i++){
		scanf("%d", &t);
		arr[i] = temp[t];
		rank[i] = {t, 1};
	}
	int level = 1;
	vector< vector<int> > store(1);
	for(int i = 0; i < N; i++)
		store[0].push_back(i);
	for(int k = 0; ; k++){
		vector<int> inner;
		for(int i = 0; i < store[k].size(); i += G){
			int max = i;
			for(int j = i; j < i + G && j < store[k].size(); j++)
				if(rank[store[k][j]].r == level && arr[store[k][j]] > arr[store[k][max]])
					max = j;
			rank[store[k][max]].r = level + 1, inner.push_back(store[k][max]);
		}
		store.push_back(inner), level++;
		if(inner.size() == 1)
			break;
	}//此处的复杂度是比较低的，收敛地极快，并非O(n^3)
	sort(rank.begin(), rank.end(), cmp);
	int tag = rank[0].r, cnt = 1, cnt2 = -1;
	for(int i = 0; i < N; i++){
		if(rank[i].r == tag)
			rank[i].r = cnt, cnt2++;
		else
			tag = rank[i].r, rank[i].r = cnt + cnt2 + 1, cnt = cnt + cnt2 + 1, cnt2 = 0;
	}
	sort(rank.begin(), rank.end(), cmp2);
	printf("%d", rank[0].r);
	for(int i = 1; i < N; i++)
		printf(" %d", rank[i].r);
	return 0;
}