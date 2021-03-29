#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H
#include <stdio.h>

/*
** big_integer.h
** Code largely based on this repo: <https://github.com/andreazevedo/biginteger>
** Modifications: support for arbitrary large numbers, bigint multiplication
**/

typedef struct BigIntegerData {
  unsigned int *bits;
  // assume the number would not be larger than 2^INT_MAX
  int size;
  int capacity;
} BigIntegerData;

typedef struct BigInteger {
  int sign;
  BigIntegerData data;
} BigInteger;

/* create a big integer number */
BigInteger big_integer_create(long long value);
/* set a big integer number with a long long value*/
void big_integer_set(long long value, BigInteger *pBigInt);

/* create a big integer number from file in the specific format:
 *     sign size bits[0] bits[1] ... bits[size-1]
 */
BigInteger big_integer_create_from_file(FILE **ppFile);
/* output a big integer number to file in the specific format:
 *     sign size bits[0] bits[1] ... bits[size-1]
 */
void big_integer_output_to_file(const BigInteger bigInt, FILE **ppFile);
/* print a big integer number to stdout in the specific format:
 *     sign size bits[0] bits[1] ... bits[size-1]
 */
void big_integer_print(const BigInteger bigInt, const char *msg);

/* destroy(free) a big integer number */
void big_integer_destroy(BigInteger *pBigInt);

/* returns the big integer as int */
int big_integer_to_int(const BigInteger bigInt);

/* returns the big integer as long long */
long long big_integer_to_long_long(const BigInteger bigInt);

/* compare big integers */
int big_integer_compare(const BigInteger left, const BigInteger right);

/* adds two big integers together ( left + right ) */
BigInteger big_integer_add(const BigInteger left, const BigInteger right);
void big_integer_add_inplace(const BigInteger left, const BigInteger right,
                             BigInteger *pResult);

/* subtracts one big integer from another ( left - right ) */
BigInteger big_integer_subtract(const BigInteger left, const BigInteger right);
void big_integer_subtract_inplace(const BigInteger left, const BigInteger right,
                                  BigInteger *pResult);

/* increments the bigInteger by the amount specified */
void big_integer_increment(BigInteger *bigInt, const unsigned int value);

/* decrements the bigInteger by the amount specified */
void big_integer_decrement(BigInteger *bigInt, const unsigned int value);

/* multiply two big integers ( left * right ) */
BigInteger big_integer_multiply(const BigInteger left, const BigInteger right);
void big_integer_multiply_inplace(const BigInteger left, const BigInteger right,
                                  BigInteger *pResult);

#ifdef DEBUG
void big_integer_dump(const BigInteger bigInt);
#endif

#endif /* BIG_INTEGER_H */