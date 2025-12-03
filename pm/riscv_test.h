// See LICENSE for license details.

#ifndef _ENV_PHYSICAL_MULTI_CORE_H
#define _ENV_PHYSICAL_MULTI_CORE_H

#include "../p/riscv_test.h"

#undef RISCV_MULTICORE_DISABLE
#define RISCV_MULTICORE_DISABLE                                   \
  la t0, fromhost;                                                  \
  lw t1, 0(t0);                                                  \
  csrr t2, misa;                                                  \
  and t1, t1, t2;                                                 \
  bne t1, zero, 1f;                                               \
  li TESTNUM, 2;                                                  \
  li a7, 93;                                                      \
  li a0, 0;                                                       \
  ecall;                                                          \
1:

#define PM_TEST_DISABLE 1

#endif
