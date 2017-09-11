#include <cstdio>
#include <algorithm>
using namespace std;
long long N, p, num[100001];
long long bisearch(long long tag, long long a, long long b = N){
	if(a == b)
		return a;
	if(a < b){
		if(num[(a + b) / 2] <= num[tag] * p)
			return bisearch(tag, (a + b) / 2 + 1, b);
		else
			return bisearch(tag, a, (a + b) / 2);
	}
}
int main(){
	scanf("%ld %ld", &N, &p);
	for(long long i = 0; i < N; i++)
		scanf("%ld", &num[i]);
	sort(num, num + N);
	long long len = 0;
	for(long long i = 0; i < N; i++){
		long long cp = bisearch(i, i);
		if(cp - i > len)
			len = cp - i;
	}
	printf("%ld", len);
	return 0;
}
/**
 * 注意题解类型应为long long类型，不然会越界
 * 顺序查找的效率不高，但通过剪枝可以减小一定复杂度，这里直接使用的是二分查找
 */