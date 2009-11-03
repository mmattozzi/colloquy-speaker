/*

  silcmath.h
 
  Author: Pekka Riikonen <priikone@silcnet.org>
 
  Copyright (C) 1997 - 2001 Pekka Riikonen
 
  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
 
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silcmath/SILC Math Interface
 *
 * DESCRIPTION
 *
 * SILC Math interface includes various utility functions such as
 * prime generation, and conversion routines. See the silcmp.h for the
 * SILC MP interface.
 *
 ***/

#ifndef SILCMATH_H
#define SILCMATH_H

#include "silcrng.h"

/****f* silcmath/SilcMathAPI/silc_math_gen_prime
 *
 * SYNOPSIS
 *
 *    int silc_math_gen_prime(SilcMPInt *prime, SilcUInt32 bits, bool verbose,
 *                            SilcRng);
 *
 * DESCRIPTION
 *
 *    Find appropriate prime. It generates a number by taking random bytes. 
 *    It then tests the number that it's not divisible by any of the small 
 *    primes and then it performs Fermat's prime test. I thank Rieks Joosten 
 *    (r.joosten@pijnenburg.nl) for such a good help with prime tests. 
 *
 *    If argument verbose is TRUE this will display some status information
 *    about the progress of generation.  If the `rng' is NULL then global
 *    RNG is used, if non-NULL then `rng' is used to generate the random
 *    number number.
 *
 ***/
bool silc_math_gen_prime(SilcMPInt *prime, SilcUInt32 bits, bool verbose,
			 SilcRng rng);

/****f* silcmath/SilcMathAPI/silc_math_prime_test
 *
 * SYNOPSIS
 *
 *    int silc_math_prime_test(SilcMPInt *p);
 *
 * DESCRIPTION
 *
 *    Performs primality testings for given number. Returns TRUE if the 
 *    number is probably a prime.
 *
 ***/
bool silc_math_prime_test(SilcMPInt *p);

#endif
