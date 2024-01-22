#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct c_v{
    int count;
    int value;
    struct c_v *next;
} c_v;



c_v *get_min(c_v *list)
{
    c_v *test = list;
    int min = test->value;
    while (test)
    {
        if (test->value < min && test->count != 0)
            min = test->value;
        test = test->next;
    }
    test = list;
    c_v *res = NULL;
    while (test)
    {
        if (test->value == min && test->count != 0)
            res = test;
        test = test->next;
    }
    return (res);
}

int main()
{
    int value_to_reach;
    scanf("%d", &value_to_reach);
    int N;
    scanf("%d", &N);
    c_v *list = malloc(sizeof(c_v));
    c_v *head = list;
    for (int i = 0; i < N; i++) {
        scanf("%d", &list->count);
        if (i + 1 < N) {
            list->next = malloc(sizeof(c_v));
            list = list->next;
        }
        else 
            list->next = NULL;
    }
    list = head;
    for (int i = 0; i < N; i++) {
        scanf("%d", &list->value);
        list = list->next;
    }

    int sum = 0;
    int count = 0;
    list = get_min(head);
    while (list)
    {
        while (list->count > 0)
        {
                sum += list->value;
                count++;
                if (sum >= value_to_reach)
                {
                    printf("%i",count);
                    return 0;
                }
                list->count--;
        }
        list = get_min(head);
    }
    printf("-1");
    return 0;
}