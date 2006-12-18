static unsigned char archive[] = {
'P','K',3,4,10,0,0,0,0,0,162,186,'g','3',0,0,0,0,0,0,0,0,0,0,0,0,1,0,21,0,
'a','U','T',9,0,3,224,'Q','p','C',224,'Q','p','C','U','x',4,0,232,3,232,3,
'P','K',1,2,23,3,10,0,0,0,0,0,162,186,'g','3',0,0,0,0,0,0,0,0,0,0,0,0,1,0,
13,0,0,0,0,0,0,0,0,0,164,129,0,0,0,0,'a','U','T',5,0,3,224,'Q','p','C','U',
'x',0,0,'P','K',5,6,0,0,0,0,1,0,1,0,'<',0,0,0,'4',0,0,0,0,0};

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
	assertA(archive_compression(a) == ARCHIVE_COMPRESSION_NONE);
	assertA(archive_format(a) == ARCHIVE_FORMAT_ZIP);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


