#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main() {
    String* newString = createString(10);
    if (newString == NULL) {
        perror("newString is NULL!\n");
    } else {
        printf("newString is at %p\n", newString);
        printf("newString is of size %d\n", newString->size);
        printf("newString is of length %d\n", newString->length);
        printf("newString has content '");
        printString(newString);
        printf("'\n");
    }

    deleteString(newString);

    return 0;
}