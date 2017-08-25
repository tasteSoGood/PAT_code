#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
	char symbol;
	string num;
	int exponent;
	scanf("%c", &symbol);
	if(symbol == '-')
		printf("-");
	for(;;){
		char t = getchar();
		if(t >= '0' && t <= '9' && t != 'E')
			num.push_back(t);
		if(t == 'E')
			break;
	}
	scanf("%d", &exponent);
	if(exponent < 0){
		num.insert(0, -exponent, '0');
		num.insert(1, 1, '.');
	}
	else if(exponent >= num.size())
		num.insert(num.size(), exponent - num.size() + 1, '0');
	else if(exponent < num.size() - 1)
		num.insert(exponent + 1, 1, '.');
	cout << num << endl;
	return 0;
}