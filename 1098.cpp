#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
void heaplify(vector<int> &arr, int p, int b){
	int l = (p + 1) * 2 - 1, r = (p + 1) * 2, max = p;
	if(l < b && arr[l] > arr[max])
		max = l;
	if(r < b && arr[r] > arr[max])
		max = r;
	if(max != p){
		swap(arr[p], arr[max]);
		heaplify(arr, max, b);
	}
}
int main(){
	int N, l;
	scanf("%d", &N);
	vector<int> a(N), b(N);
	for(int i = 0; i < N; i++) scanf("%d", &a[i]);
	for(int i = 0; i < N; i++) scanf("%d", &b[i]);
	bool flag = false;
	for(l = 1; l < N && b[l] >= b[l - 1]; l++);
	for(int i = N - 1; i > l; i--)
		if(a[i] != b[i]){
			flag = true;
			break;
		}
	if(flag){
		printf("Heap Sort\n");
		for(l = N - 1; l >= 0 && b[l] >= b[0]; l--);
		swap(b[0], b[l]);
		heaplify(b, 0, l);
	}else{
		printf("Insertion Sort\n");
		sort(b.begin(), b.begin() + l + 1);
	}
	printf("%d", b[0]);
	for(int i = 1; i < N; i++)
		printf(" %d", b[i]);
	return 0;
}