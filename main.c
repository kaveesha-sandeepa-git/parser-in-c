// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>

// typedef enum
// {
//     INT,
//     KEYWORD,
//     SEPARATOR,
//     END_OF_TOKENS
// } TokenType;

// typedef struct
// {
//     TokenType type;
//     char *value;
// } Token;



// void print_token(Token token)
// {
//     printf("TOKEN VALUE: ");
//     for (int i = 0; token.value[i] != '\0'; i++)
//     {
//         printf("%c", token.value[i]);
//     }

//     switch (token.type)
//     {
//     case INT:
//         printf(" TOKEN TYPE :INT\n");
//         break;

//     case KEYWORD:
//         printf(" TOKEN TYPE :KEYWORD\n");
//         break;
//     case SEPARATOR:
//         printf(" TOKEN TYPE :SEPARATOR\n");
//         break;

//     case END_OF_TOKENS:
//         printf(" END_OF_TOKEN\n");
//         break;
//     }
// }

// // TokenLiteral generate_number(char current, int curr_index)
// // {
// //     //TokenLiteral *token = malloc(sizeof(TokenLiteral));
// //     TokenLiteral token;
// //     token.type = INT;
// //     //char *value = malloc(sizeof(char) * 8);
// //     int value =0;
// //     //int value_index = 0;
// //     while (isdigit(current) && current != EOF)
// //     {
// //         if (!isdigit(current))
// //         {
// //             break;
// //         }
// //         value = value * 10 + (current - '0');
// //         // value[value_index] = current ;
// //         // value_index++;
// //         printf("%c", current);
// //         current = fgetc(file);
// //     }
// //     token.value = value;
// //     //token->value = value;
// //     //free(value);
// //     return (token);
// // }

// Token *generate_number(char *current, int *curr_index)
// {
//     Token *token = malloc(sizeof(Token));
//     token->type = INT;
//     char *value = malloc(sizeof(char) * 8);
//     int value_index = 0;
//     while (isdigit(current[*curr_index]) && current[*curr_index] != '\0')
//     {
//         value[value_index] = current[*curr_index];
//         // value = value *10 + (current[*curr_index] - '0');
//         value_index++;

//         *curr_index += 1;
//     }
//     value[value_index] = '\0';
//     token->value = value;
//     // free(value);
//     return token;
// }

// Token *generate_keyword(char *current, int *curr_index)
// {
//     Token *token = malloc(sizeof(Token));
//     char *keyword = malloc(sizeof(char) * 9);
//     int keyword_index = 0;

//     while (isalpha(current[*curr_index]) && current[*curr_index] != '\0')
//     {
//         keyword[keyword_index] = current[*curr_index];
//         keyword_index++;
//         *curr_index += 1;
//     }
//     keyword[keyword_index] = '\0';
//     // printf("keyword index %d",keyword_index);
//     // for(int i=0;i<keyword_index;i++){
//     //     printf("%c\n",keyword[i]);
//     // }
//     if (strcmp(keyword, "exit") == 0)
//     {
//         // printf("type EXIT\n");
//         token->type = KEYWORD;
//         // token->value = malloc(strlen(keyword) + 1);
//         token->value = "EXIT";
//     }
//     free(keyword);
//     return token;
// }
// // void lexer(FILE *file)
// // {
// //     char current = fgetc(file);

// //     while (current != EOF)
// //     {
// //         printf("curr:%c\n",current);
// //         if (current == ';')
// //         {
// //             printf("FOUND SEMI COLUMN\n");
// //         }
// //         else if (current == '(')
// //         {
// //             printf("FOUND OPEN_PARAN\n");
// //         }
// //         else if (current == ')')
// //         {
// //             printf("FOUND CLOSE_PARAN\n");
// //         }
// //         else if (isdigit(current))
// //         {
// //             TokenLiteral test_token = generate_number(current,file);
// //             printf("Test token value : %d\n",test_token.value);
// //         }
// //         else if (isalpha(current))
// //         {
// //             TokenKeyword *test_keyword = generate_keyword(current,file);
// //             //printf("test keyword %s\n", test_keyword->keyword);
// //             printf("current char:%c\n",current);
// //         }
// //         current = fgetc(file);
// //     }
// //     printf("\n");
// // }

// Token *generate_separator(char *current, int *curr_index)
// {
//     Token *token = malloc(sizeof(Token));
//     token->value = malloc(2);
//     token->value[0] = current[*curr_index];
//     token->value[1] = '\0';
//     token->type = SEPARATOR;
//     return token;
// }
// size_t tokens_index;

// Token *lexer(FILE *file)
// {
//     int length;
//     char *buffer = 0;
//     fseek(file, 0, SEEK_END);
//     length = ftell(file);
//     fseek(file, 0, SEEK_SET);
//     buffer = malloc(sizeof(char) * length + 1);
//     fread(buffer, 1, length, file);
//     // fclose(file);
//     buffer[length] = '\0';
//     // char *current = malloc(sizeof(char) * length +1);
//     char *current = buffer;
//     int curr_index = 0;
//      Token *tokens = malloc(sizeof(Token) * 1024);
//     tokens_index = 0;

//     while (current[curr_index] != '\0')
//     {
//         Token *token = malloc(sizeof(Token));
//         if (current[curr_index] == ';')
//         {
//             token = generate_separator(current,&curr_index);
//             tokens[tokens_index] = *token;
//             tokens_index++;
//             //print_token(*token);
//             // printf("FOUND SEMI COLUMN\n");
//             free(token->value);
//             free(token);
//         }
//         else if (current[curr_index] == '(')
//         {
//             token = generate_separator(current,&curr_index);
//             tokens[tokens_index] = *token;
//             tokens_index++;
//             //print_token(*token);
//             // printf("FOUND OPEN_PARAN\n");
//             free(token->value);
//             free(token);
//         }
//         else if (current[curr_index] == ')')
//         {
//             token = generate_separator(current,&curr_index);
//             tokens[tokens_index] = *token;
//             tokens_index++;
//             //print_token(*token);
//             // printf("FOUND CLOSE_PARAN\n");
//             free(token->value);
//             free(token);
//         }
//         else if (isdigit(current[curr_index]))
//         {
//             Token *int_token = generate_number(current, &curr_index);
//             print_token(*int_token);
//             curr_index--; // adjust index after number parsing
//             printf(" \ntoken value : %s\n", int_token->value);
//             free(int_token->value);
//             free(int_token);
//         }
//         else if (isalpha(current[curr_index]))
//         {
//             Token *keyword_token = generate_keyword(current, &curr_index);
//             curr_index--; // adjust index after keyword parsing
//             // printf("test keyword %s\n", test_keyword->keyword);
//             //print_token(*keyword_token);
//             // printf("current char:%c\n", current[curr_index]);
//             //  free(test_keyword->value);
//             free(keyword_token);
//         }
//         else if(current[curr_index] == ' '){
//             continue;
//         }
//         else{
//             printf("ERROR UNKNOWN CHARACTER\n"); 
//             exit(1);
//         }
//         curr_index++;
//     }
//     free(buffer);
//     tokens[tokens_index].value = '\0';
//     return tokens;
//     // free(current);
//     // free(test_token->value);
//     // free(test_token);
// }

// Token *parser(Token *tokens){
//     Token *current_token = &tokens[0];
//     while (current_token->type != END_OF_TOKENS)
//     {
//         printf("123\n");
//         current_token++;
//     }
//     return current_token;
    
// }


// int main(int argc,char *argv[])
// {
//     if(argc < 2){
//         printf("usage : %s <file name> \n",argv[0]);
//         exit(1);
//     }
//     FILE *file;
//     file = fopen(argv[1], "r");
//     if (!file)
//     {
//         perror("Failed to open file");
//         return 1;
//     }

//     Token *tokens = lexer(file);
//     for(size_t i=0;tokens[i].type != END_OF_TOKENS;i++){
//         print_token(tokens[i]);
//     }
//     Token *tokens2 = parser(tokens);
//     fclose(file);
// }

// --------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    INT,
    KEYWORD,
    SEPARATOR,
    END_OF_TOKENS
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

void print_token(Token token)
{
    printf("TOKEN VALUE: %s ", token.value ? token.value : "NULL");

    switch (token.type) {
        case INT:        printf("TOKEN TYPE: INT\n"); break;
        case KEYWORD:    printf("TOKEN TYPE: KEYWORD\n"); break;
        case SEPARATOR:  printf("TOKEN TYPE: SEPARATOR\n"); break;
        case END_OF_TOKENS: printf("TOKEN TYPE: EOF\n"); break;
    }
}

Token generate_number(char *src, int *i)
{
    Token token;
    token.type = INT;
    token.value = malloc(16);

    int k = 0;
    while (isdigit(src[*i])) {
        token.value[k++] = src[*i];
        (*i)++;
    }
    token.value[k] = '\0';
    return token;
}

Token generate_keyword(char *src, int *i)
{
    Token token;
    token.type = KEYWORD;
    token.value = malloc(16);

    int k = 0;
    while (isalpha(src[*i])) {
        token.value[k++] = src[*i];
        (*i)++;
    }
    token.value[k] = '\0';
    return token;
}

Token generate_separator(char *src, int *i)
{
    Token token;
    token.type = SEPARATOR;
    token.value = malloc(2);
    token.value[0] = src[*i];
    token.value[1] = '\0';
    (*i)++;
    return token;
}

Token *lexer(FILE *file)
{
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *src = malloc(size + 1);
    fread(src, 1, size, file);
    src[size] = '\0';

    Token *tokens = malloc(sizeof(Token) * 1024);
    int i = 0, t = 0;

    while (src[i]) {
        if (isspace(src[i])) {
            i++;
        }
        else if (isdigit(src[i])) {
            tokens[t++] = generate_number(src, &i);
        }
        else if (isalpha(src[i])) {
            tokens[t++] = generate_keyword(src, &i);
        }
        else if (src[i] == ';' || src[i] == '(' || src[i] == ')') {
            tokens[t++] = generate_separator(src, &i);
        }
        else {
            printf("Unknown character: %c\n", src[i]);
            exit(1);
        }
    }

    tokens[t].type = END_OF_TOKENS;
    tokens[t].value = NULL;

    free(src);
    return tokens;
}

Token *parser(Token *tokens)
{
    Token *curr_token = &tokens[0];
    while(curr_token->type != END_OF_TOKENS){
        printf("123\n");
        curr_token++;
    }
    return curr_token;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("File open failed");
        return 1;
    }

    Token *tokens = lexer(file);

    int i = 0;
    while (tokens[i].type != END_OF_TOKENS) {
        print_token(tokens[i]);
        i++;
    }
    parser(tokens);

    fclose(file);
    return 0;
}
