#pragma once

#ifndef TOK_H_
#define TOK_H_

#define LENGTH 10 * 1000

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef enum {
    WHITESPACE,

    IDENTIFIER,
    COMMENT,

    // End of file
    ENDOF
} Toks;

// for debug purposes
static const char* debugTypes[] = {
    "WHITESPACE",

    "IDENTIFIER",
    "COMMENT",

    // End of file
    "ENDOF"
};

typedef struct {
    int linenum;
    char text[LENGTH];
    Toks tok;

    Type type;
} Token;

Token* tokize(char character[], long filesize);
Token createTok(char name, Toks tok);
Token appendTok(Token token, Token tokens[]);
Token *sortToks(Token* tokens);

// debug
void debug(Token token);

#endif
