static unsigned char archive[] = {
31,157,144,'0','n',4,132,'!',3,6,140,26,'8','n',228,16,19,195,160,'A',26,
'1',202,144,'q','h','p','F',25,28,20,'a','X',196,152,145,' ',141,25,2,'k',
192,160,'A',163,163,201,135,29,'c',136,'<',201,'2','c','A',147,'.',0,12,20,
248,178,165,205,155,20,27,226,220,201,243,166,152,147,'T',164,4,'I',194,164,
136,148,16,'H',1,'(',']',202,180,169,211,167,'P',163,'J',157,'J',181,170,
213,171,'X',179,'j',221,202,181,171,215,175,'L',1};

#include "test.h"

int main(int argc, char **argv)
{
	struct archive_entry *ae;
	struct archive *a;
/*	printf("Archive address: start=%X, end=%X\n", archive, archive+sizeof(archive)); */
	assert(a = archive_read_new());
	assertA(0 == archive_read_support_compression_all(a));
	assertA(0 == archive_read_support_format_all(a));
	assertA(0 == archive_read_open_memory(a, archive, sizeof(archive)));
	assertA(0 == archive_read_next_header(a, &ae));
	assertA(archive_compression(a) == ARCHIVE_COMPRESSION_COMPRESS);
	assertA(archive_format(a) == ARCHIVE_FORMAT_CPIO_SVR4_CRC);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


