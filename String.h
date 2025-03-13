#ifndef STRING_H
#define STRING_H

struct String {
    char* content;
    int length;
    int size;
};

typedef struct String String;

String* createString(int size);
void fillString(String* target, char* content);
void printString(String* target);
String* substring(String* target, int start, int end);
int countOcurrancesInString(String* target, String* pattern);
int* getOcurrancesInString(String* target, String* pattern);
int splitString(String* target, String* delimiter, String** stringSplits);
int isEqual(String* string1, String* string2);

#endif
