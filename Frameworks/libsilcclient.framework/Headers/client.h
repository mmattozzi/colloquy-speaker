/*

  client.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2002 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef CLIENT_H
#define CLIENT_H

/* Forward declarations */
typedef struct SilcClientStruct *SilcClient;
typedef struct SilcClientConnectionStruct *SilcClientConnection;
typedef struct SilcClientPingStruct SilcClientPing;
typedef struct SilcClientAwayStruct SilcClientAway;
typedef struct SilcClientKeyAgreementStruct *SilcClientKeyAgreement;
typedef struct SilcClientFtpSessionStruct *SilcClientFtpSession;
typedef struct SilcClientEntryStruct *SilcClientEntry;
typedef struct SilcChannelEntryStruct *SilcChannelEntry;
typedef struct SilcServerEntryStruct *SilcServerEntry;
typedef struct SilcClientCommandStruct *SilcClientCommand;
typedef struct SilcClientCommandContextStruct *SilcClientCommandContext;
typedef struct SilcClientCommandReplyContextStruct
                                           *SilcClientCommandReplyContext;
typedef struct SilcChannelUserStruct *SilcChannelUser;
typedef struct SilcClientInternalStruct *SilcClientInternal;
typedef struct SilcClientConnectionInternalStruct 
					   *SilcClientConnectionInternal;
typedef struct SilcChannelPrivateKeyStruct *SilcChannelPrivateKey;
  
/* Client entry status */
typedef enum {
  SILC_CLIENT_STATUS_NONE       = 0x0000,
  SILC_CLIENT_STATUS_RESOLVING  = 0x0001,
} SilcEntryStatus;

#endif
