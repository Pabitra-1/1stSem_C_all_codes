#include <stdio.h>

#define MAX 20

int rods[3][MAX];
int top[3] = {-1, -1, -1};

void moveDisk(int a, int b, char name[]) {
    int disk;

    if (top[a] == -1) {
        disk = rods[b][top[b]--];
        rods[a][++top[a]] = disk;
    }
    else if (top[b] == -1) {
        disk = rods[a][top[a]--];
        rods[b][++top[b]] = disk;
    }
    else if (rods[a][top[a]] < rods[b][top[b]]) {
        disk = rods[a][top[a]--];
        rods[b][++top[b]] = disk;
    }
    else {
        disk = rods[b][top[b]--];
        rods[a][++top[a]] = disk;
    }

    printf("Move disk %d from %c to %c\n",
           disk, name[a], name[b]);
}

int main() {
    int n, i, moves;
    int source = 0, auxiliary = 1, destination = 2;

    char name[3] = {'A', 'B', 'C'};

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Enter disks between 1 and %d!\n", MAX);
        return 0;
    }

    for (i = n; i >= 1; i--) {
        rods[source][++top[source]] = i;
    }

    if (n % 2 == 0) {
        int temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    moves = (1 << n) - 1;

    for (i = 1; i <= moves; i++) {

        if (i % 3 == 1) {
            moveDisk(source, destination, name);
        }
        else if (i % 3 == 2) {
            moveDisk(source, auxiliary, name);
        }
        else {
            moveDisk(auxiliary, destination, name);
        }
    }

    return 0;
}