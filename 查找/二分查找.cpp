#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <ctime>
using namespace std;
default_random_engine e(time(0));
uniform_real_distribution<double> u;
int randint(int low, int high){
	return int(u(e) * (high - low) + low);
}
int recursion_binary_search(vector<int> arr, int left, int right, int num){
	if(left < right){
		int mid = (left + right) / 2;
		if(arr[mid] > num)
			return recursion_binary_search(arr, left, mid, num);
		else if(arr[mid] < num)
			return recursion_binary_search(arr, mid + 1, right, num);
		else
			return mid;
	}
	return right;
}
int iteration_binary_search(vector<int> arr, int num){
	int left = 0, right = arr.size(), mid;
	while(left < right){
		mid = (left + right) / 2;
		if(arr[mid] < num)
			left = mid + 1;//这里的 +1 一定要记住
		else if(arr[mid] > num)
			right = mid;
		else
			return mid;
	}
	return mid;
}
int main(){
	vector<int> test_arr(10);
	for(int i = 0; i < test_arr.size(); i++)
		test_arr[i] = randint(0, 100);
	sort(test_arr.begin(), test_arr.end());
	for(auto i : test_arr)
		cout << i << " ";
	cout << endl;
	int pos1 = iteration_binary_search(test_arr, 50);
	cout << pos1 << " " << test_arr[pos1] << endl;
	int pos2 = recursion_binary_search(test_arr, 0, test_arr.size(), 50);
	cout << pos2 << " " << test_arr[pos2] << endl;
	return 0;
}