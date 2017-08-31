#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int num = 0;
double cnt = 0, x = 0;
bool judge(string s){
	if(s.size() > 8)
		return false;//限制可能的最大长度（这里有一个未知的错误，加这一条可以避免）
	bool symbol = (s[0] == '-') ? true : false;
	if((s[0] == '-' && s[1] == '.') || s[0] == '.')
		return false;
	int temp = 0;
	for(int i = (symbol ? 1 : 0); i < s.size(); i++){
		if(!(s[i] == '.' || (s[i] <= '9' && s[i] >= '0')) || temp > 1)
			return false;
		if(s[i] == '.')
			temp++;
	}
	int t = s.find('.');
	if(t == -1)
		x = double(stoi(s));
	else if(s.size() - t > 3)
		return false;
	else{
		x = double(stoi(s.substr(0, t)));
		double sub = 0;
		for(int i = s.size() - 1; i >= t + 1; i--)
			sub = sub / 10 + double(s[i] - 48);
		x += symbol ? (-sub / 10) : sub / 10;
	}
	return (x <= 1000 && x >= -1000);
}
int main(){
	int N;
	string s;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s;
		if(judge(s))
			cnt += x, num++;
		else
			cout << "ERROR: " << s << " is not a legal number" << endl;
	}
	cout << "The average of " << num << ((num == 1) ? " number is " : " numbers is ");
	if(num == 0)
		cout << "Undefined" << endl;
	else
		printf("%.2lf\n", cnt / double(num));
	return 0;
}