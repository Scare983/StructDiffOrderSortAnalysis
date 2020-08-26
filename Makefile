OBJS		= Main.o Sorting.o
COMPILE		= g++ -g -c -std=gnu++0x -o $@

# the main target
main: $(OBJS)
	g++ -o $@ $(OBJS)
	
# dependencies
Main.o: Main.cpp
	$(COMPILE) Main.cpp
	
Sorting.o: Sorting.h Sorting.cpp
	$(COMPILE) Sorting.cpp
	
clean:
	$(RM) $(OBJS)
	
cleanall: clean
	$(RM) main
