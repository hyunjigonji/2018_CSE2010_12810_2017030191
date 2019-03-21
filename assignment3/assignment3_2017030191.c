#include <stdio.h>
#include <stdlib.h>

typedef struct node* pNode;
typedef pNode List;
typedef pNode Node;

struct node{
    int value;
    Node next;
};

List makeEmptyList(List L){
    L = (List)malloc(sizeof(struct node));
    L->value = 0;
    L->next = NULL;
    return L;
}

void insert(int v, List L, Node N){
    Node newnode = (Node)malloc(sizeof(struct node));
    newnode->value = v;
    if(N->next){
        newnode->next = N->next;
        
    }
    else{
        newnode->next = NULL;
    }
    N->next = newnode;
}

Node findPrev(int v, List L){
    Node NODE = L;
    while(NODE){
        if(NODE->next->value == v){
            return NODE;
        }
        NODE = NODE->next;
    }
    return NULL;
}

void Delete(int v, List L){
    List LIST = L;
    while(L){
        if(L->value == v){
            findPrev(v,LIST)->next = L->next;
            L->next = NULL;
            free(L);
        }
        L = L->next;
    }
}

Node find(int v, List L){
    Node NODE = L;
    while(NODE){
        if(NODE->value == v){
            return NODE;
        }
        NODE = NODE->next;
    }
    return NULL;
}

void deleteList(List L) {
    Node dummy;
    while (L != NULL) {
        dummy = L;
        L = L->next;
        free(dummy);
    }
    free(L);
}

int main(){
    List list = makeEmptyList(NULL);
    while(1){
        char input; scanf("%c",&input);
        if(input == 'i'){
            int a,b; scanf("%d %d",&a,&b);
            if(b){
                Node findnode = find(b,list);
                if(findnode){
                    insert(a,list,findnode);
                }
                else{
                    printf("Insert error. The %d isn't in the list.\n",b);
                }
            }
            else{
                insert(a,list,list);
            }
        }
        if(input == 'd'){
            int a; scanf("%d",&a);
            Node findnode = find(a,list);
            if(findnode){
                Delete(a,list);
            }
            else{
                printf("Delete error. The %d isn't in the list.\n",a);
            }
        }
        if(input == 'f'){
            int a; scanf("%d",&a);
            Node findnode = find(a,list);
            if(findnode){
                if(findPrev(a,list) == list){
                    printf("The %d is next of The header.\n",a);
                }
                else{
                    printf("The %d is next of The %d.\n",a,findPrev(a,list)->value);
                }
            }
            else{
                printf("Find error. The %d isn't in the list.\n",a);
            }
        }
        if(input == 's'){
            int headvalue = list->value;
            List headptr = list;
            while(headptr){
                if(headptr->value != headvalue){
                    printf("%d ",headptr->value);
                }
                headptr = headptr->next;
            }
            printf("\n");
        }
        if(input == 'e'){
            deleteList(list);
            return 0;
        }
    }
    
    return 0;
}

