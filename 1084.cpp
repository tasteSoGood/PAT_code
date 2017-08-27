#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	map<char, bool> ch;
	string a, b;
	cin >> a >> b;
	for(int tag1 = 0, tag2 = 0; tag1 < a.size(); tag1++){
		if(tag2 >= b.size() || a[tag1] != b[tag2]){
			if(a[tag1] >= 'a' && a[tag1] <= 'z'){
				if(ch[a[tag1] - ('a' - 'A')] != true)
					cout << char(a[tag1] - ('a' - 'A'));
				ch[a[tag1] - ('a' - 'A')] = true;
			}
			else{
				if(ch[a[tag1]] != true)
					cout << char(a[tag1]);
				ch[a[tag1]] = true;
			}
		}
		else if(a[tag1] == b[tag2])
			tag2++;
	}
	return 0;
}