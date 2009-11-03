/*

  rsa_internal.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2003 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef RSA_INTERNAL_H
#define RSA_INTERNAL_H

/* RSA Keys, includes both Private and Public key */
typedef struct {
  int bits;			/* bits in key */
  SilcMPInt n;			/* modulus */
  SilcMPInt e;			/* public exponent */
  SilcMPInt d;			/* private exponent (no CRT) */
  SilcMPInt p;			/* p */
  SilcMPInt q;			/* q */
  SilcMPInt dP;			/* CRT, d mod p - 1 */
  SilcMPInt dQ;			/* CRT, d mod q - 1 */
  SilcMPInt pQ;			/* CRT, p * (p ^ -1 mod q) mod n */
  SilcMPInt qP;			/* CRT, q * (q ^ -1 mod p) mod n */
  unsigned int pub_set : 1;	/* TRUE if n and e is set */
  unsigned int prv_set : 1;	/* TRUE if d is set */
  unsigned int crt     : 1;	/* TRUE if CRT is used */
} RsaKey;

bool rsa_generate_keys(RsaKey *key, SilcUInt32 bits,
		       SilcMPInt *p, SilcMPInt *q);
bool rsa_clear_keys(RsaKey *key);
bool rsa_public_operation(RsaKey *key, SilcMPInt *src, SilcMPInt *dst);
bool rsa_private_operation(RsaKey *key, SilcMPInt *src, SilcMPInt *dst);

#endif
