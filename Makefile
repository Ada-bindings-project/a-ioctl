
-include Makefile.conf

all:compile test

compile:
	${MAKE} gen
	gprbuild -p
Makefile.conf:Makefile
	@echo "export PATH:=${PATH}" >$@
gen:
	mkdir -p bin
	gcc -o bin/generate-ioctl src/generate-ioctl.c
	./bin/generate-ioctl >src/ioctl.ads
	gprbuild -p -P ioctl.gpr
test:
	${MAKE} -C tests all
install:
	-@gprinstall --uninstall -P ioctl.gpr >/dev/null 2>&1
	gprinstall -p -P ioctl.gpr
clean:
	git clean . -xdf
