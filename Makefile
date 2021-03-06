CXX        = g++
CXXFLAGS   = -Wall -Wextra -std=c++11
DEPFLAGS   = -MMD
LDFLAGS    = 
SRCS       = main.cpp client.cpp commande.cpp produit.cpp magasin.cpp iserializable.cpp objetserialized.cpp serializer.cpp objetmapped.cpp exceptionentreeincorrecte.cpp exceptionfichiersauvegarde.cpp exceptionserialization.cpp 
OBJS       = $(SRCS:.cpp=.o)
TARGET     = TP02
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)
