#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct{
	int profit, spendings;
}typedef biz;

bool sortBizs(const biz &a, const biz &b){
	return a.profit - a.spendings < b.profit - b.spendings;
}

int main(){
	int i;
	

	int intarray[100];
	intarray[0] = 3;
	intarray[1] = 5;
	intarray[2] = 1;
	intarray[3] = 0;
	sort(intarray, intarray + 4);
	for(i=0; i<4; i++) printf("%d\n", intarray[i]);
	putchar('\n');
	sort(intarray, intarray + 4, greater<int>());
	for(i=0; i<4; i++) printf("%d\n", intarray[i]);
	putchar('\n');


	vector<string> stringvector;
	stringvector.push_back("ancel");
	stringvector.push_back("coxo");
	stringvector.push_back("nabo");
	sort(stringvector.begin(), stringvector.end());
	for(i=0; i<3; i++) cout << stringvector[i] << endl;
	putchar('\n');


	biz bizs[5];
	bizs[2].profit = 15;
	bizs[2].spendings = 3;
	bizs[0].profit = 3;
	bizs[0].spendings = 5;
	bizs[1].profit = 10;
	bizs[1].spendings = 5;
	sort(bizs, bizs + 3, sortBizs);
	for(i=0; i<3; i++)
		printf("biz: profit: %d, spendings: %d\n", bizs[i].profit, bizs[i].spendings);

	return 0;
}