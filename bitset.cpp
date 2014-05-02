// BITSET IMPLEMENTATION

#include <stdio.h>

void printset(unsigned int set, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d", set%2);
		set = set >> 1;
	}
	putchar('\n');
}

int isset(unsigned int set, int p){
	return (set >> p) & 0x1;
}

int setp(unsigned int set, int pos){
	set = set | (0x1 << pos);
	return set;
}

int unsetp(unsigned int set, int pos){
	set = set ^ (0x1 << pos);
}
