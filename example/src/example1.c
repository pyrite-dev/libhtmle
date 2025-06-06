#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libhtmle.h"

int main(int argc, char** argv) {
	libhtmle_t* html;
	FILE*	    f = fopen(argc > 1 ? argv[1] : "index.html", "r");
	char*	    d;
	int	    sz;

	if(f == NULL) {
		return 1;
	}

	html = libhtmle_create();

	fseek(f, 0, SEEK_END);
	sz = ftell(f);
	fseek(f, 0, SEEK_SET);

	d = malloc(sz + 1);
	fread(d, sz, 1, f);
	d[sz] = 0;

	fclose(f);
	libhtmle_parse(html, d);
	libhtmle_destroy(html);

	free(d);
}
