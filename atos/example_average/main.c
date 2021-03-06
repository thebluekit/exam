#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "io.h"

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (!f)
        return -1;
    node *head = NULL;

    getlist(f, &head);

    float sum = listsum(head);
    int count = listcount(head);
    float mean = sum / count;

    printf("mean = %f\nsum = %.0f, count = %d\n", mean, sum, count);

    printf("list: ");
    printlist(head);

    printf("\ngreater than average: ");
    printlistgreater(head, mean);
    freelist(head);
    return 0;
}
