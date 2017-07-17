cc=g++
cflags='-std=gnu++0x'
root_dir=$(shell pwd)
obj_dir=debug/obj
bin_dir=debug

export cc cflags root_dir obj_dir bin_dir

all: nJson.o main.o out.o
	$(bin_dir)/out.exe

nJson.o:
	cd utility/nJson && $(MAKE)

main.o:
	$(cc) $(cflags) -c main.cpp -o $(obj_dir)/main.o

out.o: $(obj_dir)/main.o $(obj_dir)/parson.o
	$(cc) $(cflags) -o $(bin_dir)/out $^

clean:
	rd /S/Q $(root_dir)/$(obj_dir)
	del $(root_dir)/$(bin_dir)/*.exe

