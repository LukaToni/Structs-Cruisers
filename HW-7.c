#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ladja{
    char *startc;
    char *endc;
    int potovanje;
    int krcanje;
    int izkrcanje;
    struct Ladja *nextc;
}Ladja;

void makeLadja(Ladja **newlad)
{  
     *newlad = malloc(sizeof(Ladja));
    (*newlad) -> startc = malloc(sizeof(char) * 100);
    (*newlad) -> endc = malloc(sizeof(char) * 100);
    (*newlad) -> nextc = NULL;
    (*newlad) -> potovanje = 0;
    (*newlad) -> krcanje = 0;
    (*newlad) -> izkrcanje = 0;
}

void freeLadja(Ladja *newlad)
{
    free(newlad -> endc);
    free(newlad -> startc);
    free(newlad);
}

void sort(Ladja **first, Ladja *nov )
{
    Ladja *current = *first;

    while(current -> nextc != NULL)
    {
        if(strcmp(current->startc, (*first) -> startc) == 0)
        {
       
            if(strcmp((*first) -> startc, nov -> endc) == 0)
            {
                nov -> nextc = *first;
                *first = nov;
                return;
            }
        }

        if(strcmp(current -> endc, nov -> startc) == 0)
        {
            Ladja *temp;
            temp = current -> nextc;
            current -> nextc = nov;
            nov -> nextc = temp;
            return;
        }
        current = current -> nextc;
    }

    if( strcmp(current -> startc, (*first) -> startc) == 0)
        {
            if(strcmp( (*first)->startc, nov -> endc) == 0)
            {
                nov ->nextc = *first;
                *first = nov;
                return;
            }
        }

    current -> nextc = nov;
} 


void dnevi(Ladja *first)
{
    int dan = 0;
    int maxDan=0;

    Ladja *curr = first;

    while(curr!= NULL)//cez vse dneve
    {
        maxDan = maxDan + curr->potovanje;//sestevas
        curr = curr->nextc;
    }
    curr = first;

    char* starP;
    starP = malloc(sizeof(char) * 100);
    char* endP;
    endP = malloc(sizeof(char) * 100);
    int line;
    int people;

    while( scanf("%d", &line) == 1 )
    {
        while(curr != NULL)
        {
            if(curr -> potovanje >= line)
            {
                dan = dan + curr -> potovanje;
                curr = curr -> nextc;
            }
            else
            	break;
        }
        if(line > maxDan)
            printf("%d NAPAKA\n",line);
     
        else
             printf("%d %s - %s %d\n",line, curr->startc, curr->endc, people );
             
        curr = first;
        dan = 0;
    }

}


void dodaj()
{
    Ladja *curr;
    makeLadja(&curr);
    Ladja *first = curr;
    Ladja *nov;
   // puts("Vpisi podatke\n");
    scanf("%s %s %i %i %i", curr -> startc, curr -> endc, &curr -> potovanje, &curr -> krcanje, &curr -> izkrcanje);
    char *line = malloc(sizeof(char)*100);
    while(1)
    {
        //puts("Vpisi podatke\n");
        scanf("%s", line);

        if(strstr(line, "?") != NULL)
            break;

        makeLadja(&nov);
        strcpy(nov->startc,line);
        scanf("%s %i %i %i", nov->endc, &nov->potovanje, &nov->krcanje, &nov->izkrcanje);
        //todo sort
        //printf("%s %s %i %i %i\n", curr->startc, curr->endc, curr->potovanje,curr->krcanje, curr->izkrcanje);
        sort(&first , nov);
        //printf("%s %s %i %i %i\n", first->startc, first->endc, first->potovanje, first->krcanje, first->izkrcanje);
    }
    curr = first;

    dnevi(first);
}


int main()
{
    Ladja *prva;
    printf("pointer: %p\n", prva);
    
    makeLadja(&prva);
    printf("pointer: %p\n", prva);
    
    printf("%i  %i  %i\n",prva -> potovanje, prva -> izkrcanje, prva -> krcanje);
    
    dodaj();

    return 0;
}
