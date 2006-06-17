#
# The test.sh script takes two arguments:
#    * cc args to locate the libarchive header files.
#    * cc args to locate the libarchive library.
#
test:
	./test.sh "-I\"${.OBJDIR}\" -I\"${.CURDIR}\"" "-L\"${.OBJDIR}\""

clean:
	rm -f *.out
	rm -f *~
