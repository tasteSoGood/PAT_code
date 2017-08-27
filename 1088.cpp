#include <cstdio>
using namespace std;
long int eculid(long int a, long int b){
	if(b == 0)
		return a;
	if(a < b)
		return eculid(a, b % a);
	else if(a > b)
		return eculid(b, a % b);
}
void print_rat(long int a, long int b){
	if(b == 0){
		printf("Inf");
		return;
	}
	if(a == 0){
		printf("0");
		return;
	}
	if((a < 0 && b > 0) || (a > 0 && b < 0)) printf("(-");
	long int s = (a < 0) ? -a : a, t = (b < 0) ? -b : b;
	if(s % t == 0)
		printf("%ld", s / t);
	else{
		if(s > t)
			printf("%ld ", s / t);
		long int k = eculid(s, t);
		s /= k, t /= k;
		printf("%ld/%ld", s % t, t);
	}
	if((a < 0 && b > 0) || (a > 0 && b < 0)) printf(")");
}
int main(){
	long int a, b, c, d;
	scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
	
	print_rat(a, b), printf(" + ");
	print_rat(c, d), printf(" = ");
	print_rat(a * d + c * b, b * d), printf("\n");

	print_rat(a, b), printf(" - ");
	print_rat(c, d), printf(" = ");
	print_rat(a * d - c * b, b * d), printf("\n");

	print_rat(a, b), printf(" * ");
	print_rat(c, d), printf(" = ");
	print_rat(a * c, b * d), printf("\n");

	print_rat(a, b), printf(" / ");
	print_rat(c, d), printf(" = ");
	print_rat(a * d, b * c), printf("\n");
	return 0;
}