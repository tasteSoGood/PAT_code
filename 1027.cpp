#include <iostream>
using namespace std;
void trans(int x){
	char res[2];
	int cnt = 2;
	while(--cnt >= 0){
		int t = x % 13;
		if(t >= 0 && t < 10)
			res[cnt] = t + 48;
		else if(t >= 10 && t <= 12)
			res[cnt] = char('A' + t - 10);
		x /= 13;
	}
	cout << res[0] << res[1];
}
int main(){
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#";
	trans(r), trans(g), trans(b);
	cout << endl;
	return 0;
}