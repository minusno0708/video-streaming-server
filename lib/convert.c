#include<stdio.h>

#define SEGMENT_DURATION 10

void convert_to_m3u8(char *filepath) {
    printf("convert %s\n", filepath);

    FILE *base = fopen(filepath, "r");
    FILE *encoded = fopen("../videos/sample.m3u8", "w");

    if (base == NULL || encoded == NULL) {
        printf("Failed to open file\n");
        return;
    }

    fclose(base);
    fclose(encoded);
}

int main() {
    char *filepath = "../videos/sample.mp4";
    convert_to_m3u8(filepath);

    return 0;
}
