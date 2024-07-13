#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Triangle{
    private:
        int base;
        int height;
    public:
        void initialize_t(int b, int h){
            base = b;
            height = h;
        }
        int area_t(){
            return base*height;
        }
        void changebase(int b){
            base = b;
        }
};

struct rectangle{
    int length;
    int breadth;
};

void initialize_r(struct rectangle *r, int l, int b){

    r->length = l;
    r->breadth = b;
}

int area_r(struct rectangle r){
    return (r.length)*(r.breadth);
}

void changelength(struct rectangle *r, int l){
    r->length = l;
}

int main(){
    struct rectangle r;
    printf("Rectangle: \n");
    initialize_r(&r, 10, 5);
    printf("%d\t", area_r(r));
    changelength(&r, 20);
    printf("%d\n", area_r(r));

    Triangle t;
    printf("Triangle: \n");
    t.initialize_t(10,5);
    printf("%d\t", t.area_t());
    t.changebase(20);
    printf("%d\n", t.area_t());
    return 0;
}