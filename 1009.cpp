#include <iostream>
#include <vector>
#include <cstdio>
#include <conio.h>
using namespace std;

struct elem {
	int exponent;
	double coefficient;
};
void print_polynomial(vector<elem> poly){
	int cnt = 0;
	for(int i = 0; i < poly.size(); i++)
		if(poly[i].coefficient != 0)
			cnt++;
	cout << cnt;
	for(int i = 0; i < poly.size(); i++){
		if(poly[i].coefficient != 0)
			printf(" %d %.1f", poly[i].exponent, poly[i].coefficient);
	}
}
void polynomial_sort(vector<elem> & poly){
	for(int i = 0; i < poly.size() - 1; i++)
		for(int j = i + 1; j > 0; j--)
			if(poly[j].exponent > poly[j - 1].exponent){
				elem temp = poly[j];
				poly[j] = poly[j - 1];
				poly[j - 1] = temp;
			}
}
vector<elem> polynomial_product(vector<elem> poly1, vector<elem> poly2){
	vector<elem> result;
	for(int i = 0; i < poly1.size(); i++){
		for(int j = 0; j < poly2.size(); j++){
			bool flag = true;
			elem temp;
			temp.exponent = poly1[i].exponent + poly2[j].exponent;
			temp.coefficient = poly1[i].coefficient * poly2[j].coefficient;
			for(int k = 0; k < result.size(); k++)
				if(result[k].exponent == temp.exponent){
					result[k].coefficient += temp.coefficient;
					flag = false;
					break;
				}
			if(flag)
				result.push_back(temp);
		}
	}
	polynomial_sort(result);
	return result;
}

int main(){
	int k1, k2;
	cin >> k1;
	vector<elem> poly1(k1);
	for(int i = 0; i < k1; i++)
		cin >> poly1[i].exponent >> poly1[i].coefficient;
	cin >> k2;
	vector<elem> poly2(k2);
	for(int i = 0; i < k2; i++)
		cin >> poly2[i].exponent >> poly2[i].coefficient;
	print_polynomial(polynomial_product(poly1, poly2));
	getch();
	return 0;
}