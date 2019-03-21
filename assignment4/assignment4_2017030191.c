#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 100000
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct{
    int key;
} element;

element heap[MAX_ELEMENTS];
int n = 0;

void insert_min_heap(element item, int *n){
    int i;
    if(HEAP_FULL(*n)) return;
    i = ++(*n);
    int input = abs(item.key), now = heap[i/2].key;
    
    while((i > 1) && (input == now)){
        if(item.key >= heap[i/2].key){
            heap[i] = item;
            return;
        }
        else if(item.key < heap[i/2].key){
            heap[i] = heap[i/2];
            i /= 2;
            now = abs(heap[i/2].key);
        }
        else now = abs(heap[i/2].key);
    }
    
    while((i > 1) && (input < now)){
        heap[i] = heap[i/2];
        i /= 2;
    }
    
    heap[i] = item;
}

element delete_min_heap(int *n){
    element item, temp;
    if(HEAP_EMPTY(*n)) {
        item.key = 0;
        return item;
    }
    item = heap[1];
    temp = heap[(*n)--];
    int parent = 1, child = 2;
    int now = abs(temp.key);
    
    while(child <= *n){
        int leftchild = abs(heap[child].key), rightchild = abs(heap[child+1].key);
        if((child < *n) && (leftchild > rightchild)){
            child++;
            leftchild = abs(heap[child].key);
        }
        else if((child < *n) && leftchild == rightchild){
            if(heap[child].key > heap[child+1].key){
                child++;
                leftchild = abs(heap[child].key);
            }
        }
        if(now <= leftchild){
            while((child < *n) && (heap[child].key < temp.key)){
                heap[parent] = heap[child];
                parent = child;
                child *= 2;
            }
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int input; scanf("%d",&input);
        if(input){
            element one;
            one.key = input;
            insert_min_heap(one, &n);
            //for(int i = 0 ; i <= 6 ; i++) printf("%d ",heap[i].key);
            //printf("\n");
        }else{
            printf("%d\n",delete_min_heap(&n).key);
            //for(int i = 0 ; i <= 6 ; i++) printf("%d ",heap[i].key);
            //printf("\n");
        }
    }
    
    return 0;
}
