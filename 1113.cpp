#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long sum = 0, sub_sum = 0;
vector<int> set;
bool cmp(int a, int b) { return a > b; }
int main() {
	scanf("%d", &N);
	set.resize(N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &set[i]);
		sum += set[i];
	}
	sort(set.begin(), set.end(), cmp);
	for(int i = 0; i < ceil(float(N) / 2); i++)
		sub_sum += set[i];
	printf("%d %ld", (N & 1) ? 1 : 0, sub_sum - (sum - sub_sum));
	return 0;
}