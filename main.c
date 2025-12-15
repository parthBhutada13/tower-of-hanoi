#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5
#define RODS 3
#define BASE_WIDTH (MAX * 2 + 1)

int rods[RODS][MAX];
int top[RODS];
int n;
int moves = 0;
int maxMoves;

void initialize() {
    for (int i = 0; i < RODS; i++)
        top[i] = -1;

    for (int i = n; i >= 1; i--)
        rods[0][++top[0]] = i;
}

void printCenteredDisk(int size) {
    int diskWidth = size * 2;
    int padding = (BASE_WIDTH - diskWidth) / 2;

    for (int i = 0; i < padding; i++)
        printf(" ");

    for (int i = 0; i < diskWidth; i++)
        printf("=");

    printf("\n");
}

void printRod() {
    int padding = BASE_WIDTH / 2;
    for (int i = 0; i < padding; i++)
        printf(" ");
    printf("|\n");
}

void display() {
    system("cls");

    printf("=== tower of hanoi === \n\n");

    for (int r = 0; r < RODS; r++) {
        printf("rod %d:\n\n", r + 1);

        if (top[r] == -1) {
            printRod();
        } else {
            for (int i = top[r]; i >= 0; i--) {
                printCenteredDisk(rods[r][i]);
            }
            printRod();
        }

        printf("\n");
    }
}

int findDisk(int disk, int *rodIndex) {
    for (int r = 0; r < RODS; r++) {
        if (top[r] != -1 && rods[r][top[r]] == disk) {
            *rodIndex = r;
            return 1;
        }
    }
    return 0;
}

int moveDisk(int disk, int toRod) {
    int fromRod;

    if (!findDisk(disk, &fromRod)) {
        printf("invalid move, disk %d is not on top.\n", disk);
        return 0;
    }

    if (top[toRod] != -1 && rods[toRod][top[toRod]] < disk) {
        printf("illegal move, larger disk on smaller disk.\n");
        return 0;
    }

    rods[fromRod][top[fromRod]--] = 0;
    rods[toRod][++top[toRod]] = disk;

    printf("moved disk %d from rod %d to rod %d\n",
           disk, fromRod + 1, toRod + 1);

    return 1;
}

int main() {
    char input;
    int disk, toRod;

    printf("enter the number of disks (1 to %d): ", MAX);
    scanf("%d", &n);

    maxMoves = pow(2, n) - 1;

    initialize();
    display();

    while (top[2] != n - 1 && moves < maxMoves) {
        printf("\nenter the disk number to move (1 to %d) or 'q' to quit: ", n);
        scanf(" %c", &input);

        if (input == 'q')
            break;

        disk = input - '0';

        printf("enter the rod number to move to (1, 2, or 3): ");
        scanf("%d", &toRod);
        toRod--;

        if (toRod < 0 || toRod > 2) {
            printf("invalid rod number!\n");
            continue;
        }

        if (moveDisk(disk, toRod)) {
            moves++;
            display();
        }
    }

    if (top[2] == n - 1) {
        printf("\ncongratulations, you moved all disks to rod 3.\n");
        printf("you completed the game in %d moves.\n", moves);
    }

    return 0;
}
