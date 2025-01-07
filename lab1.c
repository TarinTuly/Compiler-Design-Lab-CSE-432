#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    char token[100];


    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }


    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    int index = 0;
    while ((ch = fgetc(inputFile)) != EOF) {

        if (isalnum(ch) ) {
            token[index++] = ch;
        } else {
            if (index > 0) {

                token[index] = '\0';
                fprintf(outputFile, "%s\n", token);
                index = 0;
            }


            if (!isspace(ch)) {
                fprintf(outputFile, "%c\n", ch);
            }
        }
    }





    fclose(inputFile);
    fclose(outputFile);

    printf("successful\n");
    return 0;
}