// UNION-FIND IMPLEMENTATION

#include <stdio.h>

int parent(int v){
	if(uf[v] == uf[uf[v]]){
		return uf[v];
	}
	uf[v] = parent(uf[v]);
	return uf[v];
}

void uni(int v1, int v2){
	int p1 = parent(v1), p2 = parent(v2);
	uf[p1] = p2;
}

inline int find(int v1, int v2){
	return parent(v1) == parent(v2);
}
