#include <iostream>
#include <sstream>
#include <map>
#include <cctype>
using namespace std;
int main(){
	string s, t;
	getline(cin, s);
	for(int it = 0; it < s.size(); it++){
		if(isupper(s[it]))
			s[it] = tolower(s[it]);
		if(!isalnum(s[it]))
			s[it] = ' ';
	}
	stringstream ss;
	ss << s;
	map<string, int> statistic;
	while(ss >> t)
		statistic[t]++;
	int max = 0;
	for(auto it : statistic)
		if(it.second > max)
			t = it.first, max = it.second;
	cout << t << " " << max;
	return 0;
}
/**
 * 1. stringstream是个好东西
 * 2. <cctype>可以省很多事
 */