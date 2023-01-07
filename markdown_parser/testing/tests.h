#include <stdio.h>
#include <assert.h>
#include "../lexer.h"
#include "lexer_test.h"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define LOG_RED(string) printf("%s %s || %s\t %s %s\n", ANSI_COLOR_RED, __FUNCTION__, __FILE__, string, ANSI_COLOR_RESET);
#define LOG_GREEN(string) printf("%s %s || %s\t %s %s\n", ANSI_COLOR_GREEN, __FUNCTION__, __FILE__, string, ANSI_COLOR_RESET);