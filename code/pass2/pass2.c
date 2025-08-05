#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *intermediate, *optab, *symtab, *output, *prgmlength, *objectcode;
    char opcode[20], operand[20], label[20], mnemonic[20], code[20], value[20];
    char objectCode[20], textRecord[1000];
    int locctr = 0, start = 0, prgmLength = 0, length = 0, textstartAddr = 0;
    int firstText = 1;

    // Open files
    optab = fopen("optab.txt", "r");
    intermediate = fopen("intermediate.txt", "r");
    symtab = fopen("symtab.txt", "r");
    prgmlength = fopen("prgmlength.txt", "r");
    objectcode = fopen("objectcode.txt", "w");
    output = fopen("output.txt", "w");

    if (!optab || !intermediate || !symtab || !prgmlength || !objectcode || !output) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(intermediate, "%X\t%s\t%s\t%s", &locctr, label, opcode, operand);
    fprintf(output, "    %s %s %s\n", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        fscanf(prgmlength, "%X", &prgmLength);
        start = (int)strtol(operand, NULL, 16);
        fprintf(objectcode, "H^%s^%06X^%06X\n", label, start, prgmLength);
    }

    // Read first instruction
    fscanf(intermediate, "%X\t%s\t%s\t%s", &locctr, label, opcode, operand);
    textstartAddr = locctr;
    strcpy(textRecord, "");
    length = 0;

    while (strcmp(opcode, "END") != 0) {
        strcpy(objectCode, "");
        fprintf(output, "%04X %s %s %s ", locctr, label, opcode, operand);

        if (strcmp(opcode, "BYTE") == 0) {
            if (operand[0] == 'C' && operand[1] == '\'') {
                for (int i = 2; i < strlen(operand) - 1; i++) {
                    sprintf(objectCode + strlen(objectCode), "%02X", operand[i]);
                }
            }
        } else if (strcmp(opcode, "WORD") == 0) {
            sprintf(objectCode, "%06X", atoi(operand));
        } else if (strcmp(opcode, "RESB") == 0 || strcmp(opcode, "RESW") == 0) {
            if (strlen(textRecord) > 0) {
                fprintf(objectcode, "T^%06X^%02X^%s\n", textstartAddr, length / 2, textRecord);
                strcpy(textRecord, "");
                length = 0;
                firstText = 1;
            }
        } else {
            rewind(optab);
            while (fscanf(optab, "%s %s", mnemonic, code) != EOF) {
                if (strcmp(opcode, mnemonic) == 0) {
                    strcpy(objectCode, code);
                    break;
                }
            }

            char symLabel[20];
            rewind(symtab);
            while (fscanf(symtab, "%s %s", symLabel, value) != EOF) {
                if (strcmp(operand, symLabel) == 0) {
                    sprintf(objectCode + strlen(objectCode), "%04X", (int)strtol(value, NULL, 16));
                    break;
                }
            }
        }

        fprintf(output, "%s\n", objectCode);

        if (strlen(objectCode) > 0) {
            if (length + strlen(objectCode) > 60) {
                fprintf(objectcode, "T^%06X^%02X^%s\n", textstartAddr, length / 2, textRecord);
                strcpy(textRecord, "");
                textstartAddr = locctr;
                length = 0;
                firstText = 1;
            }

            if (firstText) {
                strcpy(textRecord, objectCode);
                firstText = 0;
            } else {
                strcat(textRecord, "^");
                strcat(textRecord, objectCode);
            }

            length += strlen(objectCode);
        }

        fscanf(intermediate, "%X\t%s\t%s\t%s", &locctr, label, opcode, operand);
    }

    if (strlen(textRecord) > 0) {
        fprintf(objectcode, "T^%06X^%02X^%s\n", textstartAddr, length / 2, textRecord);
    }

    fprintf(objectcode, "E^%06X\n", start);

    fclose(optab);
    fclose(intermediate);
    fclose(symtab);
    fclose(prgmlength);
    fclose(objectcode);
    fclose(output);

    return 0;
}

