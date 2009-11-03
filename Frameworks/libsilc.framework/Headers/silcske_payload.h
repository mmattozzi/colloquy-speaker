/*

  silcske_payload.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2000 - 2002 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silcske/SKE Payloads
 *
 * DESCRIPTION
 *
 * This interface defines the implementation of the SKE Payloads, as
 * defined by the SKE protocol. This interface is mainly used by the SKE
 * library, however all structures are public and the interface can be used
 * by the application if needed. Usually application does not need use this
 * interface.
 *
 ***/

#ifndef SILCSKE_PAYLOAD_H
#define SILCSKE_PAYLOAD_H

/****s* silcske/SilcSKEPayloads/SilcSKEStartPayload
 *
 * NAME
 * 
 *    typedef struct SilcSKEStartPayloadStruct SilcSKEStartPayload;
 *
 * DESCRIPTION
 *
 *    This context is the actual Key Exchange Start Payload and is allocated
 *    by silc_ske_payload_start_decode. It is freed by calling the
 *    silc_ske_payload_start_free function.
 *
 ***/
typedef struct SilcSKEStartPayloadStruct SilcSKEStartPayload;

/****s* silcske/SilcSKEPayloads/SilcSKEKEPayload
 *
 * NAME
 * 
 *    typedef struct SilcSKEKEPayloadStruct SilcSKEKEPayload;
 *
 * DESCRIPTION
 *
 *    This context is the actual Key Exchange Payload and is allocated
 *    by silc_ske_payload_ke_decode. It is freed by calling the
 *    silc_ske_payload_ke_free function. 
 *
 ***/
typedef struct SilcSKEKEPayloadStruct SilcSKEKEPayload;

/* SILC Key Exchange Start Payload */
struct SilcSKEStartPayloadStruct {
  unsigned char flags;
  SilcUInt16 len;

  unsigned char *cookie;
  SilcUInt16 cookie_len;

  unsigned char *version;
  SilcUInt16 version_len;

  SilcUInt16 ke_grp_len;
  unsigned char *ke_grp_list;

  SilcUInt16 pkcs_alg_len;
  unsigned char *pkcs_alg_list;

  SilcUInt16 enc_alg_len;
  unsigned char *enc_alg_list;
  
  SilcUInt16 hash_alg_len;
  unsigned char *hash_alg_list;

  SilcUInt16 hmac_alg_len;
  unsigned char *hmac_alg_list;

  SilcUInt16 comp_alg_len;
  unsigned char *comp_alg_list;
};

/* SILC Key Exchange Payload */
struct SilcSKEKEPayloadStruct {
  SilcUInt16 pk_len;
  unsigned char *pk_data;
  SilcUInt16 pk_type;

  SilcMPInt x;

  SilcUInt16 sign_len;
  unsigned char *sign_data;
};

/* Prototypes */

/****f* silcske/SilcSKEPayloads/silc_ske_payload_start_encode
 *
 * SYNOPSIS
 *
 *    SilcSKEStatus silc_ske_payload_start_encode(SilcSKE ske,
 *                                                SilcSKEStartPayload *payload,
 *                                                SilcBuffer *return_buffer);
 *
 * DESCRIPTION
 *
 *    Utility function used to encode Key Exchange Start Payload from the
 *    `payload' structure. The encoded buffer is returned into the
 *    `return_buffer' and the caller must free it.
 *
 ***/
SilcSKEStatus silc_ske_payload_start_encode(SilcSKE ske,
					    SilcSKEStartPayload *payload,
					    SilcBuffer *return_buffer);

/****f* silcske/SilcSKEPayloads/silc_ske_payload_start_decode
 *
 * SYNOPSIS
 *
 *    SilcSKEStatus 
 *    silc_ske_payload_start_decode(SilcSKE ske,
 *                                  SilcBuffer buffer,
 *                                  SilcSKEStartPayload **return_payload);
 *
 * DESCRIPTION
 *
 *    Utility function used to decode Key Exchange Start Payload from the
 *    `buffer' data buffer. The decoded payload is returned into the
 *    `return_payload' and the caller must free it.
 *
 ***/
SilcSKEStatus 
silc_ske_payload_start_decode(SilcSKE ske,
			      SilcBuffer buffer,
			      SilcSKEStartPayload **return_payload);

/****f* silcske/SilcSKEPayloads/silc_ske_payload_start_free
 *
 * SYNOPSIS
 *
 *    void silc_ske_payload_start_free(SilcSKEStartPayload *payload);
 *
 * DESCRIPTION
 *
 *    Frees the Key Exchange Start Payload indicated by `payload'.
 *
 ***/
void silc_ske_payload_start_free(SilcSKEStartPayload *payload);

/****f* silcske/SilcSKEPayloads/silc_ske_payload_ke_encode
 *
 * SYNOPSIS
 *
 *    SilcSKEStatus silc_ske_payload_ke_encode(SilcSKE ske,
 *                                             SilcSKEKEPayload *payload,
 *                                             SilcBuffer *return_buffer);
 *
 * DESCRIPTION
 *
 *    Utility function used to encode Key Exchange Payload from the
 *    `payload' structure. The encoded buffer is returned into the
 *    `return_buffer' and the caller must free it.
 *
 ***/
SilcSKEStatus silc_ske_payload_ke_encode(SilcSKE ske,
					 SilcSKEKEPayload *payload,
					 SilcBuffer *return_buffer);

/****f* silcske/SilcSKEPayloads/silc_ske_payload_ke_decode
 *
 * SYNOPSIS
 *
 *    SilcSKEStatus silc_ske_payload_ke_decode(SilcSKE ske,
 *                                             SilcBuffer buffer,
 *                                             SilcSKEKEPayload 
 *                                               **return_payload);
 *
 * DESCRIPTION
 *
 *    Utility function used to decode Key Exchange Payload from the
 *    `buffer' data buffer. The decoded payload is returned into the
 *    `return_payload' and the caller must free it.
 *
 ***/
SilcSKEStatus silc_ske_payload_ke_decode(SilcSKE ske,
					 SilcBuffer buffer,
					 SilcSKEKEPayload **return_payload);

/****f* silcske/SilcSKEPayloads/silc_ske_payload_ke_free
 *
 * SYNOPSIS
 *
 *    void silc_ske_payload_ke_free(SilcSKEKEPayload *payload);
 *
 * DESCRIPTION
 *
 *    Frees the Key Exchange Payload indicated by `payload'.
 *
 ***/
void silc_ske_payload_ke_free(SilcSKEKEPayload *payload);

#endif /* SILCSKE_PAYLOAD_H */
