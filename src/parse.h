#ifndef PARSE_H_
#define PARSE_H_

#include "tok.h"

typedef struct {
    char programArray[LENGTH];
} Parse;

Parse parse(Token* tokens);
void classifyStatements(Token* tokens);
void checkLoop(Token* tokens);

#endif