#include <strings.h>

#include "util.h"

IDENT(ffs, int (*)(int));
IDENT(strcasecmp, int (*)(const char *, const char *));
IDENT(strcasecmp_l, int (*)(const char *, const char *, locale_t));
IDENT(strncasecmp, int (*)(const char *, const char *, size_t));
IDENT(strncasecmp_l, int (*)(const char *, const char *, size_t, locale_t));

TYPE_SCALAR(locale_t);
TYPE_UINT(size_t);
