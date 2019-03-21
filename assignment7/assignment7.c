#include <stdio.h>
#define INF 987654321

int dist[1005], visit[1005];
int node[1005][1005];
int n,m;

int dijkstra(int start,int end){
    dist[start] = 0;
    for(int i = 1 ; i <= n ; i++){
        int min = INF;
        int min_v = 0;
        for(int j = 1 ; j <= n ; j++){
            if(visit[j] == 0 && min > dist[j]){
                min = dist[j];
                min_v = j;
            }
        }
        visit[min_v] = 1;
        
        for(int j = 1 ; j <= n ; j++){
            if(dist[j] > dist[min_v] + node[min_v][j]){
                dist[j] = dist[min_v] + node[min_v][j];
            }
        }
    }
    return dist[end];
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            node[i][j] = INF;
        }
    }
    for(int i = 0 ; i < m ; i++){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        if(node[u][v] > w) node[u][v] = w;
    }
    for(int i = 0 ; i <= n ; i++) dist[i] = INF;
    int start,end; scanf("%d %d",&start,&end);
    printf("%d\n", dijkstra(start,end));
    
    return 0;
}

