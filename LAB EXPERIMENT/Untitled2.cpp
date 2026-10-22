#include <stdio.h>

int main() {
    FILE *f1, *f2;
    char ch;

    f1 = fopen("input.txt", "r");

    if (f1 == NULL) {
        printf("Cannot open input file");
        return 1;
    }

    f2 = fopen("output.txt", "w");

    if (f2 == NULL) {
        printf("Cannot create output file");
        fclose(f1);
        return 1;
    }

    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, f2);

    printf("File copied successfully");

    fclose(f1);
    fclose(f2);

    return 0;
}
