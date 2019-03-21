#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;
typedef struct node* Tree;

typedef struct node{
    int value;
    Node parent;
    Node leftChild;
    Node rightChild;
} node;

Tree createTree(){
    Tree tmp = (Tree)malloc(sizeof(struct node));
    tmp->value = 0;
    tmp->leftChild = NULL;
    tmp->rightChild = NULL;
    tmp->parent = NULL;
    
    return tmp;
}

int isEmpty(Tree t){
    if(t->rightChild == NULL){
        return 1;
    }
    return 0;
}

Node search(Tree t,int key){
    if(t == NULL) return NULL;
    if(key == t->value) return t;
    else if(key > t->value) return search(t->rightChild,key);
    else if(key < t->value) return search(t->leftChild,key);
    else return t;
}

Node FindMax(Tree t){
    if(t == NULL) return t;
    else if(t->rightChild == NULL) return t;
    else return FindMax(t->rightChild);
}

Node deleteNode(Tree t, int key) {
    Node tmp;
    
    if (t == NULL) {
        printf("Not Found\n");
        return t;
    }
    else if (key < t->value) {
        t->leftChild = deleteNode(t->leftChild, key);
    }
    else if (key > t->value) {
        t->rightChild = deleteNode(t->rightChild, key);
    }
    else if (t->leftChild && t->rightChild) {
        tmp = FindMax(t->leftChild);
        t->value = tmp->value;
        t->leftChild = deleteNode(t->leftChild, t->value);
    }
    else {
        tmp = t;
        if (t->leftChild == NULL) {
            t = t->rightChild;
        }
        else if (t->rightChild == NULL) {
            t = t->leftChild;
        }
        free(tmp);
    }
    return t;
}

void insertNode(Tree t,int key){
    Node parent = { 0 };
    Node tmp;
    int dif = 0; // dif가 0이면 parent의 왼쪽자식, 1이면 parent의 오른쪽자식
    if(isEmpty(t)){
        tmp = createTree();
        tmp->value = key;
        tmp->parent = t;
        t->rightChild = tmp;
        return;
    }
    else{
        while(t){
            if(key == t->value) break;
            parent = t;
            if(key > parent->value){
                t = parent->rightChild;
                dif = 1;
            }
            else{
                t = parent->leftChild;
                dif = 0;
            }
        }
        t = createTree();
        t->value = key;
        t->parent = parent;
        if(dif == 1){
            parent->rightChild = t;
            t->leftChild = NULL;
            t->rightChild = NULL;
        }
        else{
            parent->leftChild = t;
            t->leftChild = NULL;
            t->rightChild = NULL;
        }
        return;
    }
}

void showAll(Tree t){
    if(t){
        showAll(t->leftChild);
        if(t->value != 0) printf("%d ",t->value);
        showAll(t->rightChild);
    }
}

int getHeight(Tree t,int key){
    if(t == NULL){
        return 0;
    }
    else{
        int leftHeight = getHeight(t->leftChild, key);
        int rightHeight = getHeight(t->rightChild, key);
        return 1+(leftHeight>rightHeight ? leftHeight : rightHeight);
    }
}

int main(){
    Tree T = createTree();
    while(1){
        char input; scanf("%c",&input);
        if(input == 'i'){
                int x; scanf("%d",&x);
                insertNode(T, x);
        }
        if(input == 'd'){
                int y; scanf("%d",&y);
                deleteNode(T, y);
        }
        if(input == 'h'){
                int z; scanf("%d",&z);
                Node current = search(T,z);
                if(current != NULL) printf("The height of the node (%d) is %d\n",z,getHeight(current, z)-1);
                else printf("Not found\n");
        }
        if(input == 's'){
                showAll(T);
                printf("\n");
        }
        if(input == 'e') return 0;
    }
    return 0;
}

