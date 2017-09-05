#include <iostream>
#include <vector>
using namespace std;
bool isBST(vector<int> arr, int a, int b){
	if(a >= b)
		return true;
	int flag = arr[a], i;
	for(i = a + 1; i < b && arr[i] < flag; i++);
	for(int j = i; j < b; j++)
		if(arr[j] < flag)
			return false;
	isBST(arr, a + 1, i);
	isBST(arr, i, b);
}
bool isMir(vector<int> arr, int a, int b){
	if(a >= b)
		return true;
	int flag = arr[a], i;
	for(i = a + 1; i < b && arr[i] >= flag; i++);
	for(int j = i; j < b; j++)
		if(arr[j] >= flag)
			return false;
	isMir(arr, a + 1, i);
	isMir(arr, i, b);
}
int main(){
	int N;
	cin >> N;
	vector<int> preorder(N);
	for(int i = 0; i < N; i++)
		cin >> preorder[i];
	if(isBST(preorder, 0, N) && isMir(preorder, 0, N))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}