#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin >> s;
	int p = 0, t = 0, res = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == 'T')
			t++;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'P') p++;
		if(s[i] == 'T') t--;
		if(s[i] == 'A') res = (res + (p * t) % 1000000007) % 1000000007;
	}
	cout << res << endl;
	return 0;
}
/*这是一道经典题：某一个位上PAT的个数等于A左边的P的个数乘以A右边的T的个数*/