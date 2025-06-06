#include "libhtmle.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int libhtmle_get_token(libhtmle_t* engine, char** token) {
	int   r	  = TOKEN_BAD;
	char* old = PBuffer;
	int   eat = 0;
	memcpy(&engine->old, &engine->state, sizeof(engine->state));

	if(strlen(PBuffer) == 0) {
		r = TOKEN_EOF;
	} else {
		if(PBuffer[0] == '<') {
			int bad = 0;

			if(bad) { /* HACK: bad, workaround */
				r = TOKEN_TEXT;
			} else {
				PBuffer = old;

				r = TOKEN_TAG;
				for(; (*PBuffer) != 0 && (*PBuffer) != '>'; PBuffer++);
				eat = (*PBuffer) == '>' ? 1 : 0;
			}
		} else {
			r = TOKEN_TEXT;
			for(; (*PBuffer) != 0 && (*PBuffer) != '<'; PBuffer++);
			eat = (*PBuffer) == '<' ? 1 : 0;
			if(eat != 0) PBuffer -= 1;
		}
	}

	if(r == TOKEN_BAD || r == TOKEN_EOF) {
		*token = NULL;
	} else {
		*token = malloc(PBuffer - old + 1 + 1);
		memcpy(*token, old, PBuffer - old + 1);
		(*token)[PBuffer - old + 1] = 0;
	}

	PBuffer += eat;

	return r;
}

void libhtmle_parse(libhtmle_t* engine, char* data) {
	int   token;
	char* buf;

	if(engine->buffer != NULL) free(engine->buffer);
	engine->buffer = malloc(strlen(data) + 1);
	strcpy(engine->buffer, data);

	memset(&engine->old, 0, sizeof(engine->old));
	memset(&engine->state, 0, sizeof(engine->state));

	engine->state.buffer = engine->buffer;

	while((token = libhtmle_get_token(engine, &buf)) != TOKEN_EOF && token != TOKEN_BAD) {
		printf("%d %s\n", token, buf);
		free(buf);
	}
}
