#include "input.h"
#include "output.h"
#include "list.h"

int main()
{
    node_t *list = NULL;

    FILE *file_in = fopen("in_1.txt", "r");
    if (file_in == NULL)
        return -1;
    get_list(file_in, &list);

    FILE *file_out = fopen("out_1.txt", "w");
    if (file_in == NULL)
        return -1;
    out_list(file_out, list);

    free_list(list);
    fclose(file_in);
    fclose(file_out);

    return 0;
}
