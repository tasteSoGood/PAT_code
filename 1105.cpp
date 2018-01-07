#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int N;
vector<int> arr;
int res[10001][10001];
int main() {
	scanf("%d", &N);
	arr.resize(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
	int m = INT_MAX, n = 0;
	for(int i = 1; i * i <= N; i++)
		if(N % i == 0 && abs(N / i - i) < m - n)
			m = max(N / i, i), n = min(N / i, i);
	/*0: right, 1: down, 2: left, 3: up*/
	int direction = 0, cnt = 0;
	int a = 0, b = n - 1, c = 0, d = m - 1;
	while(cnt < arr.size()){
		switch(direction) {
			case 0: {
				for(int i = a; i <= b; i++)
					res[c][i] = arr[cnt++];
				c++;
				break;
			}
			case 1: {
				for(int j = c; j <= d; j++)
					res[j][b] = arr[cnt++];
				b--;
				break;
			}
			case 2: {
				for(int i = b; i >= a; i--)
					res[d][i] = arr[cnt++];
				d--;
				break;
			}
			case 3: {
				for(int j = d; j >= c; j--)
					res[j][a] = arr[cnt++];
				a++;
				break;
			}
		}
		direction = (direction + 1) % 4;
	}
	for(int i = 0; i < m; i++){
		printf("%d", res[i][0]);
		for(int j = 1; j < n; j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
	return 0;
}
/**
Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
*/
/*A spiral matrix is filled in from the first element at the 
upper-left corner, then move in a clockwise spiral.*/