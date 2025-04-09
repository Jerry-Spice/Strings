#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main() {
    String* newString = createString(11); // we're assuming this works
    fillString(newString, "Hello World");

    printf("newString is at %p\n", newString);
    printf("newString is of size %d\n", newString->size);
    printf("newString is of length %d\n", newString->length);
    printf("newString has content '");
    printString(newString);
    printf("'\n");

    fillString(newString, "This is a much longer message so it needs more space");

    printf("newString is at %p\n", newString);
    printf("newString is of size %d\n", newString->size);
    printf("newString is of length %d\n", newString->length);
    printf("newString has content '");
    printString(newString);
    printf("'\n");

    fillString(newString, "Now back to a smaller string");

    printf("newString is at %p\n", newString);
    printf("newString is of size %d\n", newString->size);
    printf("newString is of length %d\n", newString->length);
    printf("newString has content '");
    printString(newString);
    printf("'\n");

    deleteString(newString);

    return 0;
}