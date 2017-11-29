VERSION=2.0.0
CFLAGS=-Wall -Werror
LFLAGS=-Wall
LIBNAME=mylib
LIBDIR=lib
LIBTARGETDIR=/remote/users/ycouillec/.local/lib
SRCDIR=src
OBJDIR=obj
INCDIR=include
INCTARGETDIR=/remote/users/ycouillec/.local/include
TESTDIR=test

build-lib:
	gcc -I$(INCDIR) -c -o $(OBJDIR)/$(LIBNAME).o $(CFLAGS) -fpic $(SRCDIR)/$(LIBNAME).c
	gcc -shared -o $(LIBDIR)/lib$(LIBNAME).$(VERSION).so $(OBJDIR)/$(LIBNAME).o
	rm -f $(LIBDIR)/lib$(LIBNAME).so
	cd $(LIBDIR) && ln -s lib$(LIBNAME).$(VERSION).so lib$(LIBNAME).so

install-lib:
	cp $(INCDIR)/$(LIBNAME).h $(INCTARGETDIR)
	cp $(LIBDIR)/lib$(LIBNAME).$(VERSION).so $(LIBTARGETDIR)
	rm -f $(LIBTARGETDIR)/lib$(LIBNAME).so
	cd $(LIBTARGETDIR) && ln -s lib$(LIBNAME).$(VERSION).so lib$(LIBNAME).so

uninstall-lib:
	rm -rf $(INCTARGETDIR)/$(LIBNAME).h
	rm -rf $(LIBTARGETDIR)/lib$(LIBNAME).*so

build-test:
	gcc -I$(INCDIR) -c -o $(TESTDIR)/test.o $(CFLAGS) $(TESTDIR)/test.c
	gcc -L$(LIBDIR) -o $(TESTDIR)/test.out $(LFLAGS) $(TESTDIR)/test.o -l$(LIBNAME)

run-test:
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(shell pwd)/$(LIBDIR) ; $(TESTDIR)/test.out

tar-release:
	cd .. && cp -R mylib mylib.$(VERSION) && tar czvf mylib.$(VERSION).tar.gz mylib.$(VERSION) && rm -rf mylib.$(VERSION)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf *~ *.so
