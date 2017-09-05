#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N, i, j;
	cin >> N;
	vector<int> arr(N), arr_res(N);
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	for(int i = 0; i < N; i++)
		cin >> arr_res[i];
	for(i = 0; i < N - 1 && arr_res[i] <= arr_res[i + 1]; i++);
	for(j = i + 1; j < N && arr[j] == arr_res[j]; j++);
	if(j == N){
		cout << "Insertion Sort" << endl;
		sort(arr.begin(), arr.begin() + i + 2);
	}else{
		cout << "Merge Sort" << endl;
		bool flag = true;
		i = 1;
		while(flag){
			flag = false;
			for(int k = 0; k < N; k++)
				if(arr[k] != arr_res[k])
					flag = true;
			i *= 2;
			for(int k = 0; k < N; k += i){
				int t = (k + i < N) ? (k + i) : N;
				sort(arr.begin() + k, arr.begin() + t);
			}
		}
	}
	for(i = 0; i < N; i++){
		if(i != 0)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return 0;
}