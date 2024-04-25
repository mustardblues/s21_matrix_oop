# Matrix C++ by stranger

CXX					:= g++
CXXFLAGS			:= -Wall -Wextra -Werror -pedantic -std=c++17

DIR_SRC				:= ./modules/
DIR_OBJ				:= ./objects/
DIR_LIB				:= ./libs/
DIR_TEST			:= ./tests/

SRC					:= $(wildcard $(DIR_SRC)*.cpp)
OBJ					:= $(patsubst %.cpp, %.o, $(notdir $(SRC)))

LIB					:= s21_matrix_oop.a

BIN_TEST			:= GTest

ifeq ($(shell uname), Linux)
	SYSFLAGS		:= -pthread -lgtest -lstdc++ -lrt -lm

else
	SYSFLAGS		:= -lgtest -lstdc++

endif

.PHONY : all clean rebuild 

vpath %.cpp $(DIR_SRC)

all : 

test : $(LIB)
	$(CXX) $(CXXFLAGS) $(DIR_TEST)*.cpp $(DIR_LIB)$(LIB) -o $(BIN_TEST) $(SYSFLAGS)
	./$(BIN_TEST)

$(LIB) : $(DIR_OBJ)
	mkdir $(DIR_LIB) && ar src $(DIR_LIB)$(LIB) $(DIR_OBJ)*.o

$(DIR_OBJ) : $(OBJ)
	mkdir $(DIR_OBJ) && mv -t $(DIR_OBJ) $(OBJ)

$(OBJ) : s21_matrix_oop.h

clean :
	- rm -rf $(DIR_OBJ)
	- rm -rf $(DIR_LIB)
	- rm GTest

rebuld :
	make clean
	make all