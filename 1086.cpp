#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct node {
	int data;
	node *left, *right;
};
void inorder(node *tree){
	if(tree->left) inorder(tree->left);
	cout << tree->data << " ";
	if(tree->right) inorder(tree->right);
}
int main(){
	int N, n;
	cin >> N;
	stack<int> sta;
	vector<int> arr;
	for(int i = 0; i < 2 * N; i++){
		string t;
		cin >> t;
		if(t == "Push"){
			cin >> n;
			sta.push(n);
		}
		else
			arr.push_back(sta.top()), sta.pop();
	}
	for(int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}