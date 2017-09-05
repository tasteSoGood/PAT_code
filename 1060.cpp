#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int N;
string itos(int i){
	stringstream s;
	s << i;
	return s.str();
}
string trans(string num){
	string res;
	int tag = 0;
	for(int i = 0; i < num.size(); i++){
		if(num[tag] == '0')
			tag++;
		else
			break;
	}
	int dot = num.find('.'), deg = (dot > 0 && dot < num.size()) ? dot - tag : num.size() - tag;
	res = "0.*10^" + itos(deg);
	for(int i = 2; i < 2 + N; ) {
		if(num[tag] >= '0' && num[tag] <= '9')
			res = res.insert(i, 1, num[tag++]);
		(num[tag] == '.') ? tag++ : i++;
	}
	return res;
}
int main(){
	string a, b, c, d;
	cin >> N >> a >> b;
	c = trans(a), d = trans(b);
	if(c == d)
		cout << "YES " << c << endl;
	else
		cout << "NO " << c << " " << d << endl;
	// string t;
	// while(true){
	// 	cin >> t >> N;
	// 	cout << trans(t) << endl;
	// }
	return 0;
}