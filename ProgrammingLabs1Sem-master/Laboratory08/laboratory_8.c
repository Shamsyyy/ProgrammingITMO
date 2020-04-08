// Laboratory work #8
// Option 11

#include <stdio.h>
#include <string.h>

int main(int argc, char **agrv) 
{
    // Task #1
    // Concatenate string and n first chars of other string
    char str[100];
    int n;
    char other_str[100];
    scanf("%s %s %d", str, other_str, &n);
    strncat(str, other_str, n);
    printf("%s\n", str);

    // Task #2
    // Compare n first chars of two strings
    scanf("%s %s %d", str, other_str, &n);
    char str_1[100];
    char str_2[100];
    strncpy(str_1, str, n);
    strncpy(str_2, other_str, n);
    str_1[n] = '\0';
    str_2[n] = '\0';    
    printf("%d  \n", strcmp(str_1, str_2));

    // Task #3
    // Copy first n char from one string to another
    scanf("%s %s %d", str, other_str, &n);
    strncpy(other_str, str, n);
    printf("%s\n", other_str);

    // Task #4
    // Find length of a segment in a string consisting of characters of another string4
    scanf("%s %s", str, other_str);
    printf("%d\n", strspn(str, other_str));

    // Task #5
    // Select pieces from one string, separated by any of the many characters in the second string
    scanf("%s %s", str, other_str);
    char *res = strtok(str, other_str);
    while (res != NULL)
    {
        printf("%s\n", res);
        res = strtok(NULL , other_str);
    }
}