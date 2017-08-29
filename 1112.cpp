#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int k;
	string s;
	cin >> k >> s;
	map<char, int> record;
	char t = s[0];
	int cnt = 1, tag[1001];
	for(int i = 1; i < s.size(); i++){
		if(s[i] == t)
			cnt++;
		if(s[i] != t)
			t = s[i], cnt = 1;
		if(cnt == k){
			record[s[i]]++, cnt = 1;
			if(record[s[i]] == 2)
				cout << s[i];
		}
	}
	cout << endl;
	bool flag = false;
	for(int i = 0; i < s.size(); i++){
		if(flag && s[i] == t)
			cnt++;
		if(flag && cnt == k)
			tag[i - k + 1] = 1, cnt = 0;
		if(flag && s[i] != t)
			flag = false;
		if((!flag) && record[s[i]] > 1)
			cnt == 1, flag = true, t = s[i];
	}
	for(int i = 0; i < s.size(); i++){
		cout << s[i];
		if(tag[i] == 1)
			i += (k - 1);
	}
	cout << endl;
	return 0;
}