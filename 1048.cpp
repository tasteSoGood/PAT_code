#include <cstdio>
#include <algorithm>
using namespace std;
int coin[100001], N, num;
int bi_find(int tag, int data, int a = 0, int b = N){
	if(coin[(a + b) / 2] == data && (a + b) / 2 != tag)
		return data;
	else if(a == b)
		return -1;
	if(a < b){
		if(coin[(a + b) / 2] < data)
			return bi_find(tag, data, (a + b) / 2 + 1, b);
		else
			return bi_find(tag, data, 0, (a + b) / 2);
	}
}
int main(){
	scanf("%d %d", &N, &num);
	for(int i = 0; i < N; i++)
		scanf("%d", &coin[i]);
	sort(coin, coin + N);
	for(int i = 0; i < N && coin[i] < num; i++){
		int a = coin[i], b = bi_find(i, num - coin[i]);
		if(b != -1){
			printf("%d %d", a, b);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
/**
 * 尝试用STL的find()函数做，但时间上不行，说明find()函数的复杂度至少是大于O(log(N))的
 */