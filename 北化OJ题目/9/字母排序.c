#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int char_stat[26];
    int n;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char char_set[100000];
        for (int i = 0; i < 26; i++)
        {
            char_stat[i] = 0;
        }
        scanf("%s", char_set);
        for (int i = 0; char_set[i]!='\0'; i++)
        {
            char_stat[char_set[i] - 97]++;
        }

        for (int i = 0; i < 26; i++)
        {
            int ch = i + 97;
            for (int j = char_stat[i]; j > 0; j--)
            {
                printf("%c", ch);
            }
        }
        printf("\n");
    }
    
    return 0;
}
