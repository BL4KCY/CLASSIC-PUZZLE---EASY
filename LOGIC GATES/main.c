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
    for (int i = 0; i < n; i++) {
        char input_name[9];
        char input_signal[65];
        scanf("%s%s", input_name, input_signal);
    }
    for (int i = 0; i < m; i++) {
        char output_name[9];
        char type[9];
        char input_name_1[9];
        char input_name_2[9];
        scanf("%s%s%s%s", output_name, type, input_name_1, input_name_2);
        printf("%s", output_name);
    }

    return 0;
}