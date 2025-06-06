#!/bin/sh
exec clang-format --verbose -i `find src include example "(" -name "*.c" -or -name "*.h" ")"`
