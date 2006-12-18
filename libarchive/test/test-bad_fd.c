#include "test.h"

/* Verify that attempting to open an invalid fd returns correct error. */
int main (int argc, char *argv[]) {
	struct archive *a;
	assert(a = archive_read_new());
	assertA(0 == archive_read_support_compression_all(a));
	assertA(ARCHIVE_FATAL == archive_read_open_fd(a, -1, 1024));
	assertA(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	return (0);
}
