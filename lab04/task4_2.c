#include <stdio.h>

int main(void) {
    int level;
    printf("Enter level number (0-3): ");
    if (scanf("%d", &level) != 1) {
        puts("Invalid input");
        return 1;
}
switch (level) {
    case 0: puts("ERROR");
    break;
    case 1: puts("WARN");
    break;
    case 2: puts("INFO");
    break;
    case 3: puts("DEBUG");
    break;
    default:
    puts("Invalid level");

return 2;
}
return 0;
}