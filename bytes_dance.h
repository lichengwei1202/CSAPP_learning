#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
typedef unsigned char * byte_pointer; 
void show_bytes(byte_pointer s, size_t len);
void show_int(int t);
void show_long(long t);
void show_short(short t);
void show_double(double t);
int is_little_endian_judge(int test);
int is_little_endian(void);
unsigned replace_byte(unsigned *x, int t, unsigned char b);
bool is_all_one(int x);
bool is_all_zero(int x);
bool is_low_one(int x);
bool is_high_zero(int x);
bool int_shift_are_arithmetic(void);
unsigned srl(unsigned x, int k);
unsigned sra(int x, int k);
bool any_odd_one(unsigned x);
int int_size_is_32(void);
int lower_one_mask(int n);
int rotate_left(unsigned x, int n);