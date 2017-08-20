#include <iostream>
#include <vector>
using namespace std;

bool judge(vector<int> num){
	int front = 0, tail = num.size() - 1;
	while(front < tail){
		if(num[front] != num[tail])
			return false;
		front++, tail--;
	}
	return true;
}

int main(){
	long long int num, radix;
	cin >> num >> radix;
	vector<int> store;
	while(num){
		store.push_back(num % radix);
		num = num / radix;
	}
	if(judge(store))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if(store.size()){
		cout << store[store.size() - 1];
		for(int i = store.size() - 2; i >= 0; i--)
			cout << " " << store[i];
		cout << endl;
	}
	else
		cout << 0 << endl;
	return 0;
}