#include <stdio.h>
#include <queue>
using namespace std;

struct{
	int x, y;
}typedef Point;

bool operator<(const Point& a, const Point& b) {
	if(a.y < b.y)
		return true;
	else if(a.y == b.y)
		return a.x < b.y;
	return false;
}

priority_queue<Point> pq;

int main(){
	Point p;
	p.x = 3; p.y = 2; pq.push(p);
	p.x = 3; p.y = 4; pq.push(p);
	p.x = 3; p.y = 3; pq.push(p);
	p.x = 2; p.y = 3; pq.push(p);
	p.x = 1; p.y = 4; pq.push(p);
	p.x = 1; p.y = 3; pq.push(p);
	while(!pq.empty()){
		p = pq.top();
		printf("%d %d\n", p.y, p.x);
		pq.pop();
	}
/*	4 1
	4 3
	3 3
	3 1
	3 2
	2 3	*/
}