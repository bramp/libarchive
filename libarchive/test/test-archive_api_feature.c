#include "test.h"

int main(int argc, char **argv)
{
	assert(ARCHIVE_API_FEATURE == archive_api_feature());
	assert(ARCHIVE_API_VERSION == archive_api_version());
	assert(0 == (strcmp(ARCHIVE_LIBRARY_VERSION, archive_version())));
	exit(0);
}
