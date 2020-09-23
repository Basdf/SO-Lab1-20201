#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compressFile(char *fname);
// void fuseFiles(int count, char *fname[]);

char text[] = {};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    //fuseFiles(argc, argv);

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
        for (int i = 1; i < len; i++)
        {
            printf("Caracter %c",line[i]);
            if (aux == line[i])
            {
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

// void fuseFiles(int count, char *fname[])
// {
//     char *line = NULL;
//     size_t len = 0;
//     size_t read;
//     FILE *inFile;
//     int k = 0;
//     for (int i = 1; i <= count; i++)
//     {
//         line = NULL;
//         len = 0;
//         inFile = fopen(fname[i], "r");
//         while ((read = getline(&line, &len, inFile)) != -1)
//         {
//             // text[i] = line;
//             char *textAux = line;

//             printf("%s\n", line);
//             printf("%s\n", textAux);
//             printf("%d\n", sizeof(textAux));
//             for (int j = 0; j < sizeof(line); j++)
//             {
//                 text[k] = line[j];
//                 k++;
//                 // printf("%s\n", text);
//             }
//         }
        
//         fclose(inFile);
//     }
// }
