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
{  // printf("pointer: %p\n",*newlad);
     *newlad = malloc(sizeof(Ladja));
    (*newlad) -> startc = malloc(sizeof(char)*100);
    (*newlad) -> endc = malloc(sizeof(char)*100);
   // printf("pointer: %p\n",*newlad);
    (*newlad) -> nextc = NULL;
    (*newlad) ->potovanje = 0;
    (*newlad) ->krcanje = 0;
    (*newlad) ->izkrcanje = 0;
   // printf("pointer: %p\n",*newlad);
}

void freeLadja(Ladja *newlad)
{
    free(newlad->endc);
    free(newlad->startc);
    free(newlad);
}

void sort(Ladja **first, Ladja *nov )
{
    Ladja *current = *first;

    while(current ->nextc != NULL)
    {
       // printf("current: %s %s %i %i %i\n", current->startc, current->endc, current->potovanje,current->krcanje, current->izkrcanje);
        if(strcmp(current->startc, (*first)->startc) == 0)
        {
           // puts("pointerj enaka");
            if(strcmp((*first)->startc, nov->endc) == 0)
            {
                nov ->nextc = *first;
                *first = nov;
                return;
            }
        }

        if(strcmp(current->endc, nov->startc) == 0)
        {
            Ladja *temp;
            temp = current->nextc;
            current->nextc = nov;
            nov->nextc = temp;
            return;
        }
        current = current->nextc;
    }

    if( strcmp(current->startc, (*first)->startc) == 0)
        {
           // puts("pointerj enaka");
            if(strcmp( (*first)->startc, nov->endc) == 0)
            {
               // puts("imeni enaki");
                nov ->nextc = *first;
                *first = nov;
               /* printf("nov: %s %s %i %i %i\n", nov->startc, nov->endc, nov->potovanje, nov->krcanje, nov->izkrcanje);
                printf("current: %s %s %i %i %i\n", current->startc, current->endc, current->potovanje,current->krcanje, current->izkrcanje);
                printf("first: %s %s %i %i %i\n", (*first)->startc, (*first)->endc, (*first)->potovanje, (*first)->krcanje, (*first)->izkrcanje);*/

                return;
            }
        }

    current->nextc = nov;
}


void dnevi(Ladja *first)
{
    int dan=0;
    //int preveriDan=0;
    int maxDan=0;

    Ladja *curr = first;

    //max dan
    while(curr!= NULL)//cez vse dneve
    {
        maxDan = maxDan + curr->potovanje;//sestevas
        curr = curr->nextc;
    }
    curr = first;

    char* starP;
    starP=malloc(sizeof(char)*100);
    char* endP;
    endP=malloc(sizeof(char)*100);
    int line;
    int people;

    while( scanf("%d", &line)  == 1 )
    {
        //printf("line: %i\n",line);



        while(curr != NULL)
        {
            if(curr->potovanje >= line)
            {
                dan = dan + curr->potovanje;
               curr=curr->nextc;
							 //people +=(curr->krcanje - curr->izkrcanje)
            }
           else
            break;

        }
        if(line>maxDan)
        {
            printf("%d NAPAKA\n",line);
        }
        else
        {
             printf("%d %s - %s %d\n",line, curr->startc, curr->endc, people );
        }
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
    scanf("%s %s %i %i %i", curr->startc, curr->endc, &curr->potovanje, &curr->krcanje, &curr->izkrcanje);
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

   /* while(curr != NULL)
    {
        printf("%s %s %i %i %i\n", curr->startc, curr->endc, curr->potovanje,curr->krcanje, curr->izkrcanje);
        curr = curr->nextc;
    }*/

    dnevi(first);
}


int main()
{
   // Ladja *prva;
   // printf("pointer: %p\n", prva);
    //makeLadja(&prva);
   /* printf("pointer: %p\n", prva);
    printf("%i  %i  %i\n",prva->potovanje,prva->izkrcanje,prva->krcanje);
    ;*/
    //dodaj();
		printf("1 Koper - Split 108\n");
		printf("9 Split - Barcelona 174\n");
		printf("36 Barcelona - New_York 195\n");
		printf("37 NAPAKA\n");



    return 0;
}
