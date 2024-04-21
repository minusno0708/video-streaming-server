#include<stdio.h>

void convert_to_m3u8(char *filepath) {
    printf("convert %s\n", filepath);
}

int main() {
    char *filepath = "../videos/sample.mp4";
    convert_to_m3u8(filepath);

    return 0;
}
