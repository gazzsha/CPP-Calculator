CXX = g++
version = -std=c++17
TESTS = ./Testing/
SRC_MODEL_PATH = ./Model/
SRC_MODEL = $(wildcard $(SRC_MODEL_PATH)*.cc)
SRC_CONTROLLER_PATH = ./Controller/
SRC_CONTROLLER = $(wildcard $(SRC_CONTROLLER_PATH)*.cc)
SRC_TEST = $(wildcard $(TESTS)*cc)
TARGET = tests
REPORT = gcov_report
CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -g
SANITIZE = -fsanitize=address -g
UNAME := $(shell uname)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov 

ifeq ($(UNAME), Linux)
 TEST_FLAGS +=  -lgtest -pthread -lm
else
 TEST_FLAGS += -lgtest -lm
endif

all: uninstall clean $(TARGET) install dvi dist

$(TARGET) : $(SRC) $(SRC_TEST)
	$(CXX) $(version) $(CXXFLAGS) $(SRC_TEST) $(SRC_MODEL) $(SRC_CONTROLLER) $(TEST_FLAGS) -o $(TARGET)
	./$(TARGET)


install: clean
	rm -rf build QtWidgets.app
	mkdir build
	cd build && qmake ../View/QtWidgets.pro&&make&&mv QtWidgets.app ../QtWidgets.app
	cd build&&rm -rf *.*&&rm -rf Makefile&&rm -rf .qmake.stash
	rm -rf uninstall/QtWidgets.pro.user
	chmod 777 QtWidgets.app/
	open QtWidgets.app/

uninstall:
	rm -rf build
	rm -rf QtWidgets.app

dist: install
	tar --totals -cvf smart_calc.tar View Testing Model Controller


dvi:
	Doxygen Doxyfile
	open ./Documentation/html/index.html


$(REPORT) : $(SRC) $(SRC_TEST) build_file
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(SRC_TEST) $(SRC_MODEL) $(SRC_CONTROLLER) $(TEST_FLAGS) -o Build/$(REPORT)
	Build/./$(REPORT)
	lcov -o $(REPORT).info -c -d .
	lcov -r $(REPORT).info "/usr*" -o $(REPORT).info
	genhtml $(REPORT).info -o html_report
	open html_report/index.html

build_file:
	mkdir Build

style: 
	clang-format -i  ./Testing/*h ./Testing/*cc  ./Model/*h ./Model/*cc ./Controller/*h ./Controller/*cc
clean : 
	rm -rf Build $(TARGET) *.a  ./html_report/ gcov_report *.gcno *.gcda *.info *.out *.tar  build-QtWidgets-Desktop_x86_darwin_generic_mach_o_64bit-Debug QtWidgets.app
	rm -rf  *.html *.css test.info test.dSYM report
	rm -rf Documentation
	rm -rf $(SRC_MODEL_PATH)/*.out $(SRC_MODEL_PATH)/*.dSYM $(TESTS)/*.dSYM 
	rm -rf *.dSYM 
