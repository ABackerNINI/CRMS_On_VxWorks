cc=g++
cflags='-std=gnu++0x'
root_dir=$(shell cd)
obj_dir=debug\obj
bin_dir=debug

export cc cflags root_dir obj_dir bin_dir

all:pre.o utility.o cur.o debug.o

pre.o:
	if not exist $(obj_dir) (md $(obj_dir))
	if not exist $(bin_dir) (md $(bin_dir))

utility.o:
	cd utility && $(MAKE)

cur.o:
	$(cc) $(cflags) -c main.cpp -o $(root_dir)\$(obj_dir)\cur.o

debug.o:
	cd debug && $(MAKE)

clean:
	rd  /S/Q $(root_dir)\$(obj_dir)
	del $(root_dir)\$(bin_dir)\*.exe

