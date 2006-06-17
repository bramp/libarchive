#include <archive.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (strcmp(ARCHIVE_LIBRARY_VERSION, archive_version()) != 0)
		exit(1);
	exit(0);
}
