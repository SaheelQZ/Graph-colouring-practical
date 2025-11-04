#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0,1,1,0,1}, 
    {1,0,1,1,0},
    {1,1,0,1,0},
    {0,1,1,0,1},
    {1,0,0,1,0}
};

int color[V];

int isSafe(int v, int c){
    for(int i = 0; i < V; i++){
        if(graph[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoringUtil(int m, int v){
    if(v == V)
        return 1;

    for(int c = 1; c <= m; c++){
        if(isSafe(v, c)){
            color[v] = c;

            if(graphColoringUtil(m, v + 1))
                return 1;

            color[v] = 0;
        }
    }
    return 0;
}

void printSolution(){
    printf("Vertex\tColor(Frequency)\n");
    for(int i = 0; i < V; i++)
        printf("%d\t%d\n", i, color[i]);
}

int graphColoring(int m){
    for(int i = 0; i < V; i++)
        color[i] = 0;

    if(graphColoringUtil(m, 0) == 0){
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution();
    return 1;
}

int main(){
    int m;
    printf("Enter number of colors (frequencies) to use: ");
    scanf("%d", &m);

    graphColoring(m);
    return 0;
}