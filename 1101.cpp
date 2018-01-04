#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
vector<long long> arr1, arr2;
int main(){
	scanf("%d", &n);
	arr1.resize(n), arr2.resize(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr1[i]);
		arr2[i] = arr1[i];
	}
	sort(arr2.begin(), arr2.end());
	vector<long long> result;
	int max = 0;
	for(int i = 0; i < n; i++){
		if(arr1[i] == arr2[i] && arr2[i] > max)
			result.push_back(arr2[i]);
		if(arr1[i] > max)
			max = arr1[i];
	}
	printf("%d\n", result.size());
	if(result.size() == 0)
		printf("\n");
	else{
		printf("%ld", result[0]);
		for(int i = 1; i < result.size(); i++)
			printf(" %ld", result[i]);
	}
	return 0;
}