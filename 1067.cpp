#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t, cnt = 0, N;
	cin >> N;
	vector<int> arr(N), hash(N);
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		hash[arr[i]] = i;
	}
	//sort
	if(arr[0] == 0){
		for(int i = 1; i < N; i++){
			if(arr[i] != i){
				hash[arr[i]] = 0;
				hash[arr[0]] = i;
				swap(arr[0], arr[i]);
				cnt++;
				break;
			}
		}
	}
	int i = 1;
	while(arr[0] != 0){
		swap(arr[hash[0]], arr[hash[hash[0]]]);
		swap(hash[0], hash[hash[0]]);
		cnt++;
		if(arr[0] == 0){
			for(; i < N; i++){
				if(arr[i] != i){
					hash[arr[i]] = 0;
					hash[arr[0]] = i;
					swap(arr[0], arr[i]);
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}