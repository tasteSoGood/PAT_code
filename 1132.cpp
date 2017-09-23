#include <iostream>
#include <string>
using namespace std;
int main(){
	int N;
	string x;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x;
		long long n = stoi(x);
		long long a = stoi(x.substr(0, x.size() / 2));
		long long b = stoi(x.substr(x.size() / 2, x.size() / 2));
		if(a == 0 || b == 0)
			cout << "No" << endl;
		else if(n % (a * b) != 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}