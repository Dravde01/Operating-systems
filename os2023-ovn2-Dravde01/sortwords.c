#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int cmpstringp(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

static int write_words(const char **words, size_t words_len, const char *filename)
{
    int ret;
    FILE *outfile;
    outfile = fopen(filename, "wx");

    if (outfile == NULL)
    {
        ret = -1;
        goto exit2;
    }
    
    for (int i = 0; i < words_len; i++)
    {
        if (fprintf(outfile, "%s\n", words[i]) < 0)
        {
            ret = -1;
            goto exit1;
        }
    }
    
    ret = 0;

    exit1:
        fclose(outfile);
    exit2:
        return ret;
}

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");
    if (argc < 2)
    {
        file = stdin;
    }

    FILE *output_file = fopen("output.txt", "r");
    if (output_file != NULL)
    {
        printf("The file exists");
        return 1;
    }

    char *linep, *wordp, **words;
    size_t lines_sz = 11, lines_len = 0, words_sz = 10, words_len = 0;
    ssize_t ret;
    
    words = NULL;
    words = realloc(words, words_sz * sizeof(char*));

    if (words == NULL)
    {
        return -1;
    }

    linep = NULL;

    while ((ret = getline(&linep, &lines_sz, file)) >= 0) 
    {
        lines_len++;

        for (int i = 0; i < ret; i++)
        {
            linep[i] = tolower(linep[i]);
        }

        while ((wordp = strsep(&linep, "1234567890()\"\' &$,.!?:[];\n\r\t")) != NULL)
        {
            if (wordp == NULL)
                continue;

            if (wordp[0] == '\0')
                continue;

            words[words_len++] = wordp;

            if (words_len >= words_sz)
            {
                words_sz += 10;
                words = realloc(words, words_sz * sizeof(char*));
            }
        }

        free(linep);
        linep = NULL;
    }

    qsort(words, words_len, sizeof(char*), cmpstringp);
    write_words((const char **)words, words_len, "output.txt");
    printf("Read %zu rows and %zu words\n", lines_len, words_len);

    return 0;
}