/**
 * @file libhtmle_internal.h
 * @~english
 * @brief LibHTMLe internal stuffs
 */

#ifndef __LIBHTMLE_INTERNAL_H__
#define __LIBHTMLE_INTERNAL_H__

#include <libhtmle.h>

enum LIBHTMLE_TOKEN {
	TOKEN_BAD = -1,
	TOKEN_SPACE,
};

/**
 * @~english
 * @brief Get token
 * @param engine Engine
 * @return Token
 */
HTMLEDEF int libhtmle_get_token(libhtmle_t* engine);

#endif
