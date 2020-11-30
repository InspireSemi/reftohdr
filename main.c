/* Copyright (c) 2020 InspireSemi Inc. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 66

void help(void)
{
    printf("Usage: reftohdr <input file> <output file> <#define name>\n");
    exit(1);
}


int main (int argc, char *argv[])
{
    FILE* out;
    FILE* in;
    // input buffer to grab and then process referecne_output data
    char indata[65];
    char outdata[100];
    unsigned int count = 0;

    if (argc < 3 )
    {
        help();
    }

    // Convert to upper case the define name on the cmdline
    char *s = argv[3];
    while (*s) {
        *s = toupper((unsigned char) *s);
        s++;
    }

    // open the .reference_output file
    in = fopen(argv[1], "rb");
    if(in == NULL)
    {
        printf("Could not find input file %s\n", argv[1]);
        exit(1);
    }

    // open the output file 
    out =  fopen(argv[2], "wb");
    if(out == NULL)
    {
        printf("Could not open output file %s\n", argv[2]);
        exit(1);
    }

    // grab the next line in the reference_output file. 
    while ( fgets( indata, MAXCHAR, in ) != NULL)
    {
        printf("Read = %s", indata);
        sprintf(outdata, "#define %s%d 0x", argv[3], count);
        count++;
        //strcat (indata, "\n");
        strcat(outdata, indata);
        printf("Output = %s", outdata);
        fputs (outdata, out);
    }

    printf("Total Written %d\n", count);

    fclose(in);
    fclose(out);

    exit(0);

}