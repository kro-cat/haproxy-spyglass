/* SPDX-Licence-Identifier: MIT */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <string.h>

typedef struct message_attr {
	int (*init)(message_t, void *);
	int (*free)(message_t, void *);
	void *frame;
} message_attr_t;

typedef struct message {
	size_t size;
	char *data;
} *message_t;

message_t create_message(message_attr_t mattr);
int destroy_message(message_t message, message_attr_t mattr);
int send_message(message_attr_t mattr);

#endif
