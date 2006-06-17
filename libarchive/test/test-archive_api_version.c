#include <archive.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (ARCHIVE_API_VERSION != archive_api_version())
		exit(1);
	exit(0);
}
