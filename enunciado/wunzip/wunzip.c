#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        char currChar;
        char bin[4];
        int count = 1;
        FILE *inFile = fopen(argv[i], "r");
        if (inFile == NULL)
        {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        currChar = fgetc(inFile);
        while (currChar != EOF)
        {
            if (count == 5)
            {
                int x = (bin[3] << 24) | (bin[2] << 16) | (bin[1] << 8) | bin[0];
                for (int a = 0; a < x; a++)
                {
                    printf("%c", currChar);
                }
                count=0;
            }
            else
            {
                bin[count - 1] = currChar;
            }
            currChar = fgetc(inFile);
            count = count + 1;
        }

        fclose(inFile);
    }

    return 0;
}