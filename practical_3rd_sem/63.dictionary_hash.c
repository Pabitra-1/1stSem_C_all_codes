#include <stdio.h>
#include <string.h>

#define SIZE 10

struct Dictionary {
    char word[50];
    char meaning[100];
    int status;
};

struct Dictionary table[SIZE];

int hash(char word[]) {
    int sum = 0, i;

    for (i = 0; word[i] != '\0'; i++)
        sum = (sum + word[i]) % SIZE;

    return sum;
}

void insert() {
    char word[50], meaning[100];
    int index, i;

    printf("Enter word: ");
    scanf("%49s", word);

    printf("Enter meaning: ");
    scanf(" %99[^\n]", meaning);

    index = hash(word);

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 1 &&
            strcmp(table[pos].word, word) == 0) {
            printf("Word already exists\n");
            return;
        }

        if (table[pos].status == 0) {
            strcpy(table[pos].word, word);
            strcpy(table[pos].meaning, meaning);
            table[pos].status = 1;

            printf("Word inserted successfully\n");
            return;
        }
    }

    printf("Dictionary is full\n");
}

void search() {
    char word[50];
    int index, i;

    printf("Enter word to search: ");
    scanf("%49s", word);

    index = hash(word);

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 0)
            break;

        if (table[pos].status == 1 &&
            strcmp(table[pos].word, word) == 0) {
            printf("Word: %s\n", table[pos].word);
            printf("Meaning: %s\n", table[pos].meaning);
            return;
        }
    }

    printf("Word not found\n");
}

void display() {
    int i;

    printf("\nDictionary:\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i].status == 1) {
            printf("%s : %s\n",
                   table[i].word,
                   table[i].meaning);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}