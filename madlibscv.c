//Kenneth Cardinalli, Jeff Shoemaker, Cosmo Vazquez Tirado
//Final Project -Madlibs-
//12-3-2024


#include<stdio.h>
#define STR_CAP 100
#define ROW 100
#define COLUMN 100
#define FILE_NAME "madlib1.txt"

// Function prototypes
void stringCopy(char[], char[]);
void stringSwap(char[], char[]);
void userPrompt(char[][COLUMN], char[][COLUMN]);
void textGrab(FILE* fPtr, char[][COLUMN]);
void displayMadlib(char[ROW][COLUMN]);

int main() {
    char fullText[ROW][COLUMN], swappedText[ROW][COLUMN], words[10][COLUMN];
    
    FILE* fPtr;
    fPtr = fopen(FILE_NAME, "r");
    if(fPtr == NULL){    
        printf("Can't open file\n");
        return 0;
    }
    textGrab(fPtr, fullText);
    fclose(fPtr);
    userPrompt(words, fullText);
    displayMadlib(fullText);
    
    return 0;
}

// Functions
void stringCopy(char source[], char dest[]) {
    for(int index = 0; source[index] != '\0'; index++) {
        dest[index] = source[index];
    }
}

void stringSwap(char str1[], char str2[]) {
    char strCopy[STR_CAP];
    
    stringCopy(str1, strCopy);
    stringCopy(str2, str1);
    stringCopy(strCopy, str2);
}

void userPrompt(char words[][COLUMN], char fullText[][COLUMN]) {
    int index3 = 0;  // Start at the beginning of the words array

    for(int index = 0; index < ROW; index++) {
        for(int index2 = 0; fullText[index][index2] != '\0'; index2++) {
            switch(fullText[index][index2]) {
                case 'A':
                    printf("Please enter an adjective: ");
                    scanf("%s", words[index3]);
                    stringSwap(words[index3], fullText[index]);
                    index3 += 0;
                    break;
                case 'N':
                    printf("Please enter a noun: ");
                    scanf("%s", words[index3]);
                    stringSwap(words[index3], fullText[index]);
                    index3 += 0;
                    break;
                case 'V':
                    printf("Please enter a verb: ");
                    scanf("%s", words[index3]);
                    stringSwap(words[index3], fullText[index]);
                    index3 += 0;
                    break;
            }
        }
    }
}

void textGrab(FILE* fPtr, char fullText[ROW][COLUMN]) {
    for(int index = 0; index < ROW; index++) {
        fscanf(fPtr, "%s", fullText[index]);  // Read the file into fullText
    }
}

// displays final madlibs text
void displayMadlib(char fullText[ROW][COLUMN]) {
    for(int index = 0; index < ROW; index++) {
        printf(fullText[index]);
    }
}
