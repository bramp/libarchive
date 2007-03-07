#include "test.h"

/* Try to force archive_write_open_memory.c to write past the end of an array. */
static unsigned char buff[16384];
int main (int argc, char *argv[]) {
	int i;
	struct archive *a;
	struct archive_entry *ae;
	const char *name="/tmp/test";

	/* Create a simple archive_entry. */
	assert(ae = archive_entry_new());
	archive_entry_set_pathname(ae, name);
	archive_entry_set_mode(ae, S_IFREG);
	assert(0 == strcmp(archive_entry_pathname(ae), name));

	/* Try writing with different buffer sizes. */
	/* Make sure that we get failure on too-small buffers, success on
	 * large enough ones. */
	for (i = 100; i < 1600; i++) {
		size_t s;
		size_t blocksize = 94;
		assert(a = archive_write_new());
		assertA(0 == archive_write_set_format_ustar(a));
		assertA(0 == archive_write_set_bytes_in_last_block(a, 1));
		assertA(0 == archive_write_set_bytes_per_block(a, blocksize));
		buff[i] = 0xAE;
		assertA(0 == archive_write_open_memory(a, buff, i, &s));
		/* If buffer is smaller than a tar header, this should fail. */
		if (i < (511/blocksize)*blocksize)
			assertA(ARCHIVE_FATAL == archive_write_header(a,ae));
		else
			assertA(0 == archive_write_header(a, ae));
		/* If buffer is smaller than a tar header plus 1024 byte
		 * end-of-archive marker, then this should fail. */
		if (i < 1536)
			assertA(ARCHIVE_FATAL == archive_write_close(a));
		else
			assertA(0 == archive_write_close(a));
#if ARCHIVE_API_VERSION > 1
		assert(0 == archive_write_finish(a));
#else
		archive_write_finish(a);
#endif
		assert(buff[i] == 0xAE);
		assert(s <= i);
	}
	return (0);
}
