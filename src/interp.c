#include "interp.h"

int i = 0;

static char checkKeywords(char *text) {
    if (strcmp(text, "pp") == 0) {
        return 'p';
    }
    else if (strcmp(text, "cc") == 0) {
        return 'c';
    }
    else if (strcmp(text, "++") == 0) {
        return '+';
    }
    else return 0;
}

static void skipToks(Token* toks) {
    while (toks[i].tok != ENDOF && checkKeywords(toks[i].text) == 0)
        i++;
}

static char *concat(Token* toks) { 
    if (checkKeywords(toks[i].text) == 0 && toks[i].tok != ENDOF) {
        i++;

        if (checkKeywords(toks[i].text) == 0 && toks[i].tok != ENDOF) {
            return strncat(toks[i - 1].text, toks[i].text, 255);
        }
        else {
            skipToks(toks);
        }
    }
    else {
        skipToks(toks);
    } 
}

static void print(Token* toks) {
    i++;

    while (checkKeywords(toks[i].text) == 0 
    || checkKeywords(toks[i].text) == '+') {
        if (toks[i].tok == ENDOF) break;
           
        if (checkKeywords(toks[i].text) == '+') {
            i++;
            char* con = concat(toks);
            printf("%s", con);
            i++;

            if (checkKeywords(toks[i].text) == '+') {
                i++;
            }
            else {
                skipToks(toks);
                break;  
            }                
        }
        else {
            printf("%s", toks[i].text);
            i++;
        } 
    }
}

void interp(Parse parser, long filesize) {
    Token* toks = tokize(parser.programArray, filesize);

    while (toks[i].tok != ENDOF) {
        char chkKeywords = checkKeywords(toks[i].text);

        switch (chkKeywords) {
            case 'p': 
                print(toks);
                break;
            default:
                i++;
                break;
        }
    }
}