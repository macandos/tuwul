#include "parse.h"

int currTok = 0;
Parse parser;
int pos = 0;

void checkLoop(Token* tokens) {
    int ewePosition = currTok;
    while (tokens[currTok].type != AWA) {
        if (tokens[currTok].tok == ENDOF) break;

        if (tokens[currTok].type == EWE) ++currTok;
        classifyStatements(tokens);
    }

    if (tokens[currTok].type  == AWA && parser.programArray[pos] != 0) {
        currTok = ewePosition - 1;
    }

    ++currTok;
}

void classifyStatements(Token* tokens) {
    switch (tokens[currTok].type) {
        case UWU:
            parser.programArray[pos]++;
            ++currTok;
            break;
        case OWO:
            parser.programArray[pos]--;
            ++currTok;
            break;
        case TWT:
            pos++;
            ++currTok;
            break;
        case YWY:
            pos--;
            ++currTok;
            break;
        case EWE:
            checkLoop(tokens);
            break;
        case IWI:
            // copies the last position into the current position
            if (pos == 0) { 
                ++currTok; 
            }
            else {
                parser.programArray[pos] = parser.programArray[pos - 1];
                ++currTok;
            }
            break;
        default:
            if (tokens[currTok].tok == ENDOF) break;
            ++currTok;
            break;
    }
}

Parse parse(Token* tokens) {
    while (tokens[currTok].tok != ENDOF) {
        if (tokens[currTok - 1].tok == ENDOF) break;
        classifyStatements(tokens);
    }

    /*
    for debugging people
    for (int i = 0; i < 10; i++) {
        printf("%c",parser.programArray[i]);
    }
    */
    

    return parser;
}