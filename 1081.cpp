#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int eculid(int a, int b){
	if(b == 0)
		return a;
	if(a < b)
		return eculid(a, b % a);
	else if(a > b)
		return eculid(b, a % b);
}
class rat {
public:
	int up, low;
	rat(int a, int b) : up(a), low(b) {};
	void operator+(rat obj){
		int temp = low;
		low = low * obj.low;
		up = up * obj.low + temp * obj.up;
		int t = eculid(int(abs(low)), int(abs(up)));
		low /= t, up /= t;
	}
	void print(){
		if(up % low == 0)
			cout << up / low << endl;
		else{
			if(up > low)
				cout << int(abs(up)) / int(abs(low)) << " ";
			cout << int(abs(up)) % int(abs(low)) << "/" << low << endl;
		}
	}
};
int main(){
	int n;
	cin >> n;
	rat res(0, 1);
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d/%d", &a, &b);
		rat t(a, b);
		res + t;
	}
	res.print();
	return 0;
}