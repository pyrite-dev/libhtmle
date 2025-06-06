#include "libhtmle.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int check_ex(libhtmle_t* engine) {
	int r = 1;
	if(PExclusive == EX_NONE) {
		return (*PBuffer) != '<';
	} else if(PExclusive == EX_SCRIPT) {
		r = libhtmle_nocase(PBuffer, "</script>");
	} else if(PExclusive == EX_STYLE) {
		r = libhtmle_nocase(PBuffer, "</style>");
	}
	return r == 0 ? 1 : 0;
}

int libhtmle_get_token(libhtmle_t* engine, char** token) {
	int   r	  = TOKEN_BAD;
	char* old = PBuffer;
	int   eat = 0;
	int   i;
	memcpy(&engine->old, &engine->state, sizeof(engine->state));

	if(strlen(PBuffer) == 0) {
		r = TOKEN_EOF;
	} else {
		if(PBuffer[0] == '<') {
			PBuffer = old;

			r = TOKEN_TAG;
			for(; (*PBuffer) != 0 && (*PBuffer) != '>'; PBuffer++);
			eat = (*PBuffer) == '>' ? 1 : 0;
		} else {
			r = TOKEN_TEXT;
			for(; (*PBuffer) != 0 && check_ex(engine); PBuffer++);
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

	memset(PTagName, 0, sizeof(PTagName));

	if(r == TOKEN_TAG) {
		for(i = 1; (*token)[i] != 0 && i < (sizeof(PTagName) - 1); i++) {
			char c = (*token)[i];
			if(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '>') {
				break;
			} else {
				PTagName[i - 1] = c;
			}
		}
		if(libhtmle_nocase(PTagName, "script")) {
			PExclusive = EX_SCRIPT;
		} else if(libhtmle_nocase(PTagName, "style")) {
			PExclusive = EX_STYLE;
		} else if(libhtmle_nocase(PTagName, "/script") || libhtmle_nocase(PTagName, "/style")) {
			PExclusive = EX_NONE;
		}
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

	PBuffer	   = engine->buffer;
	PExclusive = EX_NONE;

	while((token = libhtmle_get_token(engine, &buf)) != TOKEN_EOF && token != TOKEN_BAD) {
		if(token == TOKEN_TAG) printf("%s\n", PTagName);
		free(buf);
	}
}
