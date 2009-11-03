/*

  command_reply.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef COMMAND_REPLY_H
#define COMMAND_REPLY_H

/* Structure holding one command reply and pointer to its function. */
typedef struct {
  SilcCommandCb cb;
  SilcCommand cmd;
} SilcClientCommandReply;

/* Context holding pending command callbacks. */
typedef struct {
  SilcCommandCb callback;
  void *context;
} *SilcClientCommandPendingCallbacks;

/* Context sent as argument to all command reply functions */
struct SilcClientCommandReplyContextStruct {
  SilcClient client;
  SilcSocketConnection sock;
  SilcCommandPayload payload;
  SilcStatus status;
  SilcStatus error;
  SilcArgumentPayload args;
  SilcPacketContext *packet;

  /* If defined this executes the pending command. */
  SilcClientCommandPendingCallbacks callbacks;
  SilcUInt32 callbacks_count;
  SilcUInt16 ident;
  SilcUInt8 users;
};

/* Macros */

/* Command reply operation that is called at the end of all command replys.
   Usage: COMMAND_REPLY((ARGS, argument1, argument2, etc...)), */
#define COMMAND_REPLY(args) cmd->client->internal->ops->command_reply args
#define SILC_ARGS cmd->client, cmd->sock->user_data,			     \
             cmd->payload, TRUE, silc_command_get(cmd->payload), cmd->status

/* Error reply to application. Usage: COMMAND_REPLY_ERROR; */
#define COMMAND_REPLY_ERROR(error)					\
do {									\
  if (cmd->status == SILC_STATUS_OK) {					\
    cmd->client->internal->ops->					\
      command_reply(cmd->client, cmd->sock->user_data, cmd->payload,	\
                    FALSE, silc_command_get(cmd->payload), error);	\
  } else {								\
    void *arg1 = NULL, *arg2 = NULL;					\
    silc_status_get_args(cmd->status, cmd->args, &arg1, &arg2);		\
    cmd->client->internal->ops->					\
      command_reply(cmd->client, cmd->sock->user_data, cmd->payload,	\
                    FALSE, silc_command_get(cmd->payload), cmd->status,	\
	            arg1, arg2);					\
    silc_free(arg1);							\
    silc_free(arg2);							\
  }									\
} while(0)

/* Macro used to declare command reply functions */
#define SILC_CLIENT_CMD_REPLY_FUNC(func)				\
void silc_client_command_reply_##func(void *context, void *context2)

/* Prototypes */

void silc_client_command_reply_process(SilcClient client,
				       SilcSocketConnection sock,
				       SilcPacketContext *packet);
void silc_client_command_reply_free(SilcClientCommandReplyContext cmd);
SILC_CLIENT_CMD_REPLY_FUNC(whois);
SILC_CLIENT_CMD_REPLY_FUNC(whowas);
SILC_CLIENT_CMD_REPLY_FUNC(identify);
SILC_CLIENT_CMD_REPLY_FUNC(nick);
SILC_CLIENT_CMD_REPLY_FUNC(list);
SILC_CLIENT_CMD_REPLY_FUNC(topic);
SILC_CLIENT_CMD_REPLY_FUNC(invite);
SILC_CLIENT_CMD_REPLY_FUNC(kill);
SILC_CLIENT_CMD_REPLY_FUNC(info);
SILC_CLIENT_CMD_REPLY_FUNC(stats);
SILC_CLIENT_CMD_REPLY_FUNC(ping);
SILC_CLIENT_CMD_REPLY_FUNC(oper);
SILC_CLIENT_CMD_REPLY_FUNC(join);
SILC_CLIENT_CMD_REPLY_FUNC(motd);
SILC_CLIENT_CMD_REPLY_FUNC(umode);
SILC_CLIENT_CMD_REPLY_FUNC(cmode);
SILC_CLIENT_CMD_REPLY_FUNC(cumode);
SILC_CLIENT_CMD_REPLY_FUNC(kick);
SILC_CLIENT_CMD_REPLY_FUNC(ban);
SILC_CLIENT_CMD_REPLY_FUNC(detach);
SILC_CLIENT_CMD_REPLY_FUNC(watch);
SILC_CLIENT_CMD_REPLY_FUNC(silcoper);
SILC_CLIENT_CMD_REPLY_FUNC(leave);
SILC_CLIENT_CMD_REPLY_FUNC(users);
SILC_CLIENT_CMD_REPLY_FUNC(getkey);
SILC_CLIENT_CMD_REPLY_FUNC(service);
SILC_CLIENT_CMD_REPLY_FUNC(quit);

/* Internal command reply functions */
SILC_CLIENT_CMD_REPLY_FUNC(whois_i);
SILC_CLIENT_CMD_REPLY_FUNC(identify_i);
SILC_CLIENT_CMD_REPLY_FUNC(info_i);
SILC_CLIENT_CMD_REPLY_FUNC(users_i);

SILC_CLIENT_CMD_REPLY_FUNC(connect);
SILC_CLIENT_CMD_REPLY_FUNC(close);
SILC_CLIENT_CMD_REPLY_FUNC(shutdown);

#endif
