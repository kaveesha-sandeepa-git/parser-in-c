#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    INT,
    KEYWORD,
    SEPARATOR
} TokenType;


typedef struct
{
    TokenType type;
    char *value;
} Token;

// TokenLiteral generate_number(char current, int curr_index)
// {
//     //TokenLiteral *token = malloc(sizeof(TokenLiteral));
//     TokenLiteral token;
//     token.type = INT;
//     //char *value = malloc(sizeof(char) * 8);
//     int value =0;
//     //int value_index = 0;
//     while (isdigit(current) && current != EOF)
//     {
//         if (!isdigit(current))
//         {
//             break;
//         }
//         value = value * 10 + (current - '0');
//         // value[value_index] = current ;
//         // value_index++;
//         printf("%c", current);
//         current = fgetc(file);
//     }
//     token.value = value;
//     //token->value = value;
//     //free(value);
//     return (token);
// }

Token *generate_number(char *current,int *curr_index){
    Token *token = malloc(sizeof(Token));
    token->type = INT;
    char *value =malloc(sizeof(char) * 8);
    int value_index =0;
    while(isdigit(current[*curr_index]) && current[*curr_index] != '\0'){
        value[value_index] = current[*curr_index];
        //value = value *10 + (current[*curr_index] - '0');
        value_index++;
       
        *curr_index += 1;
    }
    value[value_index] = '\0';
    token->value = value;
    //free(value);
    return token;
}

Token *generate_keyword(char *current,int *curr_index){
    Token *token = malloc(sizeof(Token));
    char *keyword = malloc(sizeof(char) * 9);
    int keyword_index = 0;

    while(isalpha(current[*curr_index]) && current[*curr_index] != '\0'){
        keyword[keyword_index] = current[*curr_index];
        keyword_index++;
        *curr_index += 1;

    }
    keyword[keyword_index] = '\0';
    // printf("keyword index %d",keyword_index);
    // for(int i=0;i<keyword_index;i++){
    //     printf("%c\n",keyword[i]);
    // }
    if(strcmp(keyword,"exit") ==0){
        printf("type EXIT\n");
        token->type = KEYWORD;
        token->value = "EXIT";
    }
    return token; 
}
// void lexer(FILE *file)
// {
//     char current = fgetc(file);

//     while (current != EOF)
//     {
//         printf("curr:%c\n",current);
//         if (current == ';')
//         {
//             printf("FOUND SEMI COLUMN\n");
//         }
//         else if (current == '(')
//         {
//             printf("FOUND OPEN_PARAN\n");
//         }
//         else if (current == ')')
//         {
//             printf("FOUND CLOSE_PARAN\n");
//         }
//         else if (isdigit(current))
//         {
//             TokenLiteral test_token = generate_number(current,file);
//             printf("Test token value : %d\n",test_token.value);
//         }
//         else if (isalpha(current))
//         {
//             TokenKeyword *test_keyword = generate_keyword(current,file);
//             //printf("test keyword %s\n", test_keyword->keyword);
//             printf("current char:%c\n",current);
//         }
//         current = fgetc(file);
//     }
//     printf("\n");
// }

void lexer(FILE *file){
    int length;
    char *buffer = 0;
    fseek(file,0,SEEK_END);
    length = ftell(file);
    fseek(file,0,SEEK_SET);
    buffer = malloc(sizeof(char) * length +1);
    fread(buffer,1,length,file);
    //fclose(file);
    buffer[length] = '\0';
    //char *current = malloc(sizeof(char) * length +1);
    char *current = buffer;
    int curr_index = 0;
    
    while(current[curr_index] != '\0'){
        if (current[curr_index] == ';')
        {
            printf("FOUND SEMI COLUMN\n");
        }
        else if (current[curr_index] == '(')
        {
            printf("FOUND OPEN_PARAN\n");
        }
        else if (current[curr_index] == ')')
        {
            printf("FOUND CLOSE_PARAN\n");
        }
        else if (isdigit(current[curr_index]))
        {
            Token *test_token = generate_number(current,&curr_index);
            curr_index--; // adjust index after number parsing
            printf("Test token value : %s\n",test_token->value);
        }
        else if (isalpha(current[curr_index]))
        {
            Token *test_keyword = generate_keyword(current,&curr_index);
            curr_index--; // adjust index after keyword parsing
            //printf("test keyword %s\n", test_keyword->keyword);
            printf("current char:%c\n",current[curr_index]);
        }
        curr_index++;
    }
    free(buffer);
    //free(current);
    //free(test_token->value);
    //free(test_token);
}

int main()
{
    FILE *file;
    file = fopen("test.unn", "r");
    if (!file)
    {
        perror("Failed to open file");
        return 1;
    }

    lexer(file);
    fclose(file);
}
