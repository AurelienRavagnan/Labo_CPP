CLASSES = ./Classes/
COMPILE = g++

SRCS = $(wildcard $(CLASSES)*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = Test7

$(TARGET): $(OBJS) Test7.cpp
	$(COMPILE) Test7.cpp $(OBJS) -o $(TARGET)

$(CLASSES)%.o: $(CLASSES)%.cpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(CLASSES)*.o $(TARGET)