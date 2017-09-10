#include <cstdio>
using namespace std;
char c[6][5] = { "Shi", "Bai", "Qian", "Wan", "Yi" };
char t[11][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
int a;
bool flag = false;
void read(int num){
	bool flag1 = false, flag2 = false, flag3 = false;
	if(num / 1000)//千位
		printf("%s %s", t[num / 1000], c[2]), flag1 = true;
	if(flag && !flag1)
		printf("ling ");
	if(num / 100 % 10){//百位
		if(flag1)
			printf(" ");
		printf("%s %s", t[num / 100 % 10], c[1]), flag2 = true;
	}
	if(flag1 && !flag2 && num % 100)
		printf(" ling");
	if(num / 10 % 10){//十位
		if(flag1 || flag2)
			printf(" ");
		printf("%s %s", t[num / 10 % 10], c[0]), flag3 = true;
	}
	if(flag2 && !flag3 && num % 10)
		printf(" ling");
	if(num % 10){//个位
		if(flag1 || flag2 || flag3)
			printf(" ");
		printf("%s", t[num % 10]);
	}
}
int main(){
	int flag1 = false, flag2 = false;
	scanf("%d", &a);
	if(a < 0)
		printf("Fu "), a = -a;
	if(a == 0)
		printf("ling");
	if(a > 99999999){
		int temp = a / 100000000;
		read(temp);
		printf(" %s", c[4]);
		a = a % 100000000;
		flag1 = true;
	}
	if(a > 9999){
		int temp = a / 10000;
		if(flag1)
			printf(" "), flag = 1;
		read(temp);
		printf(" %s", c[3]);
		a = a % 10000;
		flag2 = true;
	}
	flag = false;
	if((flag1 || flag2) && a != 0){
		flag = true;
		printf(" ");
	}
	read(a);
	return 0;
}
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string rad[8] = { "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
vector<string> result;
void read_four(string t, bool flag){
	int j;
	for(j = 0; j < t.size() && t[j] == '0'; j++);
	t = t.substr(j, t.size() - j);
	if(flag)
		result.push_back("ling");
	bool tag = true;
	for(int i = 0; i < t.size(); i++){
		if(t[i] != '0'){
			result.push_back(num[t[i] - 48]);
			result.push_back(rad[t.size() - i - 2]);
			tag == true;
		}
		if(tag && t[i] == '0' && i != t.size() - 1 && !(t.size() == 3 && t[2] == '0' && t[1] == '0') && !(t.size() == 4 && t[3] == '0' && t[2] == '0') && !(t.size() == 4 && t[3] == '0' && t[2] == '0' && t[1] == '0')){
			result.push_back("ling");
			tag = false;
		}
	}
}
int main(){
	string t;
	cin >> t;
	if(t[0] == '-'){
		cout << "Fu ";
		t = t.substr(1, t.size() - 1);
	}
	string res(10, '0');
	for(int i = 9, j = t.size() - 1; i >= 0 && j >= 0; i--, j--)
		res[i] = t[j];
	if(t.size() <= 4)
		read_four(t, false);
	else if(t.size() <= 8 && t.size() > 4){
		read_four(res.substr(2, 4), false);
		result.push_back("Wan");
		if(res.substr(6, 4) != "0000")
			read_four(res.substr(6, 4), false);
	}
	else{
		read_four(res.substr(0, 2), false);
		result.push_back("Yi");
		if(res.substr(2, 8) != "00000000"){
			read_four(res.substr(2, 4), false);
			result.push_back("Wan");
			if(res.substr(6, 4) != "0000")
				read_four(res.substr(6, 4), false);
		}
	}
	cout << result[0];
	for(int i = 1; i < result.size(); i++)
		if(result[i] != "")
			cout << " " << result[i];
	return 0;
}
*/