@echo off

mkdir ..\build
pushd ..\build
cl -Zi /Wall ..\markdown_parser\testing\entry.c ..\markdown_parser\testing\lexer_test.c ..\markdown_parser\lexer.c ..\markdown_parser\copy.c ..\markdown_parser\html.c
entry.exe
popd