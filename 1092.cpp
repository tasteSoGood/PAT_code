#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s, p;
	bool flag = false;
	cin >> s >> p;
	int ch[128], ch2[128], cnt = 0;
	fill(ch, ch + 128, 0), fill(ch2, ch2 + 128, 0);
	for(int i = 0; i < s.size(); i++)
		ch[s[i]]++;
	for(int i = 0; i < p.size(); i++)
		ch2[p[i]]++;
	for(int i = 0; i < p.size(); i++)
		if(ch[p[i]] < ch2[p[i]]){
			cout << "No ";
			flag = true;
			break;
		}
	if(flag){
		for(int i = 0; i < 128; i++)
			if(ch[i] < ch2[i])
				cnt += (ch2[i] - ch[i]);
	}
	else{
		cout << "Yes ";
		cnt = s.size() - p.size();
	}
	cout << cnt << endl;
	return 0;
}