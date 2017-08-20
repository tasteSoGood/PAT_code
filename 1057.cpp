/**
 * 该程序使用了统计量选择函数，是关于《算法导论》中一个算法的实现，
 * 很有意义。不过在实际题目中达不到要求，大量数据测试点全部超时。
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int p, int q){
	int j = p - 1;
	for(int i = p; i < q; i++)
		if(arr[i] <= arr[q]){
			j++;
			swap(arr[i], arr[j]);
		}
	swap(arr[j + 1], arr[q]);
	return j + 1;
}

int select(vector<int> &arr, int p, int r, int i){
	if(p == r)
		return arr[p];
	int q = partition(arr, p, r);
	int k = q - p + 1;
	if(i == k)
		return arr[q];
	else if(i < k)
		return select(arr, p, q - 1, i);
	else
		return select(arr, q + 1, r, i - k);
}

int PeekMedian(vector<int> arr){
	vector<int> temp;
	temp.assign(arr.begin(), arr.end());
	return select(temp, 0, temp.size() - 1, (temp.size() + 1) / 2);
}

int main(){
	int N;
	cin >> N;
	vector<int> stack;
	while(N--){
		string temp;
		int tempnum;
		cin >> temp;
		if(temp == "Pop"){
			if(stack.empty())
				cout << "Invalid" << endl;
			else{
				cout << stack.back() << endl;
				stack.pop_back();
			}
		}
		else if(temp == "PeekMedian"){
			if(stack.empty())
				cout << "Invalid" << endl;
			else
				cout << PeekMedian(stack) << endl;
		}
		else if(temp == "Push"){
			cin >> tempnum;
			stack.push_back(tempnum);
		}
	}
	return 0;
}