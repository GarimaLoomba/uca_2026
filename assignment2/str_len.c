#include <stdio.h>

int my_strlen(const char *str)
{
    int count = 0;

    while (str[count] != '\0')
    {
        count++;
    }

    return count;
}

int main()
{
    char str[] = "Hello";

    printf("Length = %d\n", my_strlen(str));

    return 0;
}