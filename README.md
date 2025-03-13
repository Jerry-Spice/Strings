# Strings

By _Josh Brandon_

## About

I am currently in school for Computer Science and I'm learning C as a result. I've done some C before but the thing that frustrates me to no end is that we're not supposed to use strings. I understand that they're unsafe so I figured I would make my own strings that are safe. Also there are many functions with the included strings library that are either missing or just obnoxious to use. So I made my own using a custom structure.
Of course though I am still learning so this implementation is very leaky. I would not recommend using this until the memory leaks are fixed.

Until then I have this poem (courtesy of ChatGPT):

The memory leaks, the heap runs dry,
Yet for today, we’ll let it lie.
One day we’ll patch this cursed flow,
But not today—just let it go.

## Struct and Tpye Definition

```
struct String {
    char* content;
    int length;
    int size;
};
typedef struct String String;
```

## Function Definitions

```
String* createString(int size); // allocates memory for a string (LEAKY)
```

```
void fillString(String* target, char* content); // fills in and fixes size issues for strings (LEAKY)
```

```
void printString(String* target); // prints a string
```

```
String* substring(String* target, int start, int end); // creates a substring from a string based on a start and end index (LEAKY)
```

```
int countOcurrancesInString(String* target, String* pattern); // counts how many pattern strings appear in the target string
```

```
int* getOcurrancesInString(String* target, String* pattern); // finds the indecies for where the pattern strings start in the target string (LEAKY)
```

```
int splitString(String* target, String* delimiter, String** stringSplits); // splits a string into many substrings according to a delimiter (SUPER LEAKY!)
```

```
int isEqual(String* string1, String* string2); // checks if two strings are the same length and if they have all the same characters
```
