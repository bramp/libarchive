static unsigned char archive[] = {
31,139,8,0,236,'c',217,'D',0,3,'3','0','7','0','7','0','4','0','0',181,'0',
183,'L',2,210,6,6,'&',134,169,')',' ',218,192,'8',213,2,133,'6','0','0','2',
'1','6','7','0','5','0','N','6','@',5,'&',16,202,208,212,0,';','0',130,'1',
244,24,12,160,246,17,5,136,'U',135,14,146,'`',140,144,' ','G','O',31,215,
' ','E','E','E',134,'Q',128,21,0,0,'%',215,202,221,0,2,0,0};

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
	assert(archive_format(a) == ARCHIVE_FORMAT_CPIO_SVR4_NOCRC);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


