
#include <stdio.h>
#include <string.h>

const char base64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

void base64Encode(const char input[], char output[])
{
    int len = strlen(input);
    int i = 0;
    int j = 0;

    while (i < len)
    {
        unsigned char byte1 = input[i++];
        unsigned char byte2 = (i < len) ? input[i++] : 0;
        unsigned char byte3 = (i < len) ? input[i++] : 0;

        output[j++] = base64[byte1 >> 2];

        output[j++] =
            base64[((byte1 & 3) << 4) | (byte2 >> 4)];

        if (i - 1 < len)
            output[j++] =
                base64[((byte2 & 15) << 2) | (byte3 >> 6)];
        else
            output[j++] = '=';

        if (i < len)
            output[j++] = base64[byte3 & 63];
        else
            output[j++] = '=';

    }

    output[j] = '\0';
}

int main()
{
    const char *testCases[] =
    {
        "Man",
        "Ma",
        "Cat",
        "Hello World",
        "A",
        ""
    };

    int count = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < count; i++)
    {
        char output[100];

        base64Encode(testCases[i], output);

        printf("Input: \"%s\"\n", testCases[i]);
        printf("Base64: \"%s\"\n\n", output);
    }

    return 0;
}


