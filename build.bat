@echo off

mkdir ..\build
pushd ..\build
cl -Zi ..\markdown_parser\markdown_parser.c
popd
