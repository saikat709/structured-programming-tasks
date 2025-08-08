#include <stdio.h>
#include <string.h>

int main(){

    char query[100];
    int queryLength = 0;
    char currentLine[100];

    printf("Text to search: ");
    scanf("%[^\n].*c", query);
    queryLength = strlen(query);

    printf("Searching for: %s\n", query);

    FILE* file = fopen("./check.txt", "r");
    if ( file == NULL ){
        printf("Could not open file.");
        return 1;
    }

    char containingLines[10000][300];
    int count = 0;
    int lineCount = 0;
    int currentIndex = 0;

    while ( (fgets(currentLine, sizeof(currentLine), file)) != NULL) {
        size_t lineLength = strlen(currentLine);
        int isAddedLine = 0;
        for ( int i = 0; i < lineLength - queryLength; ++i){
            if ( query[0] == currentLine[i] ){
                int isfullMatch = 1;
                for ( int j = 0; j < queryLength; j++ ){
                    if ( query[j] != currentLine[i+j] ) isfullMatch = 0;
                }

                if (isfullMatch ){
                    count++;
                    if ( !isAddedLine ) strcpy(containingLines[currentIndex++], currentLine);
                    isAddedLine = 1;
                }
            }
        }
    }

    fclose(file);

    printf("Count: %d\n", count);
    printf("Line contains the pattern ( Not Repeated ): \n" );
    for( int i = 0; i < currentIndex; ++i ){
        printf("%s", containingLines[i]);
    }

    return 0;
}