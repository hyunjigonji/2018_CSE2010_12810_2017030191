#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee {
    char name[10];
    int age;
    int salary;
    char department[20];
} Employee;

int number;
void insert(Employee* people, char* word);
int avgBenefit(Employee* people, char* word);
void delete_one(Employee* people, char* word);
int find(Employee* people, char* word);
void inform(Employee* people, char* word);

Employee Empty = { "",0,0,"" };

int main() {
    char input[100];
    char *word;
    Employee *people;
    int flag = 0;
    
    fgets(input, sizeof(input), stdin);
    word = strtok(input, " ");
    
    if (word == NULL) return 0;
    if (strcmp(word, "set") == 0) {
        word = strtok(NULL, " ");
        number = atoi(word);
        people = (Employee*)malloc(sizeof(Employee) * number);
        flag = 1;
    }
    if (!flag) return 0;
    for (int i = 0; i < number ; i++) {
        people[i] = Empty;
    }
    while (1) {
        fgets(input, sizeof(input), stdin);
        word = strtok(input, " ");
        if (word == NULL) break;
        if (strcmp(word, "insert") == 0) {
            insert(people, word);
        }
        else if (strcmp(word, "delete") == 0) {
            delete_one(people, word);
        }
        else if (strcmp(word, "find") == 0) {
            printf("%d\n", find(people, word));
        }
        else if (strcmp(word, "inform") == 0) {
            inform(people, word);
        }
        else if (strcmp(word, "avg") == 0)
            printf("%d\n", avgBenefit(people, word));
    }
    free(people);
    return 0;
}

void insert(Employee* people, char* word) {
    int i;
    for (i = 0; i < number ; i++) {
        if (strcmp(people[i].name, "") == 0) {
            break;
        }
    }
    if (i == number) {
        printf("Not enough space\n");
        return;
    }
    word = strtok(NULL, " ");
    strcpy(people[i].name, word);
    
    word = strtok(NULL, " ");
    people[i].age = atoi(word);
    
    word = strtok(NULL, " ");
    people[i].salary = atoi(word);
    
    word = strtok(NULL, "\n");
    strcpy(people[i].department, word);
}

void delete_one(Employee* people, char* word) {
    int i;
    int dec = 1;
    word = strtok(NULL, "\n");
    for (i = 0; i < number; i++) {
        if (strcmp(people[i].name, word) == 0) {
            people[i] = Empty;
            dec = 0;
        }
    }
    if (i == number && dec) {
        printf("Not found\n");
        return;
    }
}

int find(Employee* people, char* word) {
    int i;
    word = strtok(NULL, "\n");
    for (i = 0; i < number; i++) {
        if (strcmp(people[i].name, word) == 0) {
            break;
        }
    }
    if (i == number) return -1;
    else return i;
}

void inform(Employee* people, char* word) {
    int i;
    int dec = 1;
    word = strtok(NULL, "\n");
    for (i = 0; i < number; i++) {
        if (strcmp(people[i].name, word) == 0) {
            printf("%s %d %d %s\n", people[i].name, people[i].age, people[i].salary, people[i].department);
            dec = 0;
        }
    }
    if(dec){
        printf("Not found\n");
        return;
    }
}

int avgBenefit(Employee* people, char* word) {
    word = strtok(NULL, "\n");
    int num = 0;
    int avg = 0;
    for (int i = 0; i < number; i++) {
        if (strcmp(people[i].department, word) == 0) {
            num++;
            avg += people[i].salary;
        }
    }
    if (avg) avg /= num;
    return avg;
}
