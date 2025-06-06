#include "libhtmle.h"

#include <string.h>
#include <ctype.h>

int libhtmle_nocase(const char* target, const char* comp) {
	int i;
	for(i = 0; i < strlen(comp) && target[i] != 0; i++) {
		if(tolower(comp[i]) != tolower(target[i])) return 0;
	}
	return 1;
}
