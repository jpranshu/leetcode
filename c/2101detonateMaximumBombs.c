typedef struct Node{
    int index;
    struct Node* next;
}Node;

int range(int** bombs,int ref,int check){
    long long x1,y1,x2,y2,r1;
    
    x1=bombs[ref][0];
    x2=bombs[check][0];
    y1=bombs[ref][1];
    y2=bombs[check][1];
    r1=bombs[ref][2];

    long long dist,radius;
    dist=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    radius=r1*r1;

    if(dist<=radius)
        return 1;
    return 0;
}

Node **buildList(int **bombs,int bombSize){
    int i, j;
    Node **list = (Node**) calloc(bombSize, sizeof(Node*));
    Node *temp;

    for (i = 0; i < bombSize; ++i) {
        for (j = 0; j < bombSize; ++j) {
            if (i != j && range(bombs, i, j)) {
                temp = (Node*) malloc(sizeof(Node));
                temp->index = j;
                temp->next = list[i];
                list[i] = temp;
            }
        }
    }
    return list;
}

int dfs(Node **list, int node, int *visited) {
    int detonate= 1;
    Node *ref = list[node];
    int adj;
    visited[node] = 1;

    while (ref!= NULL) {
        adj = ref->index;
        if (!visited[adj])
            detonate += dfs(list, adj, visited);
        ref= ref->next;
    }
    return detonate;
}
int maximumDetonation(int** bombs, int bombsSize, int* bombsColSize){
    int visited[bombsSize];
    Node **list=buildList(bombs,bombsSize);
    int currD=0,maxD=0;
    for (int i = 0; i < bombsSize;i++) {
        memset((void*) visited, 0, bombsSize * sizeof(int));
        currD = dfs(list, i, visited);
        if (currD>maxD)
            maxD = currD;
    }
    return maxD;

}