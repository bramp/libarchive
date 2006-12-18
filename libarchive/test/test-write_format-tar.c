#include "test.h"

char buff[1000000];
char buff2[64];

int main(int argc, char **argv)
{
	struct archive_entry *ae;
	struct archive *a;
	char *p;
	size_t used;
	int blocksize;

	/* Repeat the following for a variety of odd blocksizes. */
	for (blocksize = 1; blocksize < 100000; blocksize += blocksize + 3) {
		/* Create a new archive in memory. */
		assert(a = archive_write_new());
		assertA(0 == archive_write_set_format_ustar(a));
		assertA(0 == archive_write_set_compression_none(a));
		assertA(0 == archive_write_set_bytes_per_block(a, blocksize));
		assertA(0 == archive_write_set_bytes_in_last_block(a, blocksize));
		assertA(blocksize == archive_write_get_bytes_in_last_block(a));
		assertA(0 == archive_write_open_memory(a, buff, sizeof(buff), &used));
		assertA(blocksize == archive_write_get_bytes_in_last_block(a));

		/*
		 * Write a file to it.
		 */
		assert(ae = archive_entry_new());
		archive_entry_set_mtime(ae, 1, 10);
		assert(1 == archive_entry_mtime(ae));
		assert(10 == archive_entry_mtime_nsec(ae));
		p = strdup("file");
		archive_entry_copy_pathname(ae, p);
		strcpy(p, "XXXX");
		free(p);
		assert(0 == strcmp("file", archive_entry_pathname(ae)));
		archive_entry_set_mode(ae, S_IFREG | 0755);
		assert((S_IFREG | 0755) == archive_entry_mode(ae));
		archive_entry_set_size(ae, 8);

		assertA(0 == archive_write_header(a, ae));
		assertA(8 == archive_write_data(a, "12345678", 9));

		/* Close out the archive. */
		assertA(0 == archive_write_close(a));
#if ARCHIVE_API_VERSION > 1
		assertA(0 == archive_write_finish(a));
#else
		archive_write_finish(a);
#endif
		/* This calculation gives "the smallest multiple of
		 * the block size that is at least 2048 bytes". */
		assert(((2048 - 1)/blocksize+1)*blocksize == used);

		/*
		 * Now, read the data back.
		 */
		assert(a = archive_read_new());
		assertA(0 == archive_read_support_format_all(a));
		assertA(0 == archive_read_support_compression_all(a));
		assertA(0 == archive_read_open_memory(a, buff, used));

		assertA(0 == archive_read_next_header(a, &ae));

		assert(1 == archive_entry_mtime(ae));
		/* Not the same as above: ustar doesn't store hi-res timestamps. */
		assert(0 == archive_entry_mtime_nsec(ae));
		assert(0 == archive_entry_atime(ae));
		assert(0 == archive_entry_ctime(ae));
		assert(0 == strcmp("file", archive_entry_pathname(ae)));
		assert((S_IFREG | 0755) == archive_entry_mode(ae));
		assert(8 == archive_entry_size(ae));
		assertA(8 == archive_read_data(a, buff2, 10));
		assert(0 == memcmp(buff2, "12345678", 8));

		/* Verify the end of the archive. */
		assert(1 == archive_read_next_header(a, &ae));
		assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
		assert(0 == archive_read_finish(a));
#else
		archive_read_finish(a);
#endif
	}
	return (0);
}
