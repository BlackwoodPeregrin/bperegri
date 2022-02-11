#include "test.h"

int check_number_na_povtor(int *buf_int, int len_buf, int number) {
    int res = 0;
    for (int i = 0; i < len_buf; i++) {
        if (buf_int[i] == number) res = 1;
    }
    return res;
}

void sort_by_upper(int *buf, int len_buf) {
    int temp;
    for (int i = 0; i < len_buf - 1; i++) {
        for (int j = 0; j < len_buf - i - 1; j++) {
            if (buf[j] > buf[j+1]) {
                temp = buf[j];
                buf[j] = buf[j+1];
                buf[j+1] = temp;
            }
        }
    }
}

void sort_by_lower(int *buf, int len_buf) {
    int temp;
    for (int i = 0; i < len_buf - 1; i++) {
        for (int j = 0; j < len_buf - i - 1; j++) {
            if (buf[j] < buf[j+1]) {
                temp = buf[j];
                buf[j] = buf[j+1];
                buf[j+1] = temp;
            }
        }
    }
}

void sortBuf(int **buf, int *check_mas, int len_mas) {
    for (int i = 0; i < len_mas; i++) {
        if (i % 2 == 0) {
            sort_by_upper(buf[i], check_mas[i]);
        } else {
            sort_by_lower(buf[i], check_mas[i]);
        }
    }
}

void printBuf(int **buf, int *buff_with_lenth, int len_mas) {
    for (int i = 0; i < len_mas; i++) {
        printf("[");
        for (int j = 0; j < buff_with_lenth[i]; j++) {
            if (j == buff_with_lenth[i] - 1) {
                printf("%d]", buf[i][j]);
            } else {
                printf("%d, ", buf[i][j]);
            }
        }
        printf("\n");
    }
}

void deleteBuf(int **buf, int len_buf) {
    for (int i = 0; i < len_buf; i++) free(buf[i]);
    free(buf);
}

void generation_buffer(int **buf, int *buff_with_lenth, int len_buf) {
    int len_mas_i = 0;
    for (int i = 0; i < len_buf; i++) {
        len_mas_i = rand() + 1; // чтобы не сгенирировать 0
        while (check_number_na_povtor(buff_with_lenth, i, len_mas_i) == 1) {
            len_mas_i = rand() + 1;
        }
        buff_with_lenth[i] = len_mas_i;
        buf[i] = malloc(sizeof(int *) * buff_with_lenth[i]);
        for (int k = 0; k < buff_with_lenth[i]; k++) {
            buf[i][k] = rand();
        }
    }
}