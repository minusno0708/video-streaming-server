#include <stdio.h>

#define SEGMENT_DURATION 10

void convert_to_m3u8(char *filepath) {
    printf("convert %s\n", filepath);

    FILE *base_file = fopen(filepath, "r");
    FILE *m3u8_file = fopen("../videos/sample/sample.m3u8", "w");

    if (base_file == NULL || m3u8_file == NULL) {
        printf("Failed to open file\n");
        return;
    }

    // m3u8ファイルにヘッダを書き込む
    fprintf(m3u8_file, "#EXTM3U\n");
    fprintf(m3u8_file, "#EXT-X-VERSION:3\n");

    int segment_counter = 0;

    while (1) {
        // セグメントファイルを作成
        char buffer[1024];
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), base_file);

        if (bytes_read == 0) {
            break;
        }

        char segment_name[1024];
        sprintf(segment_name, "../videos/sample/segment-%d.ts", segment_counter);

        FILE *segment_file = fopen(segment_name, "w");
        fwrite(buffer, 1, bytes_read, segment_file);
        fclose(segment_file);

        // m3u8ファイルにセグメント情報を書き込む
        fprintf(m3u8_file, "#EXTINF:%d,\n", SEGMENT_DURATION);
        fprintf(m3u8_file, "sample-%d.ts\n", segment_counter);

        segment_counter++;
    }

    fclose(base_file);
    fclose(m3u8_file);
}

int main() {
    char *filepath = "../videos/sample.mp4";
    convert_to_m3u8(filepath);

    return 0;
}
