#include <iostream>
using namespace std;

bool judge(long long a, long long b, long long c){
	long long res = a + b;
	//两种越界情况
	if(a < 0 && b < 0 && res >= 0)
		return false;
	if(a > 0 && b > 0 && res <= 0)
		return true;
	//正常情况
	if(res > c)
		return true;
	else
		return false;
}

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i + 1 << ": ";
		if(judge(a, b, c))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
/*
5
0 1 2
45 63 5
-12 3 100
0 0 0
5 123478 215654
*/