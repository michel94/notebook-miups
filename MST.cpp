// Connect disconnected graphs with weighted edges - the weight is the distance between each node (each node has x, y coordinates)
// Calculate the MST

struct Edge{
	int a, b;
	double w;
	bool operator<(const struct Edge& other) const{
        return other.w < w;
    }
};
int coord[755][2];
int parents[755];

int parentU(int a){
	if(parents[a] != a)
		parents[a] = parentU(parents[a]);
	return parents[a];
}
int findu(int a, int b){
	return parentU(a) == parentU(b);
}
void uni(int a, int b){
	parents[parentU(a)] = parents[parentU(b)];
}
double dist(int i, int j){
	return sqrt( (double)pow((double)coord[i][0]-coord[j][0], 2) + (double)pow((double)coord[i][1]-coord[j][1], 2) );
}

int main(){
	int n, m, i, j, n1, n2;
	double cost;
	while(scanf("%d", &n) != EOF){
		for(i=1; i<=n; i++){
			scanf("%d %d", &coord[i][0], &coord[i][1]);
			parents[i] = i;
		}
		cost=0;
		scanf("%d", &m);
		for(i=0; i<m; i++){
			scanf("%d %d", &n1, &n2);
			if(!findu(n1, n2)){
				uni(n1, n2);
			}
		}
		priority_queue<Edge> q;
		Edge ed;
		for(i=1; i<=n; i++){
			for(j=i+1; j<=n; j++){
				ed.a = i;
				ed.b = j;
				ed.w = dist(ed.a, ed.b);
				q.push(ed);
			}
		}
		while(!q.empty()){
            ed = q.top(); q.pop();
			if(!findu(ed.a, ed.b)){
				uni(ed.a, ed.b);
				cost += dist(ed.a, ed.b);
			}
		}
		printf("%.2lf\n", cost);
	}
}
