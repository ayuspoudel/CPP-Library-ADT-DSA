#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rectangle{
    int length;
    int breadth;
};

int main(){
    struct rectangle *p;
    p = (struct rectangle*) malloc(sizeof(struct rectangle));
    p->length = 10;
    p->breadth = 11;
    return 0;
}