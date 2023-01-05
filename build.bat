@echo off

mkdir ..\build
pushd ..\build
cl -Zi /Wall ..\markdown_parser\markdown_lexer.c
popd
