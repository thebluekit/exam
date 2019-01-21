#include "input.h"
#include "output.h"
#include "list.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return -1;

    node_t *list = NULL;

    FILE *file_in = fopen(argv[1], "r");
    if (file_in == NULL)
        return -1;
    get_list(file_in, &list);

    FILE *file_out = fopen(argv[2], "w");
    if (file_in == NULL)
        return -1;

    del_more_than_10(&list);

    out_list(file_out, list);

    free_list(list);
    fclose(file_in);
    fclose(file_out);

    return 0;
}
