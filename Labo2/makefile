All:	Test2a Test2b Test2c

Test2a:	Test2a.cpp Car.o Model.o Option.o
	g++ Test2a.cpp Car.o Model.o Option.o -o Test2a

Test2b:	Test2b.cpp Option.o
	g++ Test2b.cpp Option.o -o Test2b

Test2c:	Test2c.cpp Option.o Car.o Model.o
	g++ Test2c.cpp Option.o Car.o Model.o -o Test2c

Car.o:	Car.cpp Car.h Model.h Option.h
	g++ -c Car.cpp

Model.o:	Model.cpp Model.h
	g++ -c Model.cpp

Option.o:	Option.cpp Option.h
	g++ -c Option.cpp

clean:	
	rm -f Car.o Model.o Option.o Test2a Test2b Test2c