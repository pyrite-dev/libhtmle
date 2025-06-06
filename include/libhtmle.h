/**
 * @file libhtmle.h
 * @~english
 * @brief LibHTMLe itself
 */

#ifndef __LIBHTMLE_H__
#define __LIBHTMLE_H__

typedef struct libhtmle_state {
	char* buffer;
	int   exclusive;
	char  tagname[129];
} libhtmle_state_t;

typedef struct libhtmle_callback {
} libhtmle_callback_t;

typedef struct libhtmle {
	char*		    buffer;
	libhtmle_callback_t callback;
	libhtmle_state_t    state;
	libhtmle_state_t    old;
} libhtmle_t;

#define HTMLEDEF extern

/**
 * @~english
 * @brief Create an engine
 * @return Engine
 */
HTMLEDEF libhtmle_t* libhtmle_create(void);

/**
 * @~english
 * @brief Parse an HTML
 * @param engine Engine
 * @param data Data
 */
HTMLEDEF void libhtmle_parse(libhtmle_t* engine, char* data);

/**
 * @~english
 * @brief Destroy an engine
 * @param engine Engine
 */
HTMLEDEF void libhtmle_destroy(libhtmle_t* engine);

#ifdef LIBHTMLE_SOURCE
#include "libhtmle_internal.h"
#endif

#endif
