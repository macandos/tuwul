#include "tok.h"

int n = 0;
int linenum = 1;

Token* tokize(char character[], long filesize) {
    static Token tokens[LENGTH];
    memset(tokens, 0, LENGTH*sizeof(Token));
    n = 0;

    int getLinenum;
    Token token;
    for (int e = 0; e < filesize - linenum + 1; e++) {
        if (token.tok == COMMENT) {
            if (getLinenum < linenum) {
                token = createTok(' ', WHITESPACE);
                continue;
            }
        }

        switch (character[e]) {
            case '|':
                token = appendTok(token, tokens);

                getLinenum = linenum;
                token = createTok('|', COMMENT);
                continue;
            case '\n':
            case '\r':
                token = appendTok(token, tokens);
                ++linenum;
                break;
            case ' ':
            case '\t':
                if (token.tok == COMMENT) {
                    strncat(token.text, &character[e], 1);
                }
                else {
                    token = appendTok(token, tokens);
                }
                break;
            default:
                if (token.tok != IDENTIFIER && token.tok != COMMENT) {
                    token = appendTok(token, tokens);
                    token = createTok(character[e], IDENTIFIER);
                }
                else {
                    strncat(token.text, &character[e], 1);
                }
                break;

        }
    }

    token = appendTok(token, tokens);
    
    token = createTok(' ', ENDOF);
    token = appendTok(token, tokens);
    return tokens;
}

Token createTok(char name, Toks tok) {
    Token token;
    strcpy(token.text, "");
    strncat(token.text, &name, 1);
    token.tok = tok;

    return token;
}

Token appendTok(Token token, Token tokens[]) {
    if (token.tok != WHITESPACE && token.tok != COMMENT) {
        token.linenum = linenum; 
        tokens[n] = token;
        n++;
    }

    Token returnTok;
    returnTok.linenum = token.linenum;
    returnTok.tok = WHITESPACE;

    return returnTok;
}

Token *sortToks(Token* tokens) {
    for (int i = 0; i < LENGTH; i++) {
        if (tokens[i].tok == 0 || tokens[i].tok == ENDOF) break;

        if (strcmp(tokens[i].text, "uwu") == 0) {
            tokens[i].type = UWU;
        }
        else if (strcmp(tokens[i].text, "owo") == 0) {
            tokens[i].type = OWO;
        }
        else if (strcmp(tokens[i].text, "ywy") == 0) {
            tokens[i].type = YWY;
        }
        else if (strcmp(tokens[i].text, "twt") == 0) {
            tokens[i].type = TWT;
        }
        else if (strcmp(tokens[i].text, "ewe") == 0) {
            tokens[i].type = EWE;
        }
        else if (strcmp(tokens[i].text, "awa") == 0) {
            tokens[i].type = AWA;
        }
        else if (strcmp(tokens[i].text, "iwi") == 0) {
            tokens[i].type = IWI;
        }
    }

    return tokens;
}

void debug(Token token) {
    printf("token(%d, %s, %s, %d);\n", token.type, debugTypes[token.tok], token.text, token.linenum);
}