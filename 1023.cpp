#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string doubleIt(string num){
	string result;
	int temp = 0;
	reverse(num.begin(), num.end());
	for(string::iterator i = num.begin(); i != num.end(); i++){
		result.push_back(((temp + int((*i) - 48) * 2) % 10) + 48);
		temp = (temp + int((*i) - 48) * 2) / 10;
	}
	if(temp != 0)
		result.push_back(temp + 48);
	reverse(result.begin(), result.end());
	return result;
}

bool judgeIt(string num, string double_num){
	if(num.size() != double_num.size())
		return false;
	vector<int> N1, N2;
	for(int i = 0; i < num.size(); i++){
		N1.push_back(int(num[i] - 48));
		N2.push_back(int(double_num[i] - 48));
	}
	sort(N1.begin(), N1.end());
	sort(N2.begin(), N2.end());
	for(int i = 0; i < num.size(); i++)
		if(N1[i] != N2[i])
			return false;
	return true;
}

int main(){
	string num;
	cin >> num;
	string t = doubleIt(num);
	if(judgeIt(num, t))
		cout << "Yes\n" << t << endl;
	else
		cout << "No\n" << t << endl;
	return 0;
}