#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindromic(string n){
	int f = 0, r = n.size() - 1;
	while(f < r){
		if(n[f] != n[r])
			return false;
		f++, r--;
	}
	return true;
}
string add_reverse(string n){
	string a = n, b = n, t;
	reverse(b.begin(), b.end());
	int temp = 0;
	for(int i = 0; i < n.size(); i++){
		t = t + char((a[i] - 48 + b[i] - 48 + temp) % 10 + 48);
		temp = (a[i] - 48 + b[i] - 48 + temp) / 10;
	}
	if(temp)
		t = t + char(temp + 48);
	reverse(t.begin(), t.end());
	return t;
}
int main(){
	string N;
	int k, i;
	cin >> N >> k;
	if(isPalindromic(N)){
		cout << N << "\n" << 0 << endl;
		return 0;
	}//有可能输入本身就是回文数
	for(i = 1; i <= k; i++){
		N = add_reverse(N);
		if(isPalindromic(N)){
			cout << N << "\n" << i << endl;
			return 0;
		}
	}
	cout << N << "\n" << k << endl;
	return 0;
}