#include <stdio.h>

void url_encode(char *str, int true_length)
{
    int spaces = 0;

    // Count spaces
    for (int i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
            spaces++;
    }

    int newLength = true_length + spaces * 2;

    str[newLength] = '\0';

    int i = true_length - 1;
    int j = newLength - 1;

    while (i >= 0)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else
        {
            str[j--] = str[i];
        }

        i--;
    }
}

int main()
{
    char str[100] = "Hello World";

    url_encode(str, 11);

    printf("%s\n", str);

    return 0;
}