#include <stdio.h>
#include <assert.h>
#include "../lexer.h"
#include "lexer_test.h"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define LOG_GREEN() printf("%s[%d] %s ||\t%s\t %s %s\n", ANSI_COLOR_GREEN, __LINE__, __FUNCTION__, __FILE__, "PASS", ANSI_COLOR_RESET);
#define LOG_RED(string) fprintf(stderr, "%s[%d] %s ||\t%s\t %s - %s %s\n", ANSI_COLOR_RED, __LINE__, __FUNCTION__, __FILE__, "FAIL", string, ANSI_COLOR_RESET);