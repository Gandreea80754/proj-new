#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 3

typedef struct DATA{
    char code[11];
    char *name;
    int age;
    struct DATA *pNext;
}DATA;

DATA *readFile(DATA*); /// read 3 records from file F1
DATA *addData(DATA*); /// read 1 extra record from file F2
void printData(DATA*);/// print all the records

int main(void){
    DATA *data = (DATA*)malloc(sizeof(DATA)); /// allocate memory for 3 records
    DATA *head = (DATA*)malloc(sizeof(DATA));
    data = readFile(data);
    head = addData(data);
    printData(head);

    return 0;
}

DATA* addData(DATA* d){
    int i;
	FILE *f;
	f = fopen("F2.txt", "r");
	DATA *temp;
	temp =(DATA *)malloc(sizeof(DATA));
    char buf[256];
    fscanf(f, "%s %s %d", temp->code, buf, &temp->age);
    temp->name = malloc(strlen(buf) + 1);
    strcpy(temp->name, buf);
    temp->pNext = d;
    return temp;
}

void printData(DATA* d){
    int i;
    for (i=0;i<ROWS+1;i++){
        printf("%s %s %d\n", d->code, d->name, d->age);
        d = d->pNext;
    }
}

DATA* readFile(DATA *d){
    DATA *root = d;
    int i;
    FILE *f;
    f = fopen("F1.txt", "r");///File to read
    for(i=0;i<ROWS;i++){///Read 3 rows
        char buf[256];///buffer for name
        fscanf(f, "%s %s %d", d->code, buf, &d->age);///read 1 line
        d->name = malloc(strlen(buf) + 1);///find the length of name + terminating character
        strcpy(d->name, buf);///copy name to structure
        d->pNext = (DATA*)malloc(sizeof(DATA));
        d = d->pNext;
    }
    return root;
}
// F1.txt
/*193412IASM Madis 5 6 5 6 5 6 5 6 5 6
195643EARB Stfani 4 6 4 5 5 4 3 5 3 6 3 2
186546MAHM Karl 1 6 3 5 4 4 2 4 2 5 1 3*/
//F2.txt
/*196546TAF Georg 34*/
