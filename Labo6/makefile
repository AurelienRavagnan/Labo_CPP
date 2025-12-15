COMPILE = g++

Test6:	Test6.cpp Person.o Actor.o Employee.o Option.o OptionException.o Car.o PasswordException.o Exception.o Client.o Model.o
	$(COMPILE) Test6.cpp Person.o Actor.o Employee.o Option.o OptionException.o Car.o PasswordException.o Exception.o Client.o Model.o -o Test6

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

Client.o:	Client.cpp Client.h Actor.h
	$(COMPILE) -c Client.cpp
 
Model.o: Model.cpp Model.h
	$(COMPILE) -c Model.cpp

clean:
	rm -f *.o Test6