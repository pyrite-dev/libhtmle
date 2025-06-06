/**
 * @file libhtmle.h
 * @~english
 * @brief LibHTMLe itself
 */

#ifndef __LIBHTMLE_H__
#define __LIBHTMLE_H__

typedef struct libhtmle {
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
 * @brief Destroy an engine
 * @param engine Engine
 */
HTMLEDEF void libhtmle_destroy(libhtmle_t* engine);

#endif
