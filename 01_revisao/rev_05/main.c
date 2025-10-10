#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &m, &n);

  int matriz[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  int p_l, p_c, lp_l, lp_c;
  scanf("%d %d", &p_l, &p_c);
  scanf("%d %d", &lp_l, &lp_c);

  p_l -= 1; p_c -= 1; lp_l -= 1; lp_c -= 1;

  matriz[p_l][p_c] = 2;

  char priority[4];

  scanf(" %c%c%c%c", &priority[0], &priority[1], &priority[2], &priority[3]);

  while (1) {
    printf("(%d,%d) ", p_l+1, p_c+1);

    if (p_l == lp_l && p_c == lp_c) {
      break;
    }

    for (int i = 0; i < 5; i++) {
      if (i == 4) {
        exit(EXIT_SUCCESS);
      }

      switch (priority[i]) {
        case 'C':
          if (p_l-1 >= 0 && matriz[p_l-1][p_c] == 0) {
            p_l--;
            matriz[p_l][p_c] = 2;
            break;
          }
          continue;

        case 'B':
          if (p_l+1 < m && matriz[p_l+1][p_c] == 0) {
            p_l++;
            matriz[p_l][p_c] = 2;
            break;
          }
          continue;

        case 'D':
          if (p_c+1 < n && matriz[p_l][p_c+1] == 0) {
            p_c++;
            matriz[p_l][p_c] = 2;
            break;
          }
          continue;

        case 'E':
          if (p_c-1 >= 0 && matriz[p_l][p_c-1] == 0) {
            p_c--;
            matriz[p_l][p_c] = 2;
            break;
          }
          continue;
      }

      break;
    }
  }
  
  exit(EXIT_SUCCESS);
}
