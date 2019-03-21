#include <stdio.h>
#define MAX 1001

int n,m,v;

int adj[MAX][MAX];
int visit[MAX];
int queue[MAX];
int front = -1,rear = -1;

void dfs(int now){
    visit[now] = 1;
    printf("%d ",now);
    for(int j = 1 ; j <= n ; j++){
        int next = j;
        if(adj[now][next] == 1){
            if(visit[next] == 0){
                visit[next] = 1;
                dfs(next);
            }
        }
    }
}

void bfs(int start){
    queue[++rear] = start;
    visit[start] = 1;
    while(front != rear){
        int now = queue[++front];
        printf("%d ",now);
        for(int j = 1 ; j <= n ; j++){
            int next = j;
            if(adj[now][next] == 1){
                if(visit[next] == 0){
                    queue[++rear] = next;
                    visit[next] = 1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&v);
    for(int i = 0 ; i < m ; i++){
        int a,b; scanf("%d %d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }
    dfs(v);
    printf("\n");
    for(int i = 0 ; i < MAX ; i++) visit[i] = 0;
    bfs(v);
    return 0;
}
