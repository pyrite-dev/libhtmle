/**
 * @file libhtmle.h
 * @~english
 * @brief LibHTMLe itself
 */

#ifndef __LIBHTMLE_H__
#define __LIBHTMLE_H__

#define libhtmle_t struct libhtmle
#define libhtmle_state_t struct libhtmle_state
#define libhtmle_callback_t struct libhtmle_callback

struct libhtmle;
struct libhtmle_state;
struct libhtmle_callback;

struct libhtmle_state {
	char* buffer;
	int   exclusive;
	char  tagname[129];
};

/* Callbacks */

enum LIBHTMLE_CALLBACK_EVENT {
	/* Error */
	LIBHTMLE_ERROR_UNKNOWN, /* Unknown error occurred */
	LIBHTMLE_FATAL_UNKNOWN, /* Unknown fatal error occurred */
	/* Parsing */
	LIBHTMLE_PARSING_START,
	LIBHTMLE_PARSING_FINISHED,
	LIBHTMLE_PARSING_FAILED,
	/* Rendering */
	LIBHTMLE_RENDER_START,
	LIBHTMLE_RENDER_FINISHED,
	/* Interactive content */
	LIBHTMLE_CONTENT_LINK, /* param: const char* link followed */
	LIBHTMLE_CONTENT_FORM, /* param: const char* form data (a=b&c=d&...) */
};

struct libhtmle_callback {
	enum LIBHTMLE_CALLBACK_EVENT event;
	libhtmle_t*		     engine;
	void*			     param;
};

struct libhtmle {
	char*		    buffer;
	libhtmle_callback_t callback;
	libhtmle_state_t    state;
	libhtmle_state_t    old;
};

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
