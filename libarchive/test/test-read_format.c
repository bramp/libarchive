#include <archive.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Test the compression/format detection.  Tries to open a bunch of
 * archives, reports any mismatches between the expected
 * compression/format and the compression/format actually reported by
 * the library.
 */
struct {
	const char *file;
	int compression;
	int format;
} test[] = {
	{ "test-read_format.tar", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_TAR_USTAR },
	{ "test-read_format.tz", ARCHIVE_COMPRESSION_COMPRESS, ARCHIVE_FORMAT_TAR_USTAR },
	{ "test-read_format.tbz", ARCHIVE_COMPRESSION_BZIP2, ARCHIVE_FORMAT_TAR_USTAR },
	{ "test-read_format.tgz", ARCHIVE_COMPRESSION_GZIP, ARCHIVE_FORMAT_TAR_USTAR },
	{ "test-read_format.gtar", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_TAR_GNUTAR },
	{ "test-read_format.cpio-bin", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_CPIO_BIN_LE },
	{ "test-read_format.cpio-bin.Z", ARCHIVE_COMPRESSION_COMPRESS, ARCHIVE_FORMAT_CPIO_BIN_LE },
	{ "test-read_format.cpio-bin.bz2", ARCHIVE_COMPRESSION_BZIP2, ARCHIVE_FORMAT_CPIO_BIN_LE },
	{ "test-read_format.cpio-bin.gz", ARCHIVE_COMPRESSION_GZIP, ARCHIVE_FORMAT_CPIO_BIN_LE },
	{ "test-read_format.cpio-odc", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_CPIO_POSIX },
	{ "test-read_format.cpio-svr4", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_CPIO_SVR4_NOCRC },
	{ "test-read_format.cpio-svr4c", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_CPIO_SVR4_CRC },
	{ "test-read_format.zip", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_ZIP },
	{ "test-read_format.pax", ARCHIVE_COMPRESSION_NONE, ARCHIVE_FORMAT_TAR_PAX_INTERCHANGE },
	{ "test-read_format.iso.gz", ARCHIVE_COMPRESSION_GZIP, ARCHIVE_FORMAT_ISO9660 },
	{ "test-read_format.isorr.bz2", ARCHIVE_COMPRESSION_BZIP2, ARCHIVE_FORMAT_ISO9660_ROCKRIDGE },
};

int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
		struct archive_entry *ae;
		struct archive *a;
		a = archive_read_new();
		if (!a) {
			fprintf(stderr, "archive_read_new() failed\n");
			exit(1);
		}
		if (archive_read_support_compression_all(a)) {
			fprintf(stderr, "archive_read_support_compression_all() failed\n");
			exit(1);
		}
		if (archive_read_support_format_all(a)) {
			fprintf(stderr, "archive_read_support_format_all() failed\n");
			exit(1);
		}
		/*
		 * 2 bytes is the minimum size of the first block for
		 * correct compression detection.  I should fix
		 * archive_read to support correct compression
		 * detection even with 1-byte blocks.
		 */
		if (archive_read_open_file(a, test[i].file, 2)) {
			fprintf(stderr, "archive_read_open_file(a, \"%s\", 2) failed\n", test[i].file);
			exit(1);
		}
		if (archive_read_next_header(a, &ae)) {
			fprintf(stderr, "%s: archive_read_next_header() failed\n", test[i].file);
			exit(1);
		}
		if (archive_compression(a) != test[i].compression) {
			fprintf(stderr, "%s: compression detection failed: saw %d (%s), expected %d\n", test[i].file, archive_compression(a), archive_compression_name(a), test[i].compression);
			exit(1);
		}
		if (archive_format(a) != test[i].format) {
			fprintf(stderr, "%s: format detection failed: saw 0x%x (%s), expected 0x%x\n", test[i].file, archive_format(a), archive_format_name(a), test[i].format);
			exit(1);
		}
		archive_read_close(a);
	}
	exit(0);
}


