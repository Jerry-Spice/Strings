#include <stdio.h>
#include <stdlib.h>

#include "String.h"


/*
int main()
 @param 

 @description blah blah blah
*/
int main() {

    String* someStuff = createString(10); // this is arbitrary
    String* space = createString(1);

    fillString(someStuff, "This is a bunch of words seperated by spaces");
    fillString(space, " ");

    // printf("%s\n", substring(someStuff, 2, someStuff->length)->content);

    // int spaceCounts = countOcurrancesInString(someStuff, space);
    // int* substringSpaces = getOcurrancesInString(someStuff, space);

    // printf("There are %d spaces in this string: '%s'\n", countOcurrancesInString(someStuff, space), someStuff->content);

    int spacesInSomeStuff = countOcurrancesInString(someStuff, space);
    String** splitUpWords = (String**)malloc(sizeof(String*) * (spacesInSomeStuff+ 1));
    int pieces = splitString(someStuff, space, splitUpWords);
    // printf("There are %d pieces\n", pieces);
    int i = 0;
    for (i = 0; i < pieces; i++) {
        printf("%s\n", (*(splitUpWords+i))->content);
        free((*(splitUpWords+i))->content);
        free(*(splitUpWords+i));
    }

    free(splitUpWords);
    free(someStuff);
    free(space);



    return 0;
}

