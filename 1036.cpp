#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	string name;
	char sex;
	string id;
	int grade;
};
bool cmp(node a, node b){ return a.grade > b.grade; }
int main(){
	int N;
	cin >> N;
	vector<node> male, female;
	for(int i = 0; i < N; i++){
		node t;
		cin >> t.name >> t.sex >> t.id >> t.grade;
		if(t.sex == 'M')
			male.push_back(t);
		else
			female.push_back(t);
	}
	sort(male.begin(), male.end(), cmp);
	sort(female.begin(), female.end(), cmp);
	if(female.size() == 0)
		cout << "Absent" << endl;
	else
		cout << female[0].name << " " << female[0].id << endl;
	if(male.size() == 0)
		cout << "Absent" << endl;
	else
		cout << male[male.size() - 1].name << " " << male[male.size() - 1].id << endl;
	if(female.size() == 0 || male.size() == 0)
		cout << "NA" << endl;
	else
		cout << female[0].grade - male[male.size() - 1].grade << endl;
	return 0;
}