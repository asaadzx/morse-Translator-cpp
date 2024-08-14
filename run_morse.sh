#!/bin/bash
g++ -o morse_translator morse_translator.cpp
if [ $? -eq 0 ]; then
    ./morse_translator
else
    echo "Compilation failed."
fi

