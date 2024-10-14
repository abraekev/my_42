#!/bin/bash

cd ..

echo "Running Makefile"
make test

#if the exit code of the previous command is not 0, then…
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1;
fi
echo "Compilation succesful."

TEST_DIR="./test/args"
for FILE in "$TEST_DIR"/*.txt
do
    INPUT=$(cat "$FILE")
    echo "testing $FILE."

    RESULT=$(./push_swap $INPUT | ./checker_linux $INPUT)
    if [ "$RESULT" == "OK" ]; then
        echo -e "\e[32m✓ OK\e[0m"  # Green plain checkmark
    elif [ "$RESULT" == "KO" ]; then
        echo -e "\e[31m× KO\e[0m"  # Red small cross for KO
    else
        echo "Error"
    fi
    echo "-------------------------------------------"
done
echo "*** end of tests ***"
