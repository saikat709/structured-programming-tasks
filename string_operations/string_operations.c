#include <string.h>
#include <stdio.h>

void replace( char str[], char sub[], int start ){
    for( int i = 0; sub[i] != '\0'; i++ ) str[start-1+i] = sub[i];
}

void search( char str[], char sub[] ){
    int len_sub = strlen(sub);
    int len_str = strlen(str);
    for( int i  = 0; str[i] != '\0'; i++ ){
        if (str[i] == sub[0] ){
            int j = 0;
            while( j < len_sub && sub[j] == str[i+j]  ) j++;
            if( j == len_sub ){
                printf("Found at position: %d\n", i+1);
                i += j-1;
            }
        }
    }
}

void deleteSub( char str[], char sub[]){
    int len_sub = strlen(sub);
    int len_str = strlen(str);
    int ind = 0;
    for( int i  = 0; str[i] != '\0'; i++ ){
        if (str[i] == sub[0] ){
            int j = 0;
            while( j < len_sub && sub[j] == str[i+j]  ) j++;
            if( j == len_sub ) i += j;
        }
        str[ind++] = str[i];
    }
    str[ind] = '\0';
}

void insertSub(char str[], char sub[], int pos ){
    int len_sub = strlen(sub);
    int len_str = strlen(str);
    int ind = 0;

    for( int i = 0; pos - 1 + i <= len_str; i++ )  // str[len_str] == '\0'
        str[len_str - i + len_sub] = str[len_str - i];

    for( int i = 0; i < len_sub; i++ )
        str[i + pos - 1] = sub[i];    
}


int main(){
    char str[100] = "my name is saikat. my name.";
    char sub[100] = "my ";

    search(str, sub);        printf("%s\n", str);
    deleteSub(str, sub);     printf("%s\n", str);
    insertSub(str, sub, 6);  printf("%s\n", str);
    replace(str, sub, 6);    printf("%s\n", str);

    return 0;
}