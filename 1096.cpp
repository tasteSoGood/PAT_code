#include <iostream>
#include <vector>
using namespace std;
int main(){
	long long N;
	cin >> N;
	long long f = 0, r = 0, ft, rt;
	for(ft = 2; (ft - 1) * (ft - 1) <= N; ft++){
		long long t = 1;
		for(rt = ft; rt < ft + 12 && N % t == 0; rt++)
			t *= rt;
		if(rt - ft > r - f)
			r = rt, f = ft;
	}
	if(r - f - 1 <= 0){
		cout << 1 << "\n" << N << endl;
		return 0;
	}
	cout << r - f - 1 << endl;
	for(int i = f; i < r - 1; i++){
		if(i != f)
			cout << "*";
		cout << i;
	}
	return 0;
}