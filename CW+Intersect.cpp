// Art Gallery Problem - Solution each diagonal must intersect all diagonals.

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

struct {
	int x, y;
}typedef Point;

bool cmp(const Point &a, const Point &b){
	if(a.y < b.y)
		return true;
	else if(a.y == b.y)
		return a.x < b.x;
	return false;
}

Point points[15];
int dp[10][10];
int n;

inline bool cw(int a, int b, int c){
	return (points[b].x * points[c].y + points[c].x * points[a].y + points[a].x * points[b].y)
	- (points[b].x * points[a].y + points[c].x * points[b].y + points[a].x * points[c].y) > 0;
}

inline int intersect(int a, int b, int c, int d){
	return cw(a,c,d) != cw(b,c,d) && cw(a,b,c) != cw(a,b,d);
}

int intersect_inside(int p1, int p2){
	int i, j;
	if(dp[p1][p2])
		return 1;
	for(i=0; i<n; i++){
		for(j=i+2; j<n+i-1 && j%n > i; j++){
			if(p1 != i && p2 != i && p1 != j && p2 != j){
				//printf("%d %d %d %d\n", p1, p2, i, j);
				if(intersect(p1, p2, i, j)){
					dp[i][j] = 1;
					return 1;
				}
			}

		}
	}
	return 0;

}

int main(){
	int i, j, r;
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		for(i=0; i<n; i++)
			scanf("%d %d", &points[i].x, &points[i].y);

		r=0;
		memset(dp, 0, sizeof(dp));
		for(i=0; i<n; i++){
			for(j=i+2; j<n+i-1 && j%n > i; j++){
				r = intersect_inside(i, j%n);
				if(r == 0){
					break;
				}
			}
			if(r==0)
				break;
		}
		
		if(r == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;

}
