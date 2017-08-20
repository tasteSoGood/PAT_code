#include <iostream>
using namespace std;
int main(){
	int lastFloor = 0, res = 0, n, t;
	cin >> n;
	while(n--){
		cin >> t;
		if(t < lastFloor)
			res += (lastFloor - t) * 4;
		else if(t > lastFloor)
			res += (t - lastFloor) * 6;
		res += 5;
		lastFloor = t;
	}
	cout << res << endl;
	return 0;
}