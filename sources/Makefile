# Matrix C++ by stranger

# -----------------------------------------------------------------------------------------Macros #

CXX					:= g++
CXXFLAGS			:= -Wall -Wextra -Werror -pedantic -std=c++17

DIR_SRC				:= ./modules/
DIR_OBJ				:= ./objects/
DIR_LIB				:= ./libs/
DIR_HDR				:= ./headers/
DIR_TEST			:= ./tests/unit_tests/

SRC					:= $(wildcard $(DIR_SRC)*.cpp)
OBJ					:= $(patsubst %.cpp, %.o, $(notdir $(SRC)))

LIB					:= s21_matrix_oop.a

BIN_TEST			:= GTest

ifeq ($(shell uname), Linux)
	SYSFLAGS		:= -pthread -lgtest -lstdc++ -lrt -lm --coverage

else
	SYSFLAGS		:= -lgtest -lstdc++ --coverage

endif

# --------------------------------------------------------------------------------------- Targets #

.PHONY : all clean rebuild 

vpath %.cpp $(DIR_SRC)

all : 

gcov_report : test
	lcov -t "s21_matrix_oop" -o s21_matrix_oop.info -c -d ./ --no-external 
	genhtml -o report s21_matrix_oop.info
	open report/index.html

test : $(LIB)
	$(CXX) $(CXXFLAGS) $(DIR_TEST)*.cpp $(DIR_LIB)$(LIB) -o $(BIN_TEST) $(SYSFLAGS)
	./$(BIN_TEST)

$(LIB) : $(DIR_OBJ)
	mkdir $(DIR_LIB) && ar src $(DIR_LIB)$(LIB) $(DIR_OBJ)*.o

$(DIR_OBJ) : $(OBJ)
	mkdir $(DIR_OBJ) && mv -t $(DIR_OBJ) $(OBJ)

$(OBJ) : s21_matrix_oop.h

# --------------------------------------------------------------------------------------- Linters #

style :
	clang-format -n --style=Google $(DIR_SRC)*.cpp $(DIR_HDR)*.h $(DIR_TEST)*.cpp s21_matrix_oop.h

cppcheck :
	

# ----------------------------------------------------------------------------- Abstracts Targets #

clean :
	@- rm -rf $(DIR_OBJ)
	@- rm -rf $(DIR_LIB)
	@- rm GTest

rebuld :
	make clean
	make all