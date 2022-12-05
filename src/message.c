/* SPDX-Licence-Identifier: MIT */
/*
 * message.c
 *
 * (C) Copyright 2022 Kara O'Dell
 *
 * Messaging stuff.
 */

#include "message.h"

message_t create_message(message_attr_t mattr)
{
	message_t message = malloc(sizeof(struct message));

	if ((mattr != NULL) && (mattr.init != NULL)) {
		if (mattr.init(message, mattr.frame)) {
			free(message);
			message = NULL;
		}
	} else {
		message->size = 0;
		message->data = NULL;
	}

	return message;
}

int destroy_message(message_t message, message_attr_t mattr)
{
	int status = 0;

	if ((mattr != NULL) && (mattr.free != NULL)) {
		status = mattr.free(message, mattr.frame);
	} else {
		free(message->data);
	}

	free(message);

	return status;
}

int send_message(message_attr_t mattr)
{
	message_t message;

	message = create_message(mattr);

	/* send message here */

	destroy_message(mattr);
}

