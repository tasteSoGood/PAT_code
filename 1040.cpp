#include <iostream>
using namespace std;
bool dp[1001][1001];
int main(){
	string s;
	getline(cin, s);
	int cnt = 1, len = s.size();
	for(int i = 0; i < len; i++){
		dp[i][i] = true;
		if(i < len - 1 && s[i] == s[i + 1])
			dp[i][i + 1] = true, cnt = 2;
	}
	for(int i = 3; i <= len; i++)
		for(int j = 0; j <= len - i; j++)
			if(s[j] == s[j + i - 1] && dp[j + 1][j + i - 2])
				dp[j][j + i - 1] = true, cnt = i;
	cout << cnt << endl;
	return 0;
}