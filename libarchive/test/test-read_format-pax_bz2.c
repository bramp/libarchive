static unsigned char archive[] = {
'B','Z','h','9','1','A','Y','&','S','Y',152,180,30,185,0,0,140,127,176,212,
144,0,' ','@',1,255,226,8,'d','H',' ',238,'/',159,'@',0,16,4,'@',0,8,'0',
0,216,'A',164,167,147,'Q',147,'!',180,'#',0,'L',153,162,'i',181,'?','P',192,
26,'h','h',209,136,200,6,128,13,12,18,132,202,'5','O',209,'5','=',26,'2',
154,7,168,12,2,'d',252,13,254,29,'4',247,181,'l','T','i',130,5,195,1,'2',
'@',146,18,251,245,'c','J',130,224,172,'$','l','4',235,170,186,'c','1',255,
179,'K',188,136,18,208,152,192,149,153,10,'{','|','0','8',166,3,6,9,128,172,
'(',164,220,244,149,6,' ',243,212,'B',25,17,'6',237,13,'I',152,'L',129,209,
'G','J','<',137,'Y',16,'b',21,18,'a','Y','l','t','r',160,128,147,'l','f',
'~',219,206,'=','?','S',233,'3',251,'L','~',17,176,169,'%',23,'_',225,'M',
'C','u','k',218,8,'q',216,'(',22,235,'K',131,136,146,136,147,202,0,158,134,
'F',23,160,184,'s','0','a',246,'*','P',7,2,238,'H',167,10,18,19,22,131,215,
' '};

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
	assert(archive_format(a) == ARCHIVE_FORMAT_TAR_PAX_INTERCHANGE);
	assert(0 == archive_read_close(a));
#if ARCHIVE_API_VERSION > 1
	assert(0 == archive_read_finish(a));
#else
	archive_read_finish(a);
#endif
	exit(0);
}


