#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// トークンの種類
typedef enum {
    TK_RESERVED, // 記号
    TK_NUM,      // 整数トークン
    TK_EOF,      // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

// トークン型
struct Token {
    TokenKind kind; // トークンの型
    Token *next;    // 次の入力トークン
    int val;        // kindがTK_NUMの場合その数値、
    char *str;      // トークン文字列
};

// 現在着目しているトークン
Token *token;

// エラーを報告するための関数
// printfと同じ引数を取る
void error(char *fmt, ...) {
    va_list ap;
    va_start (ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

// 次のトークンが期待している記号の時にはトークンを1つ読み進めて真を返す
// それ以外の場合には偽を返す
bool consume(char op) {
    if (token->kind != TK_RESERVED || token->str[0] != op)
        return false;
    token = token->next;
    return true;
}

// 次のトークンが期待している記号の時には、トークンを1つ読み進める
// それ以外の場合にはエラーを返す
 void expect (char op) {
    if (token->kind != TK_RESERVED || token->str[0] != op)
        error("'%c'ではありません");
    token = token->next;
 }

/* int main(int argc, char **argv) { */
/*     if (argc != 2) { */
/*         fprintf(stderr, "引数の個数が正しくありません"); */
/*         return 1; */
/*     } */
/*  */
/*     printf(".intel_syntax noprefix\n"); */
/*     printf(".global main\n"); */
/*     printf("main:\n"); */
/*     printf("    mov rax, %d\n", atoi(argv[1])); */
/*     printf("    ret\n"); */
/*     return 0; */
/* } */
/* int main(int argc, char **argv) { */
/*     if (argc != 2) { */
/*         fprintf(stderr, "引数の個数が正しくありません"); */
/*         return 1; */
/*     } */
/*  */
/*     char *p = argv[1]; */
/*  */
/*     printf(".intel_syntax noprefix\n"); */
/*     printf(".global main\n"); */
/*     printf("main:\n"); */
/*     printf("    mov rax, %ld\n", strtol(p, &p, 10)); */
/*  */
/*     while (*p) { */
/*         if (*p == '+') { */
/*             p++; */
/*             printf("    add rax, %ld\n", strtol(p, &p, 10)); */
/*             continue; */
/*         } */
/*  */
/*         if (*p == '-') { */
/*             p++; */
/*             printf("    sub rax, %ld\n", strtol(p, &p, 10)); */
/*             continue; */
/*         } */
/*  */
/*         fprintf(stderr, "予期しない文字です: '%c'\n", *p); */
/*     } */
/*  */
/*     printf("    ret\n"); */
/*     return 0; */
/* } */
