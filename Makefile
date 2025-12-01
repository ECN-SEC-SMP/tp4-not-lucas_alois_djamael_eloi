SRCDIR := src
INCDIR := include
BUILDDIR := build
ASSETSDIR := assets

all: $(BUILDDIR)/main.out

# Build the final executable
$(BUILDDIR)/main.out: $(BUILDDIR)/main.o | $(BUILDDIR)
	g++ -o $@ $^

# Build main.o
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/point2d.hpp $(INCDIR)/polygone.hpp $(INCDIR)/parcelle.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Build parcelle.o
$(BUILDDIR)/parcelle.o: $(SRCDIR)/parcelle.cpp $(INCDIR)/parcelle.hpp $(INCDIR)/polygone.hpp $(INCDIR)/point2d.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/parcelle.cpp -o $(BUILDDIR)/parcelle.o

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR)