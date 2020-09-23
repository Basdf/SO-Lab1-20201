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

    for (int i = 1; i < argc; i++)
    {

        FILE *inFile = fopen(argv[i], "r");
        if (inFile == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        int currChar;        /* current characters */
        // int prevChar;        /* previous characters */
        // unsigned char count; /* number of characters in a run */

        // /* encode inFile */
        // prevChar = EOF; /* force next char to be different */
        // count = 0;
        // aaaab
        /* read input until there's nothing left */
        while ((currChar = fgetc(inFile)) != EOF)
        {
            printf("%c",currChar);
            // fputc(currChar, outFile);

            // /* check for run */
            // if (currChar == prevChar)
            // {
            //     /* we have a run.  count run length */
            //     count = 0;

            //     while ((currChar = fgetc(inFile)) != EOF)
            //     {
            //         if (currChar == prevChar)
            //         {
            //             count++;

            //             if (count == UCHAR_MAX)
            //             {
            //                 /* count is as long as it can get */
            //                 fputc(count, outFile);

            //                 /* force next char to be different */
            //                 prevChar = EOF;
            //                 break;
            //             }
            //         }
            //         else
            //         {
            //             /* run ended */
            //             fputc(count, outFile);
            //             fputc(currChar, outFile);
            //             prevChar = currChar;
            //             break;
            //         }
            //     }
            // }
            // else
            // {
            //     /* no run */
            //     prevChar = currChar;
            // }

            // if (currChar == EOF)
            // {
            //     /* run ended because of EOF */
            //     fputc(count, outFile);
            //     break;
            // }
        }

        fclose(inFile);
    }

    return 0;
}
