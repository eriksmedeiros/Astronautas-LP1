PROG = bin/exe
CC = g++
CPPFLAGS = -Wall -pedantic
OBJDIR = obj
SRCDIR = src
OBJS = $(OBJDIR)/main.o $(OBJDIR)/comando.o $(OBJDIR)/voo.o $(OBJDIR)/astronauta.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR)/comando.o: $(SRCDIR)/comando.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR)/voo.o: $(SRCDIR)/voo.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR)/astronauta.o: $(SRCDIR)/astronauta.cpp | $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS) $(PROG)