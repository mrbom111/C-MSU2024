#include "string.h"
int main() {
    char result[513];

    if (search("data.dat", result) == 1) {
        if (result[0]!='\0') {
            printf("Shortest Word: %s", result);
        } else {
            printf("No Words Found");
        }
    } else {
        printf("File error");
    }

    return 0;
}
