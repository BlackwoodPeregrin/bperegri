#include "test.h"

int main() {
    int number;
    scanf("%d", &number);
    int buff_with_lenth[number];
    int **buf = NULL;
    buf = (int **)malloc(sizeof(int *) * number);
    generation_buffer(buf, buff_with_lenth, number);
    sortBuf(buf, buff_with_lenth, number);
    printBuf(buf, buff_with_lenth, number);
    deleteBuf(buf, number);
}
