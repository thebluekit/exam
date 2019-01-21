#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "list.h"

void printlist(node *head);
void getlist(FILE *f, node **head);
void printlistgreater(node *head, float mean);

#endif // IO_H
