#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	string name, id;
	int grade;
};
bool cmp(node a, node b){ return a.grade > b.grade; }
int main(){
	int N, a, b;
	cin >> N;
	vector<node> r(N);
	for(int i = 0; i < N; i++)
		cin >> r[i].name >> r[i].id >> r[i].grade;
	cin >> a >> b;
	sort(r.begin(), r.end(), cmp);
	bool flag = true;
	for(auto i : r)
		if(i.grade >= a && i.grade <= b){
			flag = false;
			cout << i.name << " " << i.id << endl;
		}
	if(flag)
		cout << "NONE" << endl;
	return 0;
}