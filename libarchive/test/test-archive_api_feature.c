#include <archive.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (ARCHIVE_API_FEATURE != archive_api_feature())
		exit(1);
	exit(0);
}
