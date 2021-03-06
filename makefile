cc=g++
cflags=-std=gnu++0x -g -pthread
root_dir=$(shell pwd)
obj_dir=debug/obj
bin_dir=debug

export cc cflags root_dir obj_dir bin_dir

all:pre.o nJson.o main.o out.o
	$(bin_dir)/out.exe

pre.o:
	test -d $(bin_dir) || mkdir -p $(bin_dir)
	test -d $(obj_dir) || mkdir -p $(obj_dir)

###############################################
##utilities

nJson.o:
	cd utility/nJson && $(MAKE)

mongoose.o:
	cd utility/HttpUtil && $(MAKE)

###############################################
##launcher

mongoose.o:
	cd protocol && $(MAKE)

launcher:pre.o nJson.o mongoose.o
	$(cc) $(cflags) -o $(bin_dir)/launcher launch/launcher.cpp $(obj_dir)/nJson.o
	$(bin_dir)/launcher.exe

###############################################

main.o:
	$(cc) $(cflags) -c main.cpp -o $(obj_dir)/main.o

out.o: $(obj_dir)/main.o $(obj_dir)/nJson.o
	$(cc) $(cflags) -o $(bin_dir)/out $^

###############################################
##tests

test_enum:pre.o nJson.o
	$(cc) $(cflags) -o $(bin_dir)/test_enum test/test_serialization/test_enumeration.cpp $(obj_dir)/nJson.o
	$(bin_dir)/test_enum.exe

test_req:pre.o nJson.o
	$(cc) $(cflags) -o $(bin_dir)/test_req test/test_serialization/test_req.cpp $(obj_dir)/nJson.o
	$(bin_dir)/test_req.exe

test_rsp:pre.o nJson.o
	$(cc) $(cflags) -o $(bin_dir)/test_rsp test/test_serialization/test_rsp.cpp $(obj_dir)/nJson.o
	$(bin_dir)/test_rsp.exe

###############################################
##clean

clean:
	rm -rf $(root_dir)/$(obj_dir)
	rm -f  $(root_dir)/$(bin_dir)/*.exe
