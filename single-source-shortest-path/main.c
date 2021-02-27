#include <stdio.h>

#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[])
{
    int i, u, count, w, flag[10], min;
    for(i = 1; i <= n ; i++)
        flag[i] = 0, dist[i] = cost[v][i];
    count=2;
    while(count <= n)
    {
        min=99;
        for( w = 1; w <= n; w++)
            if(dist[w]<min && !flag[w])
                min = dist[w], u = w;
        flag[u] = 1;
        count++;
        for( w = 1 ; w <= n; w++)
        if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
        dist[w]=dist[u]+cost[u][w];
        
    }
}

void Bellf(int n, int E, int v, int cost[10][10], int dist[]) 
{ 
    for (int i = 0; i < n; i++) 
        dist[i] = infinity; 
        
    dist[v] = 0; 
 
    for (int i = 0; i < n - 1; i++) 
    { 
  
        for (int j = 0; j < E; j++) 
        { 
            if (dist[cost[j][0]] + cost[j][2] < dist[cost[j][1]]) 
                dist[cost[j][1]] =  dist[cost[j][0]] + cost[j][2]; 
        } 
    } 
  
    for (int i = 0; i < E; i++) 
    { 
        int x = cost[i][0]; 
        int y = cost[i][1]; 
        int weight = cost[i][2]; 
        if (dist[x] != infinity && dist[x] + weight < dist[y]) 
            printf("Graph contains negative weight cycle"); 
    } 
  
}

void main()
{
    int n, v, i, j, cost[10][10], dist[10];
    
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("\n Enter the cost matrix:\n");
    for(i = 1; i <= n; i++ )
        for( j= 1; j <= n; j++ )
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = infinity;
        }
    
    printf("\n Enter the source of matrix: ");
    scanf("%d", &v);
    
    int opt, E;
    printf(" Choose the Algorithm among: ");
    printf("\n 1) Dijkstra’s algorithm");
    printf("\n 2) Bellman-Ford's algorithm");
    printf("\n Enter Your Option: ");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1: dij(n, v, cost, dist);
        break;
        case 2:
            printf("No of Edges: ");
            scanf("%d", &E);
            Bellf(n, E, v, cost, dist);
        break;
        default : printf("Wrong input");
    }
            
    printf("\n Shortest path: \n");
    for(i=1 ; i<=n ; i++)
        if(i != v)
            printf("%d -> %d, cost = %d \n", v, i, dist[i]);
}
