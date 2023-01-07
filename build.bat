@echo off

mkdir ..\build
pushd ..\build
cl -Zi /Wall ..\markdown_parser\lexer.c ..\markdown_parser\copy.c ..\markdown_parser\token.c ..\markdown_parser\heading.c ..\markdown_parser\main.c 
lexer.exe
popd
