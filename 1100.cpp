#include <iostream>
#include <string>
using namespace std;
string s1[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string s2[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
string trans(int n){/*该部分要考虑周到*/
	string res;
	if(n == 0)
		return "tret";
	if(n / 13)
		res.append(s2[n / 13]);
	if(n / 13 && n % 13)
		res.append(" ");
	if(n % 13)
		res.append(s1[n % 13]);
	return res;
}
int inner(string str){
	for(int i = 0; i < 13; i++){
		if(s1[i] == str)
			return i;
		if(s2[i] == str)
			return i * 13;
	}
}
int trans_2(string str){
	if(str.size() == 3 || str.size() == 4)
		return inner(str);
	string a, b;
	int t = str.find(' ');
	a = str.substr(0, t);
	b = str.substr(t + 1, str.size() - t);
	return inner(a) + inner(b); 
}
int main(){
	int N;
	string input;
	cin >> N;
	getline(cin, input);//记得这里要多写一个getline()
	for(int i = 0; i < N; i++){
		getline(cin, input);
		if(input[0] <= '9' && input[0] >= '0')
			cout << trans(stoi(input)) << endl;
		else
			cout << trans_2(input) << endl;
	}
	return 0;
}