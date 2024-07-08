#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];

    // Open the input file in read mode
    inputFile = fopen("vids.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file in write mode
    outputFile = fopen("vids_filtered.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Read the input file line by line
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Check if the line contains the string "/model"
        if (strstr(line, "/model") == NULL) {
            // Write the line to the output file if it does not contain "/model"
            fputs(line, outputFile);
        }
    }

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    printf("Lines not containing '/model' have been written to vids_filtered.txt\n");

    return 0;
}
