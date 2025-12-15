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
