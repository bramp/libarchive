#include <archive.h>
#include <stdio.h>

/*
 * Test correct error handling for an invalid fd.
 */
int main (int argc, char *argv[]) {
	int e;
	struct archive *a = archive_read_new();
	archive_read_support_compression_all(a);
	e = archive_read_open_fd(a, -1, 1024);
	if (e != ARCHIVE_FATAL) {
		fprintf(stderr, "attempt to open fd= -1 returned error %d, expected %d\n", e, ARCHIVE_FATAL);
		return (1);
	}
	archive_read_finish(a);
	return (0);
}
