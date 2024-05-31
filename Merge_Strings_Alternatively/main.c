#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeAlternately(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int maxLen = len1 + len2;

    char *result = (char *)malloc((maxLen + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2)
    {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    while (i < len1)
    {
        result[k++] = word1[i++];
    }

    while (j < len2)
    {
        result[k++] = word2[j++];
    }

    result[k] = '\0';

    return result;
}

int main()
{
    char word1[] = "abc";
    char word2[] = "pqr";
    char *result = mergeAlternately(word1, word2);
    printf("%s\n", result);
    free(result);
    return 0;
}
