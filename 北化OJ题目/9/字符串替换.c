#include <stdio.h>
#include <stdlib.h>

typedef struct word
{
    char str[101];
    int len;
    int index;
} Word;

void InitWord(Word *w)
{
    w->index = 0;
    int i = 0;
    while (w->str[i] != '\0')
    {
        i++;
    }
    w->len = i;
}

//找到a在s中的第一次,s_index第一次是0
int FindIndexInWords(Word *s, Word *a)
{
    if (s->index >= s->len)
    {
        return -1;
    }

    int i = s->index, j = 0;
    // for ( i = 0; i < s->len; i++)
    // {

    // }

    while (i < s->len && j < a->len)
    {
        if (s->str[i] == a->str[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == a->len)
    {
        s->index = i;
        return i - j;
    }
    else
    {
        s->index = s->len;
        return -1; //没找到
    }
}

void ChangeWords(Word *s, Word *a, Word *b)
{
    int pos=0, i, j;
    //while (s->index < s->len)
    while (1)
    {
        pos = FindIndexInWords(s, a);
        if (pos == -1)
        {
            return;
        }
        i = 0;
        while (i < b->len)
        {
            s->str[pos] = b->str[i];
            pos++;
            i++;
        }
    }
}

void OutputWords(Word *s)
{
    printf("%s",s->str);
}

int main(int argc, char const *argv[])
{
    Word s, a, b;
    gets(s.str);
    gets(a.str);
    gets(b.str);
    InitWord(&s);
    InitWord(&a);
    InitWord(&b);
    //printf("%d", FindIndexInWords(&s, &a));
    ChangeWords(&s, &a, &b);
    OutputWords(&s);
    return 0;
}
