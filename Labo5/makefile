COMPILE = g++

Test5:	Test5.cpp Person.o Actor.o Employee.o Option.o OptionException.o Car.o PasswordException.o Exception.o Model.o
	$(COMPILE) Test5.cpp Person.o Actor.o Employee.o Option.o OptionException.o Car.o PasswordException.o Exception.o Model.o -o Test5

Person.o:	Person.cpp Person.h
	$(COMPILE) -c Person.cpp

Actor.o:	Actor.cpp Actor.h Person.h
	$(COMPILE) -c Actor.cpp

Employee.o:	Employee.cpp Employee.h Actor.h
	$(COMPILE) -c Employee.cpp

Option.o:	Option.cpp Option.h
	$(COMPILE) -c Option.cpp

OptionException.o: OptionException.cpp OptionException.h Exception.h
	$(COMPILE) -c OptionException.cpp

Car.o: Car.cpp Car.h Option.h OptionException.h Model.h
	$(COMPILE) -c Car.cpp

PasswordException.o: PasswordException.cpp PasswordException.h Exception.h
	$(COMPILE) -c PasswordException.cpp

Exception.o: Exception.cpp Exception.h
	$(COMPILE) -c Exception.cpp

Model.o: Model.cpp Model.h
	$(COMPILE) -c Model.cpp

clean:
	rm -f *.o Test5