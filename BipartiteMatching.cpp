// Week Problem K - Distribuiting gifts between friends, each friend has different likings and there are quantities of each gift (Bipartite Matching with Max Flow(Edmonds-Karp) )

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> graph[1110];
int dist[1110][1110];

int bfs(int st, int end){
	int tree[1110];
	bool vis[1110];
	int neigh, top, i;
	memset(vis, false, sizeof(vis));
	queue<int> q;
	q.push(st);
	tree[st] = st;
	while(!q.empty()){
		top = q.front();
		q.pop();
		if(top == end){
			break;
		}
		for(i=0; i<(int)graph[top].size(); i++){
			neigh = graph[top][i];
			if(dist[top][neigh] > 0 && !vis[neigh]){
				vis[neigh] = true;
				q.push(neigh);
				tree[neigh] = top;
			}
		}
	}
	if(top != end){
		return -1;
	}else{
		int mi = 1000;
		int node = top;
		while(node != st){
			mi = min(dist[tree[node]][node], mi);
			node = tree[node];
		}
		node = top;
		while(node != st){
			dist[tree[node]][node] -= mi;
			dist[node][tree[node]] += mi;
			node = tree[node];
		}
		return mi;
	}

}

int main(){
	int n, m, st = 0, end;
	int i, j, c, np, g;
	scanf("%d %d", &m, &n);
	memset(dist, 0, sizeof(dist));
	for(i=1; i<=m; i++){
		graph[0].push_back(i);
		graph[i].push_back(0);
		dist[0][i] = 1;
		dist[i][0] = 0;
	}
	for(i=1; i<=m; i++){
		scanf("%d", &np);
		for(j=0; j<np; j++){
			scanf("%d", &g);
			graph[i].push_back(g + m);
			graph[g + m].push_back(i);
			dist[i][g+m] = 1;
			dist[g+m][i] = 0;
		}
		
	}
	end = n+m+1;
	for(i=m+1; i<m+1+n; i++){
		scanf("%d", &dist[i][end]);
		dist[end][i] = 0;
		graph[i].push_back(end);
		graph[end].push_back(i);
	}

	int total=0;
	while(1){
		c = bfs(st, end);
		if(c == -1){
			printf("%d\n", total);
			break;
		}
		total += c;
	}

	return 0;

}
