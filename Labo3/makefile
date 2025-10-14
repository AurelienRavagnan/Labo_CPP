Test3:	Test3.cpp Car.o Model.o Option.o
	g++ Test3.cpp Car.o Model.o Option.o -o Test3

Car.o:	Car.cpp Car.h Model.h Option.h
	g++ -c Car.cpp

Model.o:	Model.cpp Model.h
	g++ -c Model.cpp

Option.o:	Option.cpp Option.h
	g++ -c Option.cpp

clean:
	rm -f Car.o Model.o Option.o Test3