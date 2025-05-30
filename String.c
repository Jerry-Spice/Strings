#include <stdio.h>
#include <stdlib.h>
#include "String.h"

/*
String* createString(int size)
 @param int size

 @description allocates memory for a string
 @leaky false
*/
String* createString(int size) {
    String* newString = (String*)malloc(sizeof(String));

    newString->content = (char*)calloc(sizeof(char), (size+1)); // +1 to account for '\0'

    newString->length=0;
    newString->size = size;
    return newString;
}

/*
void fillString(String* target, char* content)
 @param String* target
 @param char* content

 @description fills in the content for a string and ensures memory sizes match
 @leaky false
*/
void fillString(String* target, char* content) {
    int contentLength = 0;
    while (*(content+contentLength) != '\0') {
        contentLength++;
    }

    if (contentLength >= target->size) {
        target->content = realloc(target->content, sizeof(char) * (contentLength + 1));
        target->size = contentLength;
    }
    
    for (int i = 0; i < contentLength; i++) {
        *(target->content+i) = *(content+i);
    }

    *(target->content+contentLength) = '\0';

    target->length = contentLength;
}

/*
void deleteString(String* target)
 @param String* target

 @description frees the target string and the content within it
 @leaky false
*/
void deleteString(String* target) {
    if (target != NULL) {
        if (target->content != NULL) {
            free(target->content);
        }
        free(target);
    }
}

/*
void printString(String* target)
 @param String* target

 @description prints out the string contents
 @leaky false
*/
void printString(String* target) {
    printf("%s", target->content);
}

/*
String* substring(String* target, int start, int end)
 @param String* target
 @param int start
 @param int end

 @description creates a substring from a target string and a start and end index
 @notes do not reuse the same variable when creating substrings. always use seperate variables
 @leaky false
*/
String* substring(String* source, int start, int end) {
    if (end - start <= 0 || start + end > source->length) {
        return NULL;
    }

    String* destination = createString(end - start + 1);

    for (int i = start; i < end; i++) {
        *(destination->content+(i - start)) = *(source->content+i);
    }
    // printf("Substring: %s\n", newString->content);
    return destination;
}

/*
int countOcurrancesInString(String *target, String *pattern)
 @param String *target
 @param String *pattern

 @description counts how many times a pattern string appears in a target string
 @leaky false
*/
int countOcurrancesInString(String *target, String *pattern) {
    int ocurrances = 0;
    for (int i = 0; i < target->length; i++) {
        if (*(target->content+i) == *(pattern->content)) {
            for (int g = 0; g < pattern->length; g++) {
                if (i+g > target->length) {
                    break;
                }
                if (*(target->content+i+g) != *(pattern->content+g)) {
                    break;
                }
                if (g == pattern->length - 1) {
                    ocurrances++;
                }
            }
        }
    }
    return ocurrances;
}

/*
int* getOcurrancesInString(String *target, String *pattern)
 @param String *target
 @param String *pattern

 @description finds where each pattern string starts in a target string
 @leaky true
*/
int* getOcurrancesInString(String *target, String *pattern) {
    // printf("Getting ocurrances of '%s' inside of '%s'\n", pattern->content, target->content);
    int numberOfOcurrances = countOcurrancesInString(target, pattern);
    int* indexes = (int*)malloc(sizeof(int) * numberOfOcurrances);
    int indexOffset = 0;
    String* temporarySubstring;
    for (int i = 0; i < target->length; i++) {
        temporarySubstring = substring(target, i, i+pattern->length);
        if (isEqual(temporarySubstring, pattern) == 0) {
            // printf("MATCH! @ %d\n", i);
            *(indexes+indexOffset) = i;
            indexOffset++;
        }
    }

    // printf("Done getting ocurrances...\n");
    return indexes;
}

/*
int splitString(String* target, String* delimiter, String** stringSplits)
 @param String* target
 @param String* delimiter
 @param String** stringSplits

 @description splits a string into several substrings based on a delimiter
 @leaky true
*/
int splitString(String* target, String* delimiter, String** stringSplits) {
    // printf("Splitting '%s' by '%s'\n", target->content, delimiter->content);

    int numberOfLocations = countOcurrancesInString(target, delimiter);
    int* splitLocations = getOcurrancesInString(target, delimiter);

    int start = 0;
    for (int i = 0; i < numberOfLocations; i++) {
        // printf("Splitting from %d to %d\n", start, *(splitLocations+i));
        *(stringSplits+i) = substring(target, start, *(splitLocations+i));
        start = *(splitLocations+i) + 1;
    }
    *(stringSplits + numberOfLocations) =
        substring(target, start, target->length);

    // printf("Done splitting string\n");
    return numberOfLocations + 1;
}

/*
int isEqual(String* string1, String* string2)
 @param String* string1
 @param String* string2

 @description checks if two strings are the same length and if they have all the same characters in the same order
 @leaky false
*/
int isEqual(String* string1, String* string2) {
    // printf("Comparing '%s' vs. '%s'\n", string1->content, string2->content);

    if (string1->length != string2->length) {
        return 1; // different sizes
    }
    for (int i = 0; i < string1->length; i++) {
        // printf("Comparing Characters: '%c' vs. '%c'\n", *(string1->content+i), *(string2->content+i));
        if (*(string1->content+i) != *(string2->content+i)) {
            // printf("X : Strings do not match : '%c' vs '%c'\n", *(string1->content+i), *(string2->content+i));
            return -1; // they don't match
        }
    }
    // printf("Strings Match\n");
    return 0; // the strings match
}
