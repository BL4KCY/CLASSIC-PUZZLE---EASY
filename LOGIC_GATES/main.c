#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct inp{
    char *input_name;
    char *input_signal;
    struct inp *next;
} in_list;

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    in_list *input = malloc(sizeof(in_list));
    in_list *input1 = malloc(sizeof(in_list));
    in_list *input2 = malloc(sizeof(in_list));
    in_list *head = input;
    for (int i = 0; i < n; i++) {
        input->input_name = malloc(sizeof(char) * 9);
        input->input_signal = malloc(sizeof(char) * 65);
        input->next = malloc(sizeof(in_list));
        scanf("%s%s", input->input_name, input->input_signal);
        //printf("%s\n", input->input_signal);
        input = input->next;
    }
    char res[65] = {0};
    for (int i = 0; i < m; i++) {
        char output_name[9];
        char type[9];
        char input_name_1[9];
        char input_name_2[9];
        scanf("%s%s%s%s", output_name, type, input_name_1, input_name_2);
        printf("%s ", output_name);
        input = head;
        for (int i = 0; i < n; i++)
        {
            if (!strcmp(input_name_1, input->input_name))
            {
                input1 = input;
                break ;
            }
            input = input->next;
        }
        input = head;
        for (int i = 0; i < n; i++)
        {
            if (!strcmp(input_name_2, input->input_name))
            {
                input2 = input;
                break ;
            }
            input = input->next;
        }
        // printf("%s | ", input2->input_signal);
        // printf("%s", input1->input_signal);
        //-------------------8<---------------------
        //the AND gate
        if (!strcmp(type, "AND"))
        {
            for (int i = 0; input1->input_signal[i]; i++)
            {
                if (input2->input_signal[i] == '-' && input1->input_signal[i] == '-')
                    res[i] = '-';
                else
                    res[i] = '_';
            }
        }
        //-------------------8<---------------------
        //the OR gate
        if (!strcmp(type, "OR"))
        {
            for (int i = 0; input1->input_signal[i]; i++)
            {
                if (input2->input_signal[i] == '-' || input1->input_signal[i] == '-')
                    res[i] = '-';
                else
                    res[i] = '_';
            }
        }
        //-------------------8<---------------------
        //the OR gate
        if (!strcmp(type, "XOR"))
        {
            for (int i = 0; input1->input_signal[i]; i++)
            {
                if ((input2->input_signal[i] == '-' && input1->input_signal[i] == '_') 
                || (input2->input_signal[i] == '_' && input1->input_signal[i] == '-'))
                    res[i] = '-';
                else
                    res[i] = '_';
            }
        }
        //-------------------8<---------------------
        //the OR gate
        if (!strcmp(type, "XOR"))
        {
            for (int i = 0; input1->input_signal[i]; i++)
            {
                if ((input2->input_signal[i] == '-' && input1->input_signal[i] == '_') 
                || (input2->input_signal[i] == '_' && input1->input_signal[i] == '-'))
                    res[i] = '-';
                else
                    res[i] = '_';
            }
        }
        //-------------------8<---------------------
        //the NAND gate
        if (!strcmp(type, "NAND"))
        {
            for (int i = 0; input1->input_signal[i]; i++)
            {
                if (input2->input_signal[i] == '-' || input1->input_signal[i] == '-')
                    res[i] = '_';
                else
                    res[i] = '-';
            }
        }
        //-------------------8<---------------------
        //the NOR gate
        if (!strcmp(type, "NXOR"))
        {
            for (int i = 0; input1->input_signal[i]; i++)
            {
                if ((input2->input_signal[i] == '-' && input1->input_signal[i] == '_') 
                || (input2->input_signal[i] == '_' && input1->input_signal[i] == '-'))
                    res[i] = '-';
                else
                    res[i] = '_';
            }
        }
        printf("%s\n",res);
    }

    return 0;
}