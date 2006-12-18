static unsigned char archive[] = {
'B','Z','h','9','1','A','Y','&','S','Y',237,7,140,'W',0,0,27,251,144,208,
128,0,' ','@',1,'o',128,0,0,224,'"',30,0,0,'@',0,8,' ',0,'T','2',26,163,'&',
129,160,211,212,18,'I',169,234,13,168,26,6,150,'1',155,134,'p',8,173,3,183,
'J','S',26,20,'2',222,'b',240,160,'a','>',205,'f',29,170,227,'[',179,139,
'\'','L','o',211,':',178,'0',162,134,'*','>','8',24,153,230,147,'R','?',23,
'r','E','8','P',144,237,7,140,'W'};

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
	assert(archive_format(a) == ARCHIVE_FORMAT_TAR_USTAR);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


