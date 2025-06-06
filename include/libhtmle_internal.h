/**
 * @file libhtmle_internal.h
 * @~english
 * @brief LibHTMLe internal stuffs
 */

#ifndef __LIBHTMLE_INTERNAL_H__
#define __LIBHTMLE_INTERNAL_H__

#include <libhtmle.h>

/**
 * @~english
 * @brief Token
 */
enum LIBHTMLE_TOKEN {
	TOKEN_BAD = -1,
	TOKEN_EOF,
	TOKEN_TAG,
	TOKEN_TEXT
};

/**
 * @~english
 * @brief Parser buffer
 */
#define PBuffer engine->state.buffer

/**
 * @~english
 * @brief Get token
 * @param engine Engine
 * @param token Consumed token
 * @return Token
 */
HTMLEDEF int libhtmle_get_token(libhtmle_t* engine, char** token);

#endif
