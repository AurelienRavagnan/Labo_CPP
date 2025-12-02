Test4: Test4.cpp Person.o Actor.o Client.o Employee.o
	g++ Test4.cpp Person.o Actor.o Client.o Employee.o -o Test4

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Actor.o: Actor.cpp Actor.h Person.h
	g++ -c Actor.cpp

Client.o: Client.cpp Client.h Actor.h Person.h
	g++ -c Client.cpp

Employee.o: Employee.cpp Employee.h Actor.h Person.h
	g++ -c Employee.cpp

clean:
	rm -f Person.o Actor.o Client.o Employee.o Test4
