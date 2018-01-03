#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> sum, result;
void find_best(int i, int &j, int &temp_sum){
	int left = i, right = n;
	while(left < right){
		int mid = (right + left) / 2;
		if(sum[mid] - sum[i - 1] >= m)
			right = mid;
		else
			left = mid + 1;
	}
	j = right;
	temp_sum = sum[j] - sum[i - 1];
}
int main(){
	scanf("%d %d", &n, &m);
	sum.resize(n + 1, 0);
	for(int i = 1; i <= n; i++){
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	int min_sum = sum[n];
	for(int i = 1; i <= n; i++){
		int j, temp_sum;
		find_best(i, j, temp_sum);
		if(temp_sum >= m && temp_sum < min_sum)
			min_sum = temp_sum, result.clear();
		if(min_sum == temp_sum)
			result.push_back(i), result.push_back(j);
	}
	for(int i = 0; i < result.size(); i += 2)
		printf("%d-%d\n", result[i], result[i + 1]);
	return 0;
}
/**
 * 二分查找是一种更好的查找方式，尽量使用二分查找
 */