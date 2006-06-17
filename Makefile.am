## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = foreign subdir-objects

EXTRA_DIST= version config.h.in			\
	minitar					\
	libarchive/test				\
	tar/test tar/getdate.c tar/getdate.h

# Clean out some unneeded files and directories
# that get picked up as part of the directories in EXTRA_DIST above.
dist-hook:
	rm -rf `find $(distdir) -name CVS -type d`
	rm -rf `find $(distdir) -name .svn -type d`
	rm -f `find $(distdir) -name '*~'`
	rm -f `find $(distdir) -name '*.out'`
	rm -f $(distdir)/*/Makefile

distclean-local:
	-rm -f tar/getdate.c tar/getdate.h
	-rm -rf autom4te.cache/
	-rm -f *~

lib_LTLIBRARIES=	libarchive.la
bin_PROGRAMS=	bsdtar
dist_man_MANS=$(libarchive_dist_man_MANS) $(bsdtar_dist_man_MANS)

#
# Libarchive headers, source, etc.
#
#

include_HEADERS= libarchive/archive_entry.h
# Note: archive.h is built from archive.h.in, so don't
# include archive.h in the distfile, but do install it.
nodist_include_HEADERS= libarchive/archive.h

libarchive_la_SOURCES=						\
	libarchive/archive_check_magic.c			\
	libarchive/archive_entry.c				\
	libarchive/archive_entry.h				\
	libarchive/archive_platform.h				\
	libarchive/archive_private.h				\
	libarchive/archive_read.c				\
	libarchive/archive_read_data_into_buffer.c		\
	libarchive/archive_read_data_into_fd.c			\
	libarchive/archive_read_extract.c			\
	libarchive/archive_read_open_fd.c			\
	libarchive/archive_read_open_file.c			\
	libarchive/archive_read_support_compression_all.c	\
	libarchive/archive_read_support_compression_bzip2.c	\
	libarchive/archive_read_support_compression_compress.c	\
	libarchive/archive_read_support_compression_gzip.c	\
	libarchive/archive_read_support_compression_none.c	\
	libarchive/archive_read_support_format_all.c		\
	libarchive/archive_read_support_format_cpio.c		\
	libarchive/archive_read_support_format_iso9660.c	\
	libarchive/archive_read_support_format_tar.c		\
	libarchive/archive_read_support_format_zip.c		\
	libarchive/archive_string.c				\
	libarchive/archive_string.h				\
	libarchive/archive_string_sprintf.c			\
	libarchive/archive_util.c				\
	libarchive/archive_write.c				\
	libarchive/archive_write_open_fd.c			\
	libarchive/archive_write_open_file.c			\
	libarchive/archive_write_set_compression_bzip2.c	\
	libarchive/archive_write_set_compression_gzip.c		\
	libarchive/archive_write_set_compression_none.c		\
	libarchive/archive_write_set_format.c			\
	libarchive/archive_write_set_format_by_name.c		\
	libarchive/archive_write_set_format_cpio.c		\
	libarchive/archive_write_set_format_pax.c		\
	libarchive/archive_write_set_format_shar.c		\
	libarchive/archive_write_set_format_ustar.c

libarchive_la_LIBADD=-lz -lbz2
# archive.h ends up in the build directory, so make sure we can find it.
libarchive_la_CPPFLAGS=-I$(top_builddir)/libarchive
libarchive_la_LDFLAGS= -version-info $(ARCHIVE_LIBTOOL_VERSION)

libarchive_dist_man_MANS=					\
	libarchive/archive_entry.3				\
	libarchive/archive_read.3				\
	libarchive/archive_util.3				\
	libarchive/archive_write.3				\
	libarchive/libarchive.3					\
	libarchive/libarchive-formats.5				\
	libarchive/tar.5

#
#
# bsdtar source, docs, etc.
#
#

bsdtar_SOURCES=				\
		tar/bsdtar.c		\
		tar/bsdtar.h		\
		tar/bsdtar_platform.h	\
		tar/getdate.y		\
		tar/matching.c		\
		tar/read.c		\
		tar/tree.c		\
		tar/tree.h		\
		tar/util.c		\
		tar/write.c

bsdtar_DEPENDENCIES = libarchive.la		\
		libarchive/archive_entry.h	\
		libarchive/archive.h

bsdtar_LDADD= -larchive -lbz2 -lz
bsdtar_CPPFLAGS=-I$(top_builddir)/libarchive
# Link libarchive statically...
bsdtar_LDFLAGS= -static -I$(destdir)/libarchive
bsdtar_dist_man_MANS=	tar/bsdtar.1
