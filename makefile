#makefile

.SUFFIXES: 
.SUFFIXES: .o

vpath %.c src
vpath %.h include
vpath %.o obj

PROG = heysteimkeclient
CC = g++
LD = g++
LDFLAGS = 
#-Lmodules/libhttp -l/libhttp -lpthread -ldl
OBJPATH = obj
OBJS = 					\
	App.o 				\
	main.o				
OBJS_w_PATH = $(patsubst %,$(OBJPATH)/%,$(OBJS))
INCPATH = include
SRCPATH = src
BINPATH = bin
CPPFLAGS = -c -Wall -g -I$(INCPATH) 
#-Imodules/libhttp/include

bin/$(PROG): $(OBJS_w_PATH) $(BINPATH)
	$(LD) -o $(BINPATH)/$(PROG) $(OBJS_w_PATH) $(LDFLAGS)

obj/%.o: %.c $(OBJPATH)
	$(CC) $(CPPFLAGS) -o $@ $<

$(BINPATH):
	mkdir -p $(BINPATH)

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -f -r $(BINPATH)
cleanall: clean
	rm -f -r $(OBJPATH)

.PHONY: clean init build

	
