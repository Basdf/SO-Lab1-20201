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
        int currChar;
        char binario[4];
        int contador = 1;
        FILE *inFile = fopen(argv[i], "r");
        if (inFile == NULL)
        {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        while ((currChar = fgetc(inFile)) != EOF)
        {
            if (contador == 5)
            {
                // tranforma el entero de 4 bytes a un entero normalito para entenderlo en el codigo basicamente
                int x = (binario[3] << 24) | (binario[2] << 16) | (binario[1] << 8) | binario[0];
                for (int a = 0; a < x; a++)
                {
                    printf("%c", currChar);
                }
                contador=0;
            }
            else
            {
                binario[contador - 1] = currChar;
            }
            currChar = fgetc(inFile);
            contador = contador + 1;
        }

        fclose(inFile);
    }

    return 0;
}