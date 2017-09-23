#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(long long a, long long b){
	if(a > 0 && b <= 0)
		return a > b;
	else if(a > 0 && b > 0)
		return a > b;
	else if(a <= 0 && b <= 0)
		return b > a;
}
int main(){
	int NC, NP;
	cin >> NC;
	vector<long long> coupon(NC);
	for(int i = 0; i < NC; i++)
		cin >> coupon[i];
	cin >> NP;
	vector<long long> product(NP);
	for(int i = 0; i < NP; i++)
		cin >> product[i];
	sort(coupon.begin(), coupon.end(), cmp);
	sort(product.begin(), product.end(), cmp);
	int tag1 = 0, tag2 = 0;
	long long sum = 0;
	while(tag1 < NC && tag2 < NP){
		long long temp = coupon[tag1] * product[tag2];
		if(temp > 0)
			sum += temp, tag1++, tag2++;
		else if(temp <= 0){
			if(coupon[tag1] >= 0)
				tag1++;
			else if(product[tag2] >= 0)
				tag2++;
		}
	}
	cout << sum << endl;
	return 0;
}