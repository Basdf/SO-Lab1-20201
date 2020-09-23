#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compressFile(char *fname);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        compressFile(argv[i]);
    }

    return 0;
}

void compressFile(char *fname)
{
    char *line = NULL;
    size_t len = 0;
    size_t read;
    FILE *inFile = fopen(fname, "r");
    if (inFile == NULL)
    {
        printf("wzip: cannot open file\n");
        exit(1);
    }
    while ((read = getline(&line, &len, inFile)) != -1)
    {

        char aux = line[0];
        int count = 1;
        printf("linea %c",line);
        puts("");
        for (int i = 1; i < len; i++)
        {
            if (aux == line[i])
            {
                puts("entre al if");
                count++;
            }
            else
            {
                fwrite(&count, 4, 1, stdout);
                fwrite(&aux, 1, 1, stdout);
                aux = line[i];
                count = 1;
            }
        }
    }
    fclose(inFile);
}
