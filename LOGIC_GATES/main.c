#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    char str1[65] = {"\0"};
    char str2[65] = {"\0"};
    int count = 1;
    for (int i = 0; i < n; i++) {
        char input_name[9];
        char input_signal[65];
        scanf("%s%s", input_name, input_signal);
        if (count == 1)
        {
            strcpy(str1, input_signal);
            count++;
        }
        else
            strcpy(str2, input_signal);
    }
    char *oo;
    for (int i = 0; i < m; i++) {
        char output_name[9];
        char type[9];
        char input_name_1[9];
        char input_name_2[9];
        scanf("%s%s%s%s", output_name, type, input_name_1, input_name_2);
        printf("%s ", output_name);
        oo = strtok(type, " ");
        //---------------8<------------------
        //the AND gate
        if (!strcmp(oo, "AND"))
        {
            for (int i = 0;str1[i]; i++)
            {
                if (str1[i] == '-' && str2[i] == '-')
                    printf("-");
                else
                    printf("_");
            }
            printf("\n");
        }
        //---------------8<------------------
        //the OR gate
        else if (!strcmp(oo, "OR"))
        {
            for (int i = 0;str1[i]; i++)
            {
                if (str1[i] == '_' && str2[i] == '_')
                    printf("_");
                else
                    printf("-");
            }
            printf("\n");
        }
        //---------------8<------------------
        //the XOR gate
        else if (!strcmp(oo, "XOR"))
        {
            for (int i = 0;str1[i]; i++)
            {
                if ((str1[i] == '-' && str2[i] == '_') || (str1[i] == '_' && str2[i] == '-'))
                    printf("-");
                else
                    printf("_");
            }
            printf("\n");
        }
        //---------------8<------------------
        //the NAND gate
        if (!strcmp(oo, "NAND"))
        {
            for (int i = 0;str1[i]; i++)
            {
                if (str1[i] == '-')
                    printf("_");
                else
                    printf("-");
            }
            printf("\n");
        }
    }

    return 0;
}