CPP=g++ #-DDEBUG

Test3:	Test3.cpp Car.o Model.o Option.o
	$(CPP) Test3.cpp Car.o Model.o Option.o -o Test3

Car.o:	Car.cpp Car.h Model.h Option.h
	$(CPP) -c Car.cpp

Model.o:	Model.cpp Model.h
	$(CPP) -c Model.cpp

Option.o:	Option.cpp Option.h
	$(CPP) -c Option.cpp

clean:
	rm -f Car.o Model.o Option.o Test3