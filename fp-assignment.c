#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "fptypes.h"

union float_converter {
    uint32_t intval;
    float floatval;
} __attribute__((packed));

static float_t example_val = {2, 3, 4};


/*
1) Give the bit patterns of each field in the structure when the number
   corresponds to following values:
*/
/*   a) Returns Inf value */
float_t get_Inf(void) {
    float_t answer = {0, 255, 0};
//  float_t answer = {1,255,0};
    return answer;
}

/*   b) Returns NaN value */
float_t get_NaN(void) {
    float_t answer = {0, 255, 1};
    return answer;
}

/*   c) Returns float value for 1 */
float_t get_1(void) {
    float_t answer = {0, 127, 0};
    return answer;
}

/*   d) Returns float value for 0 */
float_t get_0(void) {
    float_t answer = {0, 0, 0};
//  float_t answer = {1,0,0};
    return answer;
}

/*   e) Returns Smallest denormalized value */
float_t get_smallest_denormalized(void) {
    float_t answer = {0, 0, 1};
    return answer;
}

/*
2) Implement the body of the prototypes:
*/

/* a) Given a C float data type, returns the equivalent float_t data
 * struct */
float_t fp_encode(float b) {
    union float_converter name;
    name.floatval = b;
//
//
//
    unsigned int sign = name.intval >> 31;
    printf("%u \n", sign);


    name.intval = name.intval & ~(1 << 31);
    unsigned int exp = name.intval >> 23;
    printf("%u \n", exp);


    name.intval = name.intval << 8;
    name.intval = name.intval & ~(1 << 31);
    name.intval = name.intval >> 8;
    unsigned int mant = name.intval;





    // TIP: You may want to use a union with a uint32_t, shift and bitwise
    // operators for this.  Also, think about whether the endianness of your
    // machine will affect the way you want to interpret the float.

    float_t answer = {sign, exp, mant};
    return answer;
}

/* b) Given a float_t struct, returns the equivalent float C data type */
float fp_decode(float_t a) {
    union float_converter name;
    name.intval = 0;
    name.intval = name.intval | a.mantissa;
    name.intval = name.intval | (a.exponent << 23);
    name.intval = name.intval | (a.sign << 31);

    printf("%u \n", name.intval);
    return name.floatval;
}

/* c) Compute -a, return the result */
float_t fp_negate(float_t a) {
    // TIP: This is be the easiest operation you will be implementing. You just
    // need to flip the sign.

    float_t answer = example_val;
    // TODO: Your implementation here
    return answer;
}

/* d) Add two float_t numbers, return the result */
float_t fp_add(float_t a, float_t b) {
    // TIP: Refer to the lecture slides about floating point numbers to implement
    // this operation.  You may also want to implement functions for
    // denormalization, normalization, round_even to implement this operation.
    //
    // Remember that the mantissa in floating point numbers is a fraction and
    // hence leading and trailing zeroes have different semantics than for normal
    // numbers.  Also note that you can't use floating point addition to add
    // mantissas.

    float_t answer = example_val;
    // TODO: Your implementation here
    return answer;
}

/* e) Multiply two float_t numbers, return the result */
float_t fp_mul(float_t a, float_t b) {
    // TIP:  Just like in the ``Addition`` operation, mantissa here is the
    // fraction.  You can't use floating point operations to multiply mentisa's.
    // Don't worry about all the corner cases in the beginning, you can extend
    // your solution to incorporate all corner cases later.

    float_t answer = example_val;
    // TODO: Your implementation here
    return answer;
}
