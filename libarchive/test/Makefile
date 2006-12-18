# TODO: Integrate this with FreeBSD build system, so it can
# optionally be run as part of "buildworld".

test:
	# Compile utility.c; every test harness links against this.
	cc -c -g -o test.o test.c
	# Compile and run every test harness
	for p in test-*.c; do			\
		cc -Wall -g -o $$p.out $$p test.o -I\"${.OBJDIR}\" -I\"${.CURDIR}\" -L\"${.OBJDIR}\" -larchive -lz -lbz2;	\
		./$$p.out || echo Failed $$p;	\
	done

clean:
	rm -f *.out
	rm -f *.o
	rm -f *~
