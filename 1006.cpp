#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stud {
	string stud_num;
	string sign_in;
	string sign_out;
};

int main(){
	int n, in = 0, out = 0;
	cin >> n;
	vector<struct stud> store(n);
	for(int i = 0; i < n; i++){
		cin >> store[i].stud_num >> store[i].sign_in >> store[i].sign_out;
		if(store[i].sign_in <= store[in].sign_in)
			in = i;
		if(store[i].sign_out >= store[out].sign_out)
			out = i;
	}
	cout << store[in].stud_num << " " << store[out].stud_num << endl;
	return 0;
}