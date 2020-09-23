#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    size_t read;
    char aux;
    int count;

    for (int i = 1; i < argc; i++)
    {

        FILE *inFile = fopen(argv[i], "r");
        if (inFile == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        while ((read = getline(&line, &len, inFile)) != -1)
        {
            aux = line[0];
            count = 1;
            for (int j = 1; j < len; j++)
            {
                if (aux == line[j])
                {
                    count++;
                }
                else if (j == len)
                {
                    /// ver que poner aqui 
                }
                else
                {
                    // printf("caracter %c", line[j]);
                    // puts("");
                    fwrite(&count, 4, 1, stdout);
                    fwrite(&aux, 1, 1, stdout);
                    aux = line[j];
                    count = 1;
                }
            }
        }
        fclose(inFile);
    }

    return 0;
}
