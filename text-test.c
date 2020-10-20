#include <string.h>
#include <stdio.h>
#include <tis_builtin.h>
#include "tap.h"
#include "text.h"

int main(int argc, char *argv[]) {

	Text *txt = text_load(NULL);
	if (!txt)
		return 1;

	const char *data = "Hello World";
	size_t len = strlen(data);
	if (!text_insert(txt, 0, data, len))
		return 1;

	puts("Loaded");

	size_t pos = tis_interval(0, len);
	if (!text_insert(txt, pos, "|", 1))
		return 1;

	puts("Inserted");

	pos = tis_interval(0, len);

	if (!text_delete(txt, pos, 1))
		return 1;

	puts("Deleted");

	text_free(txt);

	return 0;
}
