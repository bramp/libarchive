static unsigned char archive[] = {
31,157,144,'.',0,8,28,'H',176,160,193,131,8,19,'*','\\',200,176,'!','B',24,
16,'o',212,168,1,2,0,196,24,18,'a','T',188,152,'q','#',196,143,' ','5',198,
128,'1','c',6,13,24,'4','0',206,176,1,2,198,200,26,'6','b',0,0,'Q',195,161,
205,155,'8','s',234,4,'P','g',14,157,'0','r',',',194,160,147,166,205,206,
132,'D',141,30,'=',24,'R',163,'P',144,21,151,'J',157,'J',181,170,213,171,
'X',179,'j',221,202,181,171,215,175,'`',195,138,29,'K',182,172,217,179,'h',
211,170,']',203,182,173,219,183,'g',1};

#include "test.h"

int main(int argc, char **argv)
{
	struct archive_entry *ae;
	struct archive *a;
	assert(a = archive_read_new());
	assertA(0 == archive_read_support_compression_all(a));
	assertA(0 == archive_read_support_format_all(a));
	assertA(0 == archive_read_open_memory(a, archive, sizeof(archive)));
	assertA(0 == archive_read_next_header(a, &ae));
	assertA(archive_compression(a) == ARCHIVE_COMPRESSION_COMPRESS);
	assertA(archive_format(a) == ARCHIVE_FORMAT_TAR_USTAR);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


