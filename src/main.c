#include <stdio.h>
#include <stdlib.h>

#include "tok.h"
#include "parse.h"
#include "interp.h"

void start(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) { 
        printf("no such file"); 
        exit(1); 
    }
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char character[filesize];
    size_t i = 0;
    char ch;

    while (!feof(file)) 
        character[i++] = fgetc(file);
    character[i] = '\0';

    // lexing stage
    Token* toks = tokize(character, filesize);
    toks = sortToks(toks);
    
    /*
    for debugging purposes
    for (int i = 1; i < LENGTH; i++) {
        if (toks[i].tok == 0) break;
        debug(toks[i]);
    }
    */

    // parser
    Parse parser = parse(toks);
    
    // interpreter
    interp(parser, filesize);
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("invalid command");
    }
    else {
        start(argv[1]);
    }
}
