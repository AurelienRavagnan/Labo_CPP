CLASSES = ./Classes/
CXX = g++
CXXFLAGS = -Wall -I$(CLASSES)
TARGET = Test8a
SRCS = $(wildcard $(CLASSES)*.cpp) $(TARGET).cpp
OBJS = $(SRCS:.cpp=.o)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
run: $(TARGET)
	./$(TARGET)
