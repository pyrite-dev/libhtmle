#include "libhtmle.h"

#include <stdlib.h>
#include <string.h>

libhtmle_t* libhtmle_create(void) {
	libhtmle_t* r = malloc(sizeof(*r));
	memset(r, 0, sizeof(*r));

	return r;
}

void libhtmle_destroy(libhtmle_t* engine) { free(engine); }
