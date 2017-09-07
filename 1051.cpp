#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int M, N, num;
bool judge(vector<int> arr){
	int tag = 0, i;
	stack<int> t;
	for(i = 1; i <= arr[tag]; i++)
		t.push(i);
	while(tag < N){
		if(t.size() > M)
			return false;
		if(!t.empty() && t.top() == arr[tag])
			t.pop(), tag++;
		else if(t.empty())//没有这一项，会引起段错误，因为在栈空时取栈顶元素是不可能的
			t.push(i++);
		else if(t.top() > arr[tag])
			return false;
		else{
			for(int j = i; j <= arr[tag]; j++)
				t.push(j);
			i = arr[tag] + 1;
		}
	}
	return true;
}
int main(){
	cin >> M >> N >> num;
	vector<int> arr(N);
	for(int i = 0; i < num; i++){
		for(int j = 0; j < N; j++)
			cin >> arr[j];
		cout << (judge(arr) ? "YES" : "NO") << endl;
	}
	return 0;
}
/*在不知道何种错误的时候，最好自己构造一个测试点
3 10 2
3 2 5 4 1 6 9 10 8 7
3 2 5 4 1 6 9 10 7 8
*/