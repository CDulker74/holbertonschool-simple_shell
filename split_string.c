#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **split_string(char *str)
{
    char **result = NULL;
    char *token;
    int count = 0;

    token = strtok(str, " ");
    while (token != NULL)
    {
        result = realloc(result, sizeof(char *) * (count + 1));
        result[count] = token;
        count++;
        token = strtok(NULL, " ");
    }
    result = realloc(result, sizeof(char *) * (count + 1));
    result[count] = NULL;

    return result;
}

int main(void)
{
    char test[] = "Hello world how are you";
    char **words = split_string(test);
    
    for (int i = 0; words[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i, words[i]);
    }
    
    free(words);
    return (0);
}
