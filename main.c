#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct sig
{
	char		*name;
	char		*signal;
	struct sig	*next;
}	t_sig;

typedef struct logic
{
	char			*name;
	char			*type;
	char			*name_a;
	char			*name_b;
	struct logic	*next;
}	t_logic;


int hash_func(char *str)
{
	if (!strcmp(str, "AND"))
		return (0);
	if (!strcmp(str, "OR"))
		return (1);
	if (!strcmp(str, "XOR"))
		return (2);
	if (!strcmp(str, "NAND"))
		return (3);
	if (!strcmp(str, "NOR"))
		return (4);
	if (!strcmp(str, "NXOR"))
		return (5);
	return (-1);
}


int main()
{
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);

	t_sig	*input = malloc(sizeof(t_sig));
	t_sig	*head = input;
	t_logic	*output = malloc(sizeof(t_logic));
	t_logic	*logic_head = output;
	t_sig	*a = NULL;
	t_sig	*b = NULL;

	for (int i = 0; i < n; i++) {
		input->name = malloc(9);
		input->signal = malloc(68);
		input->next = malloc(sizeof(t_sig));
		scanf("%s%s", input->name, input->signal);

		input = input->next;

	}
	input->next = NULL;
	for (int i = 0; i < m; i++) {
		output->name = malloc(9);
		output->type = malloc(9);
		output->name_a = malloc(9);
		output->name_b = malloc(9);
		output->next = malloc(sizeof(t_logic));
		scanf("%s%s%s%s",output->name ,output->type , output->name_a, output->name_b);
		output = output->next;
	}
	output->next = NULL;
	output = logic_head;
	for (int i = 0; i < m; i++) {
		input = head;
		while (input)
		{
			if (!strcmp(output->name_a, input->name))
				a = input;
			if (!strcmp(output->name_b, input->name))
				b = input;
			input = input->next;
		}
		printf("%s",output->name);
		for (int j = 0; a->signal[j];j++)
		{

			switch (hash_func(output->type))
			{
				case 0:
					if (a->signal[j] == b->signal[j])
						putchar('-');
					else
						putchar('_');

					break;
				default:
					break;
			}
		}
	}
	return 0;
}
