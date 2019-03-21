#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack* Stack;

struct stack{
    char* array;
    int size;
    int top;
};

Stack createStack(int arraySize){
    Stack S = (Stack)malloc(sizeof(struct stack));
    S->size = arraySize;
    S->top = -1;
    S->array = (char*)malloc(sizeof(char)*arraySize);
    return S;
}

Stack makeEmptyStack(Stack S){
    for(int i = 0 ; i < S->size ; i++){
        S->array[i] = ' ';
    }
    S->top = -1;
    return S;
}

int isEmpty(Stack S){
    if(S->top == -1) return 1;
    else return 0;
}

void push(char X, Stack S){
    S->top++;
    S->array[S->top] = X;
}

char pop(Stack S){
    char word = S->array[S->top];
    S->top--;
    return word;
}

void deleteStack(Stack S){
    free(S);
}

int main(){
    Stack st = createStack(200);
    char print[105];
    print[0] = '\0';
    int dec = 0;
    while(1){
        char word; scanf("%c",&word);
        if(word == '('){
            push(word,st);
        }
        if(word == ')'){
            if(isEmpty(st)){
                printf("wrong.%s\n",print);
                dec = 1;
            }
            else{
                while(1){
                    char t = pop(st);
                    if(t == '(') break;
                    int index = 0;
                    for(int i = 0 ; i < 105 ; i++){
                        if(print[i] == '\0'){
                            index = i;
                            print[i] = ' ';
                            break;
                        }
                    }
                    print[index+1] = t;
                    print[index+2] = '\0';
                }
            }
        }
        if(isalpha(word)){
            if(isEmpty(st)){
                int index = 0;
                for(int i = 0 ; i < 105 ; i++){
                    if(print[i] == '\0'){
                        index = i;
                        print[i] = ' ';
                        break;
                    }
                }
                print[index+1] = word;
                print[index+2] = '\0';
            }
            else{
                push(word,st);
            }
        }
        if(word == '#'){
            if(isEmpty(st) && !dec) {
                printf("right.%s\n",print);
            }
            else if(isEmpty(st) && dec) dec = 0;
            else printf("wrong.%s\n",print);
            makeEmptyStack(st);
            print[0] = '\0';
        }
        if(word == '!'){
            break;
        }
    }
    deleteStack(st);

    return 0;
}
