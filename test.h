#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#include <stdio.h>
#include <stdlib.h>

void generation_buffer(int **buf, int *buff_with_lenth, int len_buf);
void deleteBuf(int **buf, int len_buf);
void printBuf(int **buf, int *buff_with_lenth, int len_mas);
void sortBuf(int **buf, int *check_mas, int len_mas);
void sort_by_lower(int *buf, int len_buf);
void sort_by_upper(int *buf, int len_buf);
int check_number_na_povtor(int *buf_int, int len_buf, int number);

#endif  //  SRC_TEST_H_
