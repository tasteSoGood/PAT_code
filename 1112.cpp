#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int k, cnt = 1;
	string s;
	cin >> k >> s;
	map<char, bool> record, these_is_not, output;
	char t = '#';
	s = s + t;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == t)
			cnt++;
		else{
			if(cnt % k != 0)
				these_is_not[s[i]];
			cnt = 1;
		}
		if(i != s.size() - 1)
			record[s[i]] = (cnt % k == 0);
		t = s[i];
	}
	for(int i = 0; i < s.size(); i++){
		//这里需要保证坏键的输出顺序是字符串本身的顺序，且只能输出一次
		if(record[s[i]] && output[s[i]] == false){
			cout << s[i];
			output[s[i]] = true;
		}
	}
	cout << endl;
	for(int i = 0; i < s.size() - 1; i++){
		cout << s[i];
		if(record[s[i]])
			i += (k - 1);
	}
	cout << endl;
	return 0;
}