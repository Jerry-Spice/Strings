#ifndef STRING_H
#define STRING_H

struct String {
    char* content;
    int length;
    int size;
};

typedef struct String String;

/*
String* createString(int size)
 @param int size

 @description allocates memory for a string
 @leaky false
*/
String* createString(int size);
/*
void fillString(String* target, char* content)
 @param String* target
 @param char* content

 @description fills in the content for a string and ensures memory sizes match
 @leaky false
*/
void fillString(String* target, char* content);
/*
void deleteString(String* target)
 @param String* target

 @description frees the target string and the content within it
 @leaky false
*/
void deleteString(String* target);
/*
void printString(String* target)
 @param String* target

 @description prints out the string contents
 @leaky false
*/
void printString(String* target);
/*
String* substring(String* target, int start, int end)
 @param String* target
 @param int start
 @param int end

 @description creates a substring from a target string and a start and end index
 @notes do not reuse the same variable when creating substrings. always use seperate variables
 @leaky false
*/
String* substring(String* source, int start, int end);
/*
int countOcurrancesInString(String *target, String *pattern)
 @param String *target
 @param String *pattern

 @description counts how many times a pattern string appears in a target string
 @leaky false
*/
int countOcurrancesInString(String* target, String* pattern);
/*
int* getOcurrancesInString(String *target, String *pattern)
 @param String *target
 @param String *pattern

 @description finds where each pattern string starts in a target string
 @leaky true
*/
int* getOcurrancesInString(String* target, String* pattern);
/*
int splitString(String* target, String* delimiter, String** stringSplits)
 @param String* target
 @param String* delimiter
 @param String** stringSplits

 @description splits a string into several substrings based on a delimiter
 @leaky true
*/
int splitString(String* target, String* delimiter, String** stringSplits);
/*
int isEqual(String* string1, String* string2)
 @param String* string1
 @param String* string2

 @description checks if two strings are the same length and if they have all the same characters in the same order
 @leaky false
*/
int isEqual(String* string1, String* string2);

#endif
