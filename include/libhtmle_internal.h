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
 * @brief Exclusive
 */
enum LIBHTMLE_EXCLUSIVE {
	EX_NONE = 0,
	EX_SCRIPT,
	EX_STYLE
};

/**
 * @~english
 * @brief Parser buffer
 */
#define PBuffer engine->state.buffer

/**
 * @~english
 * @brief Parser exclusive
 */
#define PExclusive engine->state.exclusive

/**
 * @~english
 * @brief Parser tagname
 */
#define PTagName engine->state.tagname

/**
 * @~english
 * @brief Get token
 * @param engine Engine
 * @param token Consumed token
 * @return Token
 */
HTMLEDEF int libhtmle_get_token(libhtmle_t* engine, char** token);

/**
 * @~english
 * @brief Check if comp matches in target
 * @param target Target
 * @param comp String
 * @return Result
 */
HTMLEDEF int libhtmle_nocase(const char* target, const char* comp);

#endif
