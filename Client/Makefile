CC					= g++
LINK					= g++

CC_FLAGS				= -c -g -Wall
LINK_FLAGS				= -g
LIB_FLAGS				= 

TARGET					= client.exe
CLEARTARGET				= traceclear.exe

LIBTARGET				= libtraceclient.a
LIBINSTALLDIR				= d:/usr/local

LIBS					= -lwsock32

CLEARTARGETOBJS				= $(sort				\
					    traceclear.o                        \
					    trace.o                             \
					   )

OBJS					= $(sort				\
					    main.o                              \
					    trace.o                             \
					   )

LIBTARGETOBJS				= $(sort				\
					    trace.o				\
					   )

TARGETS					= $(TARGET) $(CLEARTARGET) $(LIBTARGET)

%.o					: %.cpp
					  @echo [C+] $@
					  @$(CC) $(CC_FLAGS) $<


.PHONY					: all
all					: $(TARGETS)

$(CLEARTARGET)				: $(CLEARTARGETOBJS)
					  @echo [LD] $@
					  @$(LINK) $(LINK_FLAGS) $(LIB_FLAGS) -o $(CLEARTARGET) $(CLEARTARGETOBJS) $(LIBS)

$(TARGET)				: $(OBJS)
					  @echo [LD] $@
					  @$(LINK) $(LINK_FLAGS) $(LIB_FLAGS) -o $(TARGET) $(OBJS) $(LIBS)

$(LIBTARGET)				: $(LIBTARGETOBJS)
					  ar ru $(LIBTARGET) $(LIBTARGETOBJS)

include					  depends.mk

.PHONY					: junkclean
junkclean				:
					  rm -rf $(wildcard *~ *.bak)

.PHONY					: clean
clean					: junkclean
					  rm -rf $(wildcard $(TARGET) $(OBJS))

.PHONY					: install
install					: $(LIBTARGET)
					  cp $(LIBTARGET) $(LIBINSTALLDIR)/lib
					  cp trace_winnet.h $(LIBINSTALLDIR)/include
					  cp trace_winnetqt.h $(LIBINSTALLDIR)/include
