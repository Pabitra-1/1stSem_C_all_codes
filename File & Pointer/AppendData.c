#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("file.txt", "a");  

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter text to append: ");
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);

    printf("Data appended successfully.\n");

    fclose(fp);
    return 0;
}
