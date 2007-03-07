#!/usr/bin/perl

# Testing the 'read' interface is easy: Just build a copy of the test
# archive into a simple C shell that uses archive_read_open_memory(),
# then walk through a sequence of archive operations, using assert()
# liberally to verify the proper result of each call.  This simple
# Perl script reads an archive on stdin and spits out a template C
# program to get you started.

print "static unsigned char archive[] = {\n";
$separator="";
$line = "";
while (sysread(STDIN, $b, 1) == 1) {
    $line .= $separator;
    if (length($line) > 72) {
	print $line,"\n";
	$line="";
    }
    $n = ord($b);
    if ($b eq '\\') {
	$line .= "'\\\\'";
    } elsif ($b eq '\'') {
	$line .= "'\\''";
    } elsif ($n < 32) {
	$line .= $n;
    } elsif ($n < 127) {
	$line .= "'$b'";
    } else {
	$line .= $n;
    }
    $separator = ",";
}
print "$line};\n";

exit(1);

print <<EOF
#include "test.h"

/* Skeleton test program:  Open the archive and read the first header. */
/* Customize this for the particular feature(s) you need to test. */
int main(int argc, char **argv)
{
	struct archive_entry *ae;
	struct archive *a;
	assert(a = archive_read_new());
	/* assertA() looks for a variable called 'a' and uses
	 * it to emit additional error information if the assert fails. */
	assertA(0 == archive_read_support_compression_all(a));
	assertA(0 == archive_read_support_format_all(a));
	assertA(0 == archive_read_open_memory(a, archive, sizeof(archive)));
	assertA(0 == archive_read_next_header(a, &ae));
	assert(0 == archive_read_close(a));
	exit(0);
}
EOF
