.PHONY: clean 
HTTPSPROXY = ../obj/yap
PRODUCTS = $(HTTPSPROXY)
default: $(PRODUCTS)

OBJDIR = ../obj


include utils/makefile
include logging/makefile

include unittest/makefile
include unittest/utils/makefile
include unittest/logging/makefile

# OBJS can deal with either .cc or .c 
OBJS += $(OBJDIR)/yap_stringutil.o
OBJS += $(OBJDIR)/yap_config.o $(OBJDIR)/yap_logging.o 
OBJS += $(OBJDIR)/yap_main.o

JUNK = *~ $(OBJDIR)/*.o $(OBJDIR)/*.a  

# Define the tools we are going to use
CC= g++
LD = g++

CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -std=c++11 -I.

LIBS = -lm -lc -lpthread

$(OBJDIR)/yap_main.o: yap_main.cc
	$(CC) $(CFLAGS) -c -o $@ $<

$(PRODUCTS): $(OBJS)     
	$(LD) -o $@  $^  $(LIBS)
	cp $(PRODUCTS) ./



#unittest,using googletest:https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
#this make no sense, and just test googletest

ut-utils-stringutil: $(OBJDIR)/yap_stringutil_ut
	./$(OBJDIR)/yap_stringutil_ut

ut-logging-logging: $(OBJDIR)/yap_logging_ut 
	./$(OBJDIR)/yap_logging_ut  

ut-logging-config: $(OBJDIR)/yap_config_ut
	./$(OBJDIR)/yap_config_ut

clean:
	@rm -f $(JUNK) $(PRODUCTS) ./yap


