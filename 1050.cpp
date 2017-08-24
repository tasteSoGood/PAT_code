#include <iostream>
#include <map>
using namespace std;
int main(){
	string s;
	map<char, bool> judge;
	for(int i = 0; i < 128; i++)
		judge[char(i)] = false;
	getline(cin, s);
	for(;;){
		char t = getchar();
		if(t == '\n') break;
		judge[t] = true;
	}
	for(string::iterator i = s.begin(); i != s.end(); i++)
		if(!judge[*i])
			cout << *i;
	cout << endl;
	return 0;
}