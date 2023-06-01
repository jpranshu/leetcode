struct coord{
    int row,col,dist;
};


int isEmpty(int* front,int* rear){
    if(*front==-1)
        return 1;
    return 0;
}
void push(struct coord *queue,int* front,int* rear,struct coord element,int qLen){

    if(*front==-1)
        *front=0;
    *rear=(*rear+1)%qLen;
    queue[*rear]=element;
}
struct coord pop(struct coord* queue, int* front, int* rear,int qLen){
    struct coord element;
    element=queue[*front];
    if(*front==*rear){
        *front=*rear=-1;
    }
    else{
        *front=(*front+1)%qLen;
    }
    return element;
}



int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    struct coord* queue;
    int qLen=gridSize*gridSize;
    queue=malloc(qLen*sizeof(struct coord));
    int front= -1;
    int rear= -1;
    int* fr;
    int* re;
    fr=&front;
    re=&rear;
    
    if(grid[0][0]!=0){
        return -1;
    }

    struct coord element;
    element.row=0;
    element.col=0;
    element.dist=1;
    push(queue,fr,re,element,qLen);
    grid[element.row][element.col]=-1;
    
    while(!isEmpty(fr,re)){
        element=pop(queue,fr,re,qLen);
        printf("%d,%d = %d\n",element.row,element.col,element.dist);
        if((element.col==gridSize-1)&&(element.row==gridSize-1))
            return element.dist;
        struct coord el;
         //1st col
        if(element.col!=0){
            if(element.row!=0){
                if(grid[element.row-1][element.col-1]==0){
                    
                    el.row=element.row-1;
                    el.col=element.col-1;
                    el.dist=element.dist+1;
                    push(queue,fr,re,el,qLen);
                    grid[el.row][el.col]=-1;
                }
            }
            if(grid[element.row][element.col-1]==0){
                
                el.row=element.row;
                el.col=element.col-1;
                el.dist=element.dist+1;
                push(queue,fr,re,el,qLen);
                grid[el.row][el.col]=-1;   
            }            
            if(element.row!=gridSize-1){
                if(grid[element.row+1][element.col-1]==0){
                    
                    el.row=element.row+1;
                    el.col=element.col-1;
                    el.dist=element.dist+1;
                    push(queue,fr,re,el,qLen);
                    grid[el.row][el.col]=-1; 
                }
            }

        }
        //last col
        if(element.col!=gridSize-1){
            if(element.row!=0){
                if(grid[element.row-1][element.col+1]==0){
                    
                    el.row=element.row-1;
                    el.col=element.col+1;
                    el.dist=element.dist+1;
                    push(queue,fr,re,el,qLen);
                    grid[el.row][el.col]=-1;
                }
            }
            if(grid[element.row][element.col+1]==0){
                
                el.row=element.row;
                el.col=element.col+1;
                el.dist=element.dist+1;
                push(queue,fr,re,el,qLen);
                grid[el.row][el.col]=-1;   
            }            
            if(element.row!=gridSize-1){
                if(grid[element.row+1][element.col+1]==0){
                    
                    el.row=element.row+1;
                    el.col=element.col+1;
                    el.dist=element.dist+1;
                    push(queue,fr,re,el,qLen);
                    grid[el.row][el.col]=-1;
                }
            }

        }
//1st row
        if(element.row!=0){
            if(grid[element.row-1][element.col]==0){
                    
                    el.row=element.row-1;
                    el.col=element.col;
                    el.dist=element.dist+1;
                    push(queue,fr,re,el,qLen);
                    grid[el.row][el.col]=-1;
            }
        }
//last row
        if(element.row!=gridSize-1){
            if(grid[element.row+1][element.col]==0){
                    
                    el.row=element.row+1;
                    el.col=element.col;
                    el.dist=element.dist+1;
                    push(queue,fr,re,el,qLen);
                    grid[el.row][el.col]=-1;
            }
        }
    }
    return -1;
}