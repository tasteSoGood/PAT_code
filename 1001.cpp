#include <iostream>
using namespace std;
string format(int num){
	if(num == 0)
		return "0";
	int temp = (num < 0) ? -num : num, cnt = 0;
	string store;
	while(temp != 0){
		if(cnt % 3 == 0 && cnt != 0)
			store.push_back(',');
		store.push_back(temp % 10 + 48);
		temp /= 10, cnt++;
	}
	if(num < 0)
		store.push_back('-');
	int length = store.size();
	for(int i = 0; i < (int)(length / 2); i++)
		swap(store[i], store[length - i - 1]);
	return store;
}
int main(){
	int a, b;
	cin >> a >> b;
	cout << format(a + b) << endl;
	return 0;
}