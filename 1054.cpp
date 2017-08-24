#include <cstdio>
#include <map>
using namespace std;
int main(){
	int M, N, t;
	scanf("%d %d", &M, &N);
	int half = M * N / 2;
	map<int, int> record;
	for(int i = 0; i < M * N; i++){
		scanf("%d", &t);
		record[t]++;
		if(record[t] > half){
			printf("%d\n", t);
			break;
		}
	}
	return 0;
}
/**
 * 这道题是不能用<iostream>中的cin来输入的，会超时
 * 以后在看到需要考虑用时的输入输出操作的时候，最好
 * 使用C标准的输入输出
 */