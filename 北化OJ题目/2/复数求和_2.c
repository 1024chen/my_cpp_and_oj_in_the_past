#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define MaxLength 99
int length = 0;

typedef struct LinkedList
{
    int real;
    int imag;
    struct LinkedList *next;
} list;

int InitLinkedList(list *L)
{
    L->imag = 0;
    L->real = 0;
    L->next = NULL;
    return OK;
}

int AddNode(list *L, int real, int imag)
{
    list *ls, *lp;
    ls = (list *)malloc(sizeof(list));
    ls->real = real;
    ls->imag = imag;
    ls->next = NULL;

    lp = L;
    while (lp->next != NULL)
    {
        lp = lp->next;
    }
    lp->next = ls;
    length++;
    return OK;
}

void OutPutList(list *L)
{
    list *lp;
    int real_sum = 0, imag_sum = 0;
    lp = L;
    do
    {
        real_sum += lp->real;
        imag_sum += lp->imag;
        //printf("%d+%d*i\n", lp->real, lp->imag);
        lp = lp->next;
    } while (lp != NULL);
    printf("%d+%di\n", real_sum, imag_sum);
}

int main()
{
    int line;
    int real, imag;
    list L;
    InitLinkedList(&L);
    scanf("%d", &line);
    if (line > 0)
    {
        for (int i = 0; i < line; i++)
        {
            scanf("%d%d", &real, &imag);
            AddNode(&L, real, imag);
        }

        OutPutList(&L);
    }
    return 0;
}