#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int list_idx = 0;
void isPandigital(int *list, int *perm);
int getList(int *potential);
int allDigits(int p1, int p2, int product);
int unique(int num);
int contains(int *list, int num);

int main() {
	
	int i;
	int list[15120] = {0};
	int perm[5];
	int potential[88889] = {0};
	int number;
	int sum = 0;
	
	number = getList(potential);

	for (i = 0; i < number; i++) {
		perm[0] = potential[i] / 10000;
		perm[1] = (potential[i] % 10000) / 1000;
		perm[2] = ((potential[i] % 10000) % 1000) / 100;
		perm[3] = (((potential[i] % 10000) % 1000) % 100) / 10;
		perm[4] = ((((potential[i] % 10000) % 1000) % 100) % 10);
		isPandigital(list,perm);
	}	

	if (!list_idx) {
		printf("No multiplicand/multiplier/product identities that can be written as 1-9 pandigital found\n");
	} else {
		printf("list_idx is %d and products who identities can be written 1-9 pandigital:\n",list_idx);
		for (i = 0; i < list_idx; i++) {
			sum += list[i];
			printf("%d\n",list[i]);
		}
		printf("Their sum is %d\n",sum);
	}
	
	return 0;
}

int getList(int *potential) {
	
	int i, idx = 0;
	for (i = 11111; i <= 99999; i++) {
		if (unique(i)) {
			potential[idx++] = i;
		}
	}
	return idx;
}

int unique(int num) {
	
	int digits[10] = {0,0,0,0,0,0,0,0,0,0};
	int n = num;

	while (n > 0) {
		
		if (n % 10 == 0) {
			return 0;
		}
		if (!digits[n % 10]) {
			digits[n % 10] = 1;		
		} else {
			return 0;
		}
		n /= 10;
	}	

	return 1; 
}

int contains(int *list, int n) {
	int i;
	for (i = 0; i < 15120; i++) {
		if (n == list[i]) return 1;
	}
	return 0;
}

void isPandigital(int *list, int *perm) {
	
	int i,p;
	int p11 = 0;
	int p21 = 0;
	int p12 = 0;
	int p22 = 0;
	int p13 = 0;
	int p23 = 0;
	int p14 = 0;
	int p24 = 0;

	p11 = perm[0];
	for (i = 4; i >= 1; i--) {
		p21 += perm[i]*((int)pow(10.0,4.0-i)); 
	}
	//printf("p11 is %d while p21 is %d\n",p11,p21);	
	p = p11*p21;
	//printf("p is %d\n",p);
	
	if (allDigits(p11,p21,p)) {
		//printf("p11 and p21 and p make it pandigital\n");
		if (!contains(list, p) && p < 10000)
			list[list_idx++] = p;
	}

	for (i = 1; i >= 0; i--) {
		p12 += perm[i]*((int)pow(10.0,1.0-i));
	}
	for (i = 4; i >= 2; i--) {
		p22 += perm[i]*((int)pow(10.0,4.0-i));
	}	
	//printf("p12 is %d and p22 is %d\n",p12,p22);
	p = p12*p22;
	//printf("p is now %d\n", p);

	if (allDigits(p12,p22,p)) {
		//printf("p12 and p22 and p make it pandigital\n");
		if (!contains(list,p) && p < 10000) 
			list[list_idx++] = p;
	}

	for (i = 2; i >= 0; i--) {
		p13 += perm[i]*((int)pow(10.0,2.0-i));
	}
	for (i = 4; i >= 3; i--) {
		p23 += perm[i]*((int)pow(10.0,4.0-i));
	}	
	//printf("p13 is %d and p23 is %d\n",p13,p23);
	p = p13*p23;
	//printf("p is now %d\n", p);

	if (allDigits(p13,p23,p)) {
		//printf("p13 and p23 and p make it pandigital\n");
		if (!contains(list,p) && p < 10000)
			list[list_idx++] = p;
	}

	for (i = 3; i >= 0; i--) {
		p14 += perm[i]*((int)pow(10.0,3.0-i));
	}
	p24 = perm[4];	

	//printf("p14 is %d and p24 is %d\n",p14,p24);
	p = p14*p24;
	//printf("p is now %d\n", p);

	if (allDigits(p14,p24,p)) {
		//printf("p14 and p24 and p make it pandigital\n");
		if (!contains(list,p) && p < 10000)
			list[list_idx++] = p;
	}
}

int allDigits(int p1, int p2, int product) {

	int i;
	int digits[10] = {0,0,0,0,0,0,0,0,0,0};
	int n1 = p1;
	int n2 = p2;
	int p = product;
	
	while (n1 > 0) {
		
		digits[n1 % 10] = 1;
		n1 /= 10;
	}

	while (n2 > 0) {
		
		digits[n2 % 10] = 1;
		n2 /= 10;
	}	

	while (p > 0) {
	
		digits[p % 10] = 1;
		p /= 10;
	}
	
	if (digits[0]) return 0;

	for (i = 1; i < 10; i++) {
		if (!digits[i]) return 0;
	} 
	
	return 1;
}
