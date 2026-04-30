#include <stdio.h>

int main() {
    FILE *file;
    char text[100];

    // Writing to file
    file = fopen("file.txt", "w");
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    fputs(text, file);
    fclose(file);

    // Reading from file
    file = fopen("file.txt", "r");
    printf("\nContent of file:\n");
    while (fgets(text, sizeof(text), file) != NULL) {
        printf("%s", text);
    }
    fclose(file);

    return 0;
}
