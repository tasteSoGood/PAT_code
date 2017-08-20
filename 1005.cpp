#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintLetter(int num){
	vector<string> letter = {  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	if(num != 0){
		PrintLetter(num / 10);
		if(!(num >= 0 && num < 10))
			cout << " ";
		cout << letter[num % 10];
	}
}
int sum(string big_num){
	int res = 0;
	for(int i = 0; i < big_num.size(); i++)
		res += int(big_num[i] - 48);
	return res;
}

int main(){
	string test;
	cin >> test;
	int x = sum(test);
	if(x == 0)
		cout << "zero" << endl;
	else{
		PrintLetter(x);
		cout << endl;
	}
	return 0;
}