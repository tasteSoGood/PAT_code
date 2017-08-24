#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct solu {
	string user_name;
	string password;
	bool flag = false;
};
bool judge(solu &obj){
	bool f = false;
	for(string::iterator i = obj.password.begin(); i != obj.password.end(); i++){
		if(*i == '1')
			*i = '@', f = true;
		if(*i == '0')
			*i = '%', f = true;
		if(*i == 'l')
			*i = 'L', f = true;
		if(*i == 'O')
			*i = 'o', f = true;
	}
	obj.flag = f;
	return f;
}
int main(){
	int M, cnt = 0;
	cin >> M;
	vector<solu> store(M);
	for(int i = 0; i < M; i++)
		cin >> store[i].user_name >> store[i].password;
	for(int i = 0; i < M; i++)
		if(judge(store[i]))
			cnt++;
	if(cnt == 0 && M == 1)
		cout << "There is 1 account and no account is modified" << endl;
	else if(cnt == 0 && M > 1)
		cout << "There are " << M << " accounts and no account is modified" << endl;
	else{
		cout << cnt << endl;
		for(int i = 0; i < M; i++)
			if(store[i].flag)
				cout << store[i].user_name << " " << store[i].password << endl;
	}
	return 0;
}