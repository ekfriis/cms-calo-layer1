/*
 * =====================================================================================
 *
 *       Filename:  adler32.c
 *
 *    Description:  Test checksum functionality.
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <string.h>

#include "minunit.h"
#include "adler32.h"

static char* test_adler32(void) {
  uint32_t my_data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  uint32_t my_data2[10] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 1};

  mu_assert("detect_difference", 
      adler32((void*)my_data, 40) != adler32((void*)my_data2, 40));
  mu_assert_eq("is_same", 
      adler32((void*)(my_data+1), 20), adler32((void*)(my_data2 + 1), 20));
  return 0;
}

static char* test_checksumming(void) {
  uint32_t my_data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};

  add_checksum(my_data, 10);

  mu_assert("end modified", my_data[9] != -1);

  mu_assert("closure", verify_checksum(my_data, 10));

  my_data[2] = 1000;

  mu_assert("detect error", !verify_checksum(my_data, 10));
      
  return 0;
}

int tests_run;

char * all_tests(void) {
  printf("\n\n=== adler32 tests ===\n");
  mu_run_test(test_adler32);
  mu_run_test(test_checksumming);
  return 0;
}
