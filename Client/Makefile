CC					= g++
LINK					= g++

CC_FLAGS				= -c -g -Wall
LINK_FLAGS				= -g
LIB_FLAGS				= 

TARGET					= client.exe
LIBS					= -lwsock32
OBJS					= $(sort				\
					    main.o                              \
					    trace.o                             \
					   )

%.o					: %.cpp
					  @echo [C+] $@
					  @$(CC) $(CC_FLAGS) $<


.PHONY					: all
all					: $(TARGET)

$(TARGET)				: $(OBJS)
					  @echo [LD] $@
					  @$(LINK) $(LINK_FLAGS) $(LIB_FLAGS) -o $(TARGET) $(OBJS) $(LIBS)

include					  depends.mk

.PHONY					: junkclean
junkclean				:
					  rm -rf $(wildcard *~ *.bak)

.PHONY					: clean
clean					: junkclean
					  rm -rf $(wildcard $(TARGET) $(OBJS))
