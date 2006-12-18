static unsigned char archive[] = {
'B','Z','h','9','1','A','Y','&','S','Y',134,'J',208,'4',0,0,30,246,141,253,
8,2,0,' ',1,'*','&',20,0,'`',' ',' ',2,0,128,0,'B',4,8,' ',0,'T','P',0,'4',
0,13,6,137,168,245,27,'Q',160,'a',25,169,5,'I',187,'(',10,'d','E',177,177,
142,218,232,'r',130,'4','D',247,'<','Z',190,'U',237,236,'d',227,31,' ','z',
192,'E','_',23,'r','E','8','P',144,134,'J',208,'4'};

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
	assert(archive_compression(a) == ARCHIVE_COMPRESSION_BZIP2);
	assert(archive_format(a) == ARCHIVE_FORMAT_CPIO_BIN_LE);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


