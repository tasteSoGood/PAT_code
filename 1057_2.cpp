#include <iostream>
#include <vector>
#include <string>
using namespace std;

int PeekMedian(vector<int> arr){
	return 1;
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