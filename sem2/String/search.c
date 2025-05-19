#include "string.h"

int search(const char *SInputFile, char *word) {
    FILE *f = fopen(SInputFile, "r");
    if (f == NULL) {
        return -1;
    }

    int linecurrlength = 0, minlen = -1, flag = 0;
    int c;
    char line[513]; //512 символов + '\0'
    char minword[513] = "";

    while ((c = fgetc(f)) != EOF) { //чтение по символам
        if (c == '\n' || c == '\r' || c == ' ' || c == '.' || c == ',') {
            line[linecurrlength] = '\0';
            if (linecurrlength != 0 && line[0] == 'A') {
                flag = 1;
                for (int i = 0; i < linecurrlength; i++) {
                    if (!isupper((unsigned char)line[i])) {
                        flag = 0;
                        break;
                    }
                }
                if (flag && (minlen == -1 || linecurrlength < minlen)) {
                    strcpy(minword, line);
                    minlen = linecurrlength;
                }
            }
            linecurrlength = 0;
        } else {
            line[linecurrlength] = (char)c;
            linecurrlength++;
        }
    }

    fclose(f);

    if (minlen != -1) {
        strcpy(word, minword);
        return minlen;
    } else {
        return 0;
    }
}
