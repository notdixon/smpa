CC = g++
CFLAGS =
LIBS =
INCLUDE =

SRCDIRS = src
CLEANDIRS = $(addsuffix clean, $(SRCDIRS))
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
EXEC_NAME = smpa
EXEC = src/$(EXEC_NAME)

.PHONY: all
all: $(EXEC)
clean: $(CLEANDIRS)

src/config.hpp:
	@echo " CP      $@"
	@cp src/config.def.hpp $@

$(EXEC): src/config.hpp $(OBJECTS)
	@echo " LD      $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJECTS): src/%.o : src/%.cpp
	@echo " CC      $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(LIBS)

%clean :%
	@$(MAKE) -C $< -f $(PWD)/Makefile clean_dir

clean_dir:
	@rm -vf *.o *~ $(EXEC_NAME) config.hpp

install: $(EXEC)
	@echo " IN      /usr/local/bin/$(EXEC_NAME)"
	@cp $(EXEC) /usr/local/bin/$(EXEC_NAME)
	@echo " IN      /usr/local/share/man/smpa.1"
	@cp docs/smpa.1 /usr/local/share/man/smpa.1

uninstall:
	@echo " RM      /usr/local/bin/$(EXEC_NAME)"
	@rm -f /usr/local/bin/$(EXEC_NAME)
	@echo " RM      /usr/local/share/man/smpa.1"
	@rm -f /usr/local/share/man/smpa.1
