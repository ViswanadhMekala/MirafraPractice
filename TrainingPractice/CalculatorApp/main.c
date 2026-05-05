#include <stdio.h>
#include "calc.h"

int main() {
    double x = 10.0, y = 5.0;
    printf("Add: %.2f\n", add(x, y));
    printf("Div: %.2f\n", divide(x, 0)); // Test error handling
    return 0;
}
