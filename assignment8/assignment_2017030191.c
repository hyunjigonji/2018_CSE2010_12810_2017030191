#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ELEMENTS 100000
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)
#define SWAP(a,b,c) ((c) = (a), (a) = (b), (b) = (c))

typedef struct{
    char name[100];
    int korean;
    int english;
    int math;
} student;

student heap[MAX_ELEMENTS];
int n = 0;

int studentComp(student stu1, student stu2);
void adjust(int root, int n);
void mHeapsort();
void insert_max_heap(student stu, int *n);

int main(){
    int num = 0;
    int i = 0;
    int tempKor, tempEng, tempMath;
    char tempName[100];
    scanf("%d",&num);
    
    for(i = 0 ; i < num ; i++){
        scanf("%s %d %d %d",tempName,&tempKor,&tempEng,&tempMath);
        student temp = { "", tempKor, tempEng, tempMath };
        heap[++n] = temp;
        strcpy(heap[n].name,tempName);
    }
    mHeapsort();
    
    for(i = n ; i > 0 ; i--){
        printf("%s\n",heap[i].name);
    }
    
    return 0;
}

int studentComp(student stu1, student stu2){
    if(stu1.korean != stu2.korean){
        return (stu1.korean > stu2.korean ? -1 : 1);
    }
    else{
        if(stu1.english != stu2.english){
            return (stu1.english < stu2.english ? -1 : 1);
        }
        else{
            if(stu1.math != stu2.math){
                return (stu1.math > stu2.math ? -1 : 1);
            }
            else return strcmp(stu1.name,stu2.name);
        }
    }
}

void adjust(int root, int n){
    int child;
    student rootStu = heap[root];
    child = 2*root;
    
    while(child <= n){
        if((child < n) && (studentComp(heap[child], heap[child+1]) > 0)){
            child++;
        }
        if(studentComp(rootStu, heap[child]) < 0){
            break;
        }
        else{
            heap[child/2] = heap[child];
            child *= 2;
        }
    }
    heap[child/2] = rootStu;
}

void mHeapsort(){
    int i;
    student temp;
    
    for(i = n/2 ; i > 0 ; i--){
        adjust(i,n);
    }
    for(i = n-1 ; i > 0 ; i--){
        SWAP(heap[1], heap[i+1], temp);
        adjust(1,i);
    }
}
