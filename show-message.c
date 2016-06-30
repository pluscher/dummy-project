/* Over-complex dummy project for testing Jenkins with Git.
 * Version 2
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define MAXLEN (128)

const char csGreetFile[] = "greeting.txt";


int main(int argc, char *argv[])
{
    FILE *ifile = NULL;
    char *result = NULL;
    char greeting[MAXLEN] = "";
    int retval = 0;
    int i;

    if ((argc > 1) && (strcmp(argv[1], "-h") == 0))
    {
        printf("Needlessly complex Hello World program: put a string in a file called %s\n", csGreetFile);
        printf(" Command switches:\n    -h  This help message. \n\n");
    }

    ifile = fopen(csGreetFile, "r");
    if (ifile == NULL)
    {
        fprintf(stderr, "ERROR: can't open file %s\n", csGreetFile);
        retval = 1;
    }
    else
    {
        result = fgets(greeting, MAXLEN, ifile);
        fclose(ifile);
        if (result == NULL)
        {
            fprintf(stderr, "ERROR: can't read greeting from file %s\n", csGreetFile);
            retval = 2;
        }
        else
        {
            // all this code just for this result...
            for (i = 0; i < strlen(greeting); i++)
            {
                printf("%02X ", greeting[i]);
            }
            printf("\n%s\n", greeting);
        }
    }

    return retval;
}

