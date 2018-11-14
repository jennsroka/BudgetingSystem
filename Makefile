all: budget
	make doc
clean:
	-rm *.o
	-rm budget
	-rm -r html
	-rm -r latex
budget: main.o Budget.o account.o bank.o
	g++ -o budget main.o Budget.o
main.o: main.cc Budget.h
	g++ -c main.cc
Budget.o: Budget.cc Budget.h
	g++ -c Budget.cc
account.o: account.cc
	g++ -c account.cc
bank.o: bank.cc
	g++ -c bank.cc
doc:
	doxygen Doxyfile
