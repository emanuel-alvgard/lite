#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

char *read_file(char *file_name) {
    
    FILE *file;
    long file_size;
    char *buffer;

    file = fopen(file_name, "r");
    file_size = fseek( file, 0L, SEEK_END);
    rewind(file);

    buffer = (char *) calloc(1, file_size + 1);
    fread(buffer, file_size, 1, file);

    fclose(file);
    return buffer;
}