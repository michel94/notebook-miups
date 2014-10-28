// Calculates area and perimeter of union of rectangles.

struct {
	int x1, y1, x2, y2;
}typedef Rect;

bool garden[2005][2005];
Rect rects[1005];
int xs[2005];
int ys[2005];
int mx[32670];
int my[32670];

int main(){
	int n, i=1, x, y, xi, xf, yi, yf;
	//bool tx[33000]; bool ty[33000];
	xs[0] = 0;
	ys[0] = 0;
	while(scanf("%d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2)!= EOF ){
		xs[2*i] = rects[i].x1;
		xs[2*i+1] = rects[i].x2;
		ys[2*i] = rects[i].y1;
		ys[2*i+1] = rects[i].y2;
		i++;
	}
	n = i;
	sort(xs, xs + 2*n);
	sort(ys, ys + 2*n);
	for(i=0; i<2*n; i++){
		mx[xs[i]] = i;
		my[ys[i]] = i;
	}
	memset(garden, 0, sizeof(garden));
	for(i=0; i<n; i++){
		xi = mx[rects[i].x1];
		xf = mx[rects[i].x2];
		yi = my[rects[i].y1];
		yf = my[rects[i].y2];
		//printf("%d %d %d %d\n", xi, yi, xf, yf);
		for(y=yi; y<yf; y++)
			memset(garden[y] + xi, true, xf-xi);
	}
	int a=0, p=0;
	for(x=1; x<2*n+1; x++){
		for(y=1; y<2*n+1; y++){
			//printf("%d", garden[y][x]);
			if(garden[y][x]){
				a += (xs[x+1] - xs[x]) * (ys[y+1] - ys[y]);

				if(!garden[y][x-1])
					p += ys[y+1] - ys[y];
				if(!garden[y][x+1])
					p += ys[y+1] - ys[y];
				if(!garden[y-1][x])
					p += xs[x+1] - xs[x];
				if(!garden[y+1][x])
					p += xs[x+1] - xs[x];

			}
		}
	}
	printf("%d %d\n", a, p);

	return 0;
}
