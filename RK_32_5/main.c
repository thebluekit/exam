#include <stdio.h>
#include "funcs.h"

int main(int argc, char **argv)
{
    FILE *f = fopen("in.txt", "r");
    node_t *node = load_data(f);
    print_data(node);
    delete_node(node, "Perov");
    //delete_node(node, "Perov");
    printf("%s\n", "=================");
    print_data(node);
    free_list(node);
    //gluing(node);
    //print_data_2(node);
  // int a[3][3] = {
  //       {1, 2, 3},
  //       {4, 5}
  //   };

  //   for (int i = 0; i<3;i++)
  //   {
  //       for (int j = 0; j<3;j++)
  //           printf("%d ", a[i][j]);
  //       printf("\n");
  //   }

}
