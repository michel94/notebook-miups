// Count articulation points of a graph

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct{
	vector<int> edges;
	int dfs;
	int low;
}typedef Node;

int n;
Node graph[805];
bool vis[805];

int d;
int INF=100000;
int best, count;

int min(int a, int b){
	return a < b ? a : b;
}

void dfs(int node){
	int i, neigh;
	vis[node] = true;
	graph[node].dfs = d++;
	graph[node].low = graph[node].dfs;
	for(i=0; i<(int)graph[node].edges.size(); i++){
		neigh = graph[node].edges[i];
		if(!vis[neigh]){
			dfs(neigh);
			graph[node].low = min(graph[node].low, graph[neigh].low);
			if(graph[node].dfs>1){
				if(graph[neigh].low >= graph[node].dfs && graph[node].edges.size() > 1)
					count++;
			}else{
				if(graph[neigh].dfs > 2){
					count++;
				}
			}
			
		}else{
			graph[node].low = min(graph[node].low, graph[neigh].dfs);
		}
			
	}

}

int main(){
	int i, j, v;

	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		printf("%d\n", n);
		for(i=0; i<n; i++){
			scanf("%d", &j);
			printf("%d\n", j);
			while(getchar() != '\n'){
				scanf("%d", &v);
				graph[j].edges.push_back(v);
				graph[v].edges.push_back(j);
				printf("%d ", v);
			}
			putchar('\n');
		}

		d=1;
		memset(vis, false, sizeof(vis));
		count=0;
		for(i=1; i<=n; i++)
			if(!vis[i])
				dfs(i);

		printf("%d\n", count);
		
	}
	return 0;
}
