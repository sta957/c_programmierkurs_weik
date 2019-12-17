#include <stdio.h>
#include <stdlib.h>

struct knoten{ // create new structure{
    int key; // value of struct element
    struct knoten *next; // pointer to next element in queue
};

typedef struct knoten* Queue_; //type Queue is pointer on strucutre knoten
Queue_ warten; // define warten as pointer on structure knoten

char* alloc (int n){ // function to reserve memory
    char* mem = malloc(n); // mem contains address of new memor<
    if(mem == NULL){ // if memory is NULL -> no reservation possible
        printf("Kein freier Speicher!\n");
        exit(1);
    }
    return mem; // return address of reserved memory
}

void qinit(){ // initialize structure
    warten = NULL; // warten as nullpointer - last element in queue
    printf("Die Warteschlange wurde erzeugt\n");
    return;
}

int isempty(void){
    int leer = 0;
    if(warten == NULL){ // if warten is nullpointer -> list is empty
        leer = 1;
    }
    return leer; // 1 = empty, 0 = not empty
}

void printQueue(void){ // print last element in queue
    Queue_ var_warten; // second variable for queue
    var_warten = warten;

    if(isempty()){ // when queue is empty
        printf("Liste ist leer\n");
        return;
    }

    for(; var_warten->next != NULL; var_warten = var_warten->next){ // for each element in queue
        printf("%d\n",var_warten->key);
    }
    if(var_warten->next == NULL){
        printf("%d\n",var_warten->key); // print last element
    }
    return;
}

void enqueue(int element){ // add new element with key
    Queue_ new_element;
    Queue_ *var_warten; // create poniter *var_warten
    var_warten = &warten; // set pointer to warten
    if (isempty()){ // if empty -> set as first element
        warten = (Queue_) alloc(sizeof(struct knoten)); // reserve memory for new queue
        warten->key = element; // set key of warten to element
        warten->next = NULL; // next element to NULL (bc. -> first element)
        return;
    }

    while (*var_warten != NULL){ // find last element
       var_warten = &(*var_warten)->next; // set address of active element to address of next element
    }
    new_element = (Queue_) alloc(sizeof(struct knoten)); // reserve memory for new element
    new_element->key = element; // set key of new element to value of element
    new_element->next = NULL; // set next element to NULL
    *var_warten = new_element; // put address of new element in list
    return;
}

int dequeue(void){ // delete first/oldest element
    if(isempty()){
        return -1;
    }

    if(warten->next == NULL){ // if last element -> set as nullpointer
        free(warten); // free memory of warten
        warten = NULL; // set warten to NULL
        return 1;
    }

    Queue_ var_warten; // create new Queue 
    var_warten = warten->next; // var_warten -> next element of warten
    free(warten); // free memory of warten
    warten = var_warten; 
    return 1;
}

int main(){
    int auswahl;
    qinit();
    int n = 0;
    int de = 0;
    while(1){
        printf("\nHauptmenue:\n"
               "1. Anfuegen eines Elementes\n"
               "2. Loeschen und Ausgeben des ersten Elementes \n"
               "3. Ausgeben der Warteschlange\n"
               "4. Beenden des Programmes\n\n"
               "Bitte geben Sie die Ziffer der gewuenschten Funktion ein:\n");
        scanf("%d",&auswahl);

        switch(auswahl){
            case 1 :
                printf("Bitte Key eingeben:\n");
                scanf("%d",&n);
                enqueue(n);
                printf("Das Element wurde der Warteschlange angehangen\n\n");
                break;
            case 2:
                de = dequeue();
                if(de < 0){ // return value of dequeue
                    printf("Die Liste war bereits Leer\n\n");
                }else if(isempty()){
                    printf("Die Liste ist jetzt Leer\n\n");
                }else{
                    printf("Das erste Element ist nun: %d\n\n",warten->key);
                }
                break;
            case 3:
                printf("Liste der Elemente\n");
                printQueue();
                break;
            case 4:
                printf("Programm wird beendet\n");
                exit(1);
            default:
                printf("Bitte eine valide Nummer eingeben\n\n");
        }
    }
}
