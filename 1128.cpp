#include <iostream>
#include <vector>
using namespace std;
bool judge(vector<int> arr){
	for(int i = 0; i < arr.size(); i++)
		for(int j = 0; j < i; j++)
			if(arr[j] == arr[i] || arr[j] == arr[i] + i - j || arr[j] == arr[i] + j - i)
				return false;
	return true;
}
int main(){
	int N, length;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> length;
		vector<int> chess(length);
		for(int i = 0; i < length; i++)
			cin >> chess[i];
		cout << (judge(chess) ? "YES" : "NO") << endl;//注意，大小写千万要看清楚，输出不要错了！
	}
	return 0;
}