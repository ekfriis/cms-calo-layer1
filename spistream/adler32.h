/*
 * =============================================================================
 *
 *       Filename:  adler32.h
 *
 *    Description:  Adler-32 Checksum.  Adapted from
 *                  https://en.wikipedia.org/wiki/Adler-32
 *
 * =============================================================================
 */

#ifndef ADLER32_9IRJ0M8H
#define ADLER32_9IRJ0M8H

#include <stdint.h>

// Compute the Adler-32 checksum.
/* where data is the location of the data in physical memory and
 * len is the length of the data in bytes */
uint32_t adler32(const unsigned char* data, int len);

// Compute the checksum of the first len-1 words in in data and store it
// as the last word.
void add_checksum(uint32_t* data, int len);

// Returns if 1 if the checksum in the last position is consistent, 0 if not.
int verify_checksum(const uint32_t* data, int len);

#endif /* end of include guard: ADLER32_9IRJ0M8H */
