#include "monty.h"

char *argt = NULL;
/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument list
 *
 * Return: EXIT_SUCCESS or EXIT FAILURE
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char line[1024];
    int i;
    unsigned int line_number = 0;
    char *opcode, *arg;
    stack_t *stack = NULL;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file  %s\n", argv[1]);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        opcode = strtok(line, " \n");
        if (opcode == NULL || opcode[0] == '#')
            continue;
        arg = strtok(NULL, " \n");

        if (strcmp(opcode, "push") == 0)
            {
                argt = arg;
            }

        for (i = 0; instructions[i].opcode; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                break;

            }
        }

        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%u: Unknown instr -> %s\n", line_number, opcode);
            fclose(file);
            free_stack(stack);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);
    free_stack(stack);

    return (EXIT_SUCCESS);
}
