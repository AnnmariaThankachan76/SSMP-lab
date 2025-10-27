#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *input, *output;
    int i, j, length;
    char line[50], arr[10];

    // Open input file for reading
    input= fopen("input.txt", "r");
    if (input== NULL) {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    // Open output file for writing (overwrite mode)
    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error: Cannot create output.txt\n");
        fclose(input);
        return 1;
    }

    // Read line by line until EOF
    while (fscanf(input, "%s", line) != EOF) {
        if (line[0] == 'T') {
            // Extract starting address from the line
            for (i = 1, j = 0; i < 7; i++, j++) {
                arr[j] = line[i];
            }
            arr[j] = '\0';

            // Convert hex string to integer
            length = strtol(arr, NULL, 16);

            // Skip first 12 chars and read object codes
            i = 9;
            while (line[i] != '\0') {
                fprintf(output, "%X\t%c%c\n", length, line[i], line[i + 1]);
                length++;
                i = i + 2;
            }
        }
    }

    fclose(input);
    fclose(output);

    printf(" Output written to output.txt successfully.\n");
    return 0;
}
