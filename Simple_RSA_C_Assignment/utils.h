#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

/*
 * Prints the hex value of the input, 16 values per line
 *
 * arg0: data
 * arg1: data len
 */
void print_hex(unsigned char *, size_t);


/*
 * Prints the input as string
 *
 * arg0: data
 * arg1: data len
 */
void print_string(unsigned char *, size_t);


/*
 * Prints the usage message
 */
void usage(void);


/*
 * Checks the validity of the arguments
 *
 * arg0: path to input file
 * arg1: path to output file
 * arg2: path to key file
 * arg3: operation mode
 */
void check_args(char *, char *, char *, int);

unsigned char *read_from_file(char *);

int get_file_length(char *);

void write_key_to_file(char *, size_t, size_t);

void write_plaintext_to_file(char *, unsigned char *, int);

void write_cipher_to_file(char *, unsigned char *, int);


#endif /* _UTILS_H */
