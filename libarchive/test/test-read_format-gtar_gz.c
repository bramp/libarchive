static unsigned char archive[] = {
31,139,8,0,'+','e',217,'D',0,3,211,211,'g',160,'9','0',0,2,'s','S','S',16,
'm','h','n','j',128,'L',195,0,131,161,129,177,177,137,129,137,185,185,161,
'!',131,129,161,129,153,161,'9',131,130,')',237,157,198,192,'P','Z','\\',
146,'X',164,160,192,'P',146,153,139,'W',29,'!','y',152,'G','`',244,'(',24,
5,163,'`',20,12,'r',0,0,226,234,'6',162,0,6,0,0};

#include "test.h"

int main(int argc, char **argv)
{
	struct archive_entry *ae;
	struct archive *a;
	assert(a = archive_read_new());
	assert(0 == archive_read_support_compression_all(a));
	assert(0 == archive_read_support_format_all(a));
	assert(0 == archive_read_open_memory(a, archive, sizeof(archive)));
	assert(0 == archive_read_next_header(a, &ae));
	assert(archive_compression(a) == ARCHIVE_COMPRESSION_GZIP);
	assert(archive_format(a) == ARCHIVE_FORMAT_TAR_GNUTAR);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


