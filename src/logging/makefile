LOGGINGDIR := logging


$(OBJDIR)/yap_config.o: $(LOGGINGDIR)/yap_config.cc
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/yap_logging.o: $(LOGGINGDIR)/yap_logging.cc $(LOGGINGDIR)/yap_logging.ini ../logs
	$(CC) $(CFLAGS) -c -o $@ $<

../logs: 
	mkdir ../logs



