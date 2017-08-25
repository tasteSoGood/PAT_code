/*普通版
#include <iostream>
using namespace std;

int res(int n){
	int t = 0;
	while(n)
		t = t * 10 + n % 10, n /= 10;
	return t;
}
void print4digits(int num){
	int res[4];
	for(int i = 3; i >= 0; i--)
		res[i] = num % 10, num /= 10;
	for(int i = 0; i < 4; i++)
		cout << res[i];
}
int digits_sort(int num){
	int t[4], res = 0;
	for(int i = 3; i >= 0; i--)
		t[i] = num % 10, num /= 10;
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j > 0 && t[j] > t[j - 1]; j--)
			swap(t[j], t[j - 1]);
	for(int i = 0; i < 4; i++)
		res = res * 10 + t[i];
	return res;
}
int main(){
	int num, temp, tag;
	cin >> num;
	if(num > 999 && res(num) - num == 0){
		cout << num << " - " << num << " = 0000";
		return 0;
	}
	temp = digits_sort(num);
	tag = temp - res(temp);
	for(;;){
		print4digits(temp);
		cout << " - ";
		print4digits(res(temp));
		cout << " = ";
		print4digits(tag);
		cout << endl;
		if(tag == 6174)
			break;
		temp = digits_sort(tag);
		tag = temp - res(temp);
	}
	return 0;
}
**/
/**
 * STL版
 */
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
bool compare(char a, char b){ return a > b; }
string itos(int n){
	stringstream s;
	s << n;
	return s.str();
}/*这是一个折中的方案，c++11中的to_string方法不知道怎么在g++上用不了*/
int main(){
	string str;
	cin >> str;
	str.insert(0, 4 - str.size(), '0');
	do {
		string a = str, b = str;
		sort(a.begin(), a.end(), compare);
		sort(b.begin(), b.end());
		str = itos(stoi(a) - stoi(b));
		str.insert(0, 4 - str.size(), '0');
		cout << a << " - " << b << " = " << str << endl;
	} while(str != "6174" && str != "0000");
	return 0;
}