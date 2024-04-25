# Matrix C++ by stranger

CXX					:= g++
CXXFLAGS			:= -Wall -Wextra -Werror -pedantic -std=c++17 -O2

DIR_SRC				:= ./modules/
DIR_OBJ				:= ./objects/
DIR_LIB				:= ./libs/
DIR_TEST			:= ./tests/

SRC					:= $(wildcard $(DIR_SRC)%.cpp)
OBJ					:= $(patsubst %.cpp, %.o, $(nodir $(SRC)))

LIB					:= s21_matrix_oop.a

BIN_TEST			:= tests

ifeq ($(shell uname), Linux)
	SYSFLAGS		:= -pthread -lgtest -lstdc++ -lrt -lm

else
	SYSFLAGS		:= -lgtest -lstdc++

endif

.PHONY : all clean rebuild 

vpath %.cpp $(DIR_SRC)

all :

test : $(LIB)
	$(CXX) $(CXXFLAGS) $(LIB) $(DIR_TEST)%.cpp -o $(BIN_TEST) $(SYSFLAGS)
	./$(BIN_TEST)

$(LIB) : $(DIR_OBJ)
	ar src $(LIB) $(DIR_OBJ)%.o

$(DIR_OBJ) : $(OBJ)
	$(shell mkdir $(DIR_OBJ)) && $(shell mv -t $(DIR_OBJ) $(OBJ))

$(OBJ) : s21_matrix_oop.h

clean :