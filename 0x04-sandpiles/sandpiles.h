#ifndef _SANDPILES_H_
#define _SANDPILES_H_

static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int sandpiles_stable(int grid1[3][3], int grid2[3][3]);
void sandpile_spread(int grid1[3][3], int i, int j);

#endif
