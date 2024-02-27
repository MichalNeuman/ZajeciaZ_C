#include <stdio.h>

typedef struct{
    float x;
    float y;
}Point;

typedef struct{
     Point topleft;
     Point bottomright;
}Rectangle;

void funcPoint( Point* o) {
    o->x *= 2;
    o->y *= 2;
}

void calculateArea( Rectangle rect) {
    float width = rect.bottomright.x - rect.topleft.x;
    float height = rect.topleft.y - rect.bottomright.y;
    printf("Pole %f\n", width * height);
    printf("Obwod %f\n", (width + height) * 2);
    
}

int main() {
     Point uno = { 1, 2 };
    Rectangle rect = { {1, 4}, {5, 1} };

    printf("%f\n", uno.x);
    printf("%f\n", uno.y);

    funcPoint(&uno);

    printf("%f\n", uno.x);
    printf("%f\n", uno.y);

    calculateArea(rect);

    return 0;
}
