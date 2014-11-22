#include <utility>
#include <stdio.h>
using namespace std;

int main(){
	pair<int, double> p = pair<int, double>(3, 2.3);
	printf("%d %lf\n", p.first, p.second);
}