#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main() {
    String* newString = createString(10); // we assume that this works for this test
    fillString(newString, "This is some cool stuff"); // we assume this works for this test

    
    printf("newString is at %p\n", newString);
    printf("newString is of size %d\n", newString->size);
    printf("newString is of length %d\n", newString->length);
    printf("newString has content '");
    printString(newString);
    printf("'\n");

    String* cutString1 = substring(newString, 0, 5); // we expect to get 'This '

    if (cutString1 == NULL) {
        printf("cutString is NULL\
            =-");
    } else {
        printf("cutString1 is at %p\n", cutString1);
        printf("cutString1 is of size %d\n", cutString1->size);
        printf("cutString1 is of length %d\n", cutString1->length);
        printf("cutString1 has content '");
        printString(cutString1);
        printf("'\n");
    }

    String* cutString2 = substring(newString, 3, 2); // this should give NULL

    if (cutString2 == NULL) {
        printf("cutString is NULL\n");
    } else {
        printf("cutString2 is at %p\n", cutString2);
        printf("cutString2 is of size %d\n", cutString2->size);
        printf("cutString2 is of length %d\n", cutString2->length);
        printf("cutString2 has content '");
        printString(cutString2);
        printf("'\n");
    }

    String* cutString3 = substring(newString, 0, 100); // this should give NULL

    if (cutString3 == NULL) {
        printf("cutString3 is NULL\n");
    } else {
        printf("cutString3 is at %p\n", cutString3);
        printf("cutString3 is of size %d\n", cutString3->size);
        printf("cutString3 is of length %d\n", cutString3->length);
        printf("cutString3 has content '");
        printString(cutString3);
        printf("'\n");
    }

    deleteString(newString);
    deleteString(cutString1);
    deleteString(cutString2);
    deleteString(cutString3);

    return 0;
}