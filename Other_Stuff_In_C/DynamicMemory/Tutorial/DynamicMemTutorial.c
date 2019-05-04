/******************************
 * Filename: DynamicMemTutorial.c
 * Author: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A sample and standard new file
   gcc -Wall -Wextra -O -ansi -pedantic -o DynamicMemTutorial DynamicMemTutorial.c
 ******************************/
/*printf, fscanf, fgetc, puts*/
#include <stdio.h>
/*malloc, free*/
#include <stdlib.h>

#define MAXFILEPATH 256

int main(void)
{
    /*Counters*/
    int i, charcount;
    /* make room for file path*/
    char filename[MAXFILEPATH];
    /* make file pointer to open file with*/
    FILE *fp;
    /* dynamically allocate memory using this pointer to store this result*/
    char *cp;
    puts("Please enter the file you wish to read");
    fgets(filename, MAXFILEPATH, stdin);
    /* fgets usually returns with the newline still there so we need to replace that*/
    for (i = 0; i < MAXFILEPATH; ++i)
    {
        if (filename[i] == '\n')
            filename[i] = '\0';
    }

    /* try to open file to read text*/
    fp = fopen(filename, "rt");
    /* check if the file opened*/
    if (!fp)
    {
        perror(filename);
        return -1;
    }
    /* file openig was successfull, now use it*/
    /* first, get the number from the front of the file that states how many chars are after thr 1st line*/
    fscanf(fp, " %i", &charcount);
    /* clear the rest of the first line*/
    while (fgetc(fp) != '\n')
        ;
    /* attempt to allocate the memory to allocate the remaining text*/
    cp = (char *)malloc(charcount * sizeof(char));
    /* check if it failed*/
    if (!cp)
    {
        /* print appropriate sounding error*/
        perror("mallod failed");
        fclose(fp);
        return -1;
    }
    /* scan the file and store each char into the array*/
    for (i = 0; i < charcount && feof(fp) == 0; cp[i] = fgetc(fp), ++i)
        ;
    /* replace the last char with '\0'*/
    cp[i - 1] = '\0';
    /* print the text and how many chars it is*/
    printf("%s\n%i\n", cp, charcount);

    /* free the memory*/
    free(cp);
    fclose(fp);
    return 0;
}
