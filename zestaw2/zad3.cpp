#include <stdio.h>

struct Point {
    float x;
    float y;
};

struct Rectangle {
    struct Point topleft;
    struct Point bottomright;
};

void funcPoint(struct Point* o) {
    o->x *= 2;
    o->y *= 2;
}

void calculateArea(struct Rectangle rect) {
    float width = rect.bottomright.x - rect.topleft.x;
    float height = rect.topleft.y - rect.bottomright.y;
    printf("Pole %f\n", width * height);
    printf("Obwod %f\n", (width + height) * 2);
    
}

int main() {
    struct Point uno = { 1, 2 };
    struct Rectangle rect = { {1, 4}, {5, 1} };

    printf("%f\n", uno.x);
    printf("%f\n", uno.y);

    funcPoint(&uno);

    printf("%f\n", uno.x);
    printf("%f\n", uno.y);

    calculateArea(rect);

    return 0;
}
