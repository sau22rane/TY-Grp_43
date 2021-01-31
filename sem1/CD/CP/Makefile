YFLAGS=d
SRCS=y.tab.c lex.yy.c

src1=$(shell find ./Java -name "*.c")
src2=$(shell find ./Python -name "*.c")

all : converter
run: converter
	@echo "Running Test cases"
	@echo ""
	@./Java/cvt_java conditional < ./Test_cases/C/conditional.c > ./Test_cases/Generated_Java/conditional.java
	@./Python/cvt_python < ./Test_cases/C/conditional.c > ./Test_cases/Generated_Python/conditional.py

	@./Java/cvt_java loops < ./Test_cases/C/loops.c > ./Test_cases/Generated_Java/loops.java
	@./Python/cvt_python < ./Test_cases/C/loops.c > ./Test_cases/Generated_Python/loops.py

	@./Java/cvt_java recursion < ./Test_cases/C/recursion.c > ./Test_cases/Generated_Java/recursion.java
	@./Python/cvt_python < ./Test_cases/C/recursion.c > ./Test_cases/Generated_Python/recursion.py

	@echo "Java and Python files generated for all the test cases"
	@echo "----------------------------------"


converter :
	@echo "----------------------------------"
	@yacc -o ./Java/y.tab.c ./Java/converter_java.y -$(YFLAGS) -v
	@lex -o ./Java/lex.yy.c ./Java/converter_java.l
	@gcc -o ./Java/cvt_java $(src1)
	@echo ""
	@echo "C to Java Converter Compiled"
	@echo "----------------------------------"

	@yacc -o ./Python/y.tab.c ./Python/converter_python.y -$(YFLAGS) -v
	@lex -o ./Python/lex.yy.c ./Python/converter_python.l
	@gcc -o ./Python/cvt_python $(src2)
	@echo ""
	@echo "C to Python Converter Compiled"
	@echo "----------------------------------"

ast: converter
	@echo "======================================================="
	@./Java/cvt_java p < ./Java/text.txt
	@echo "======================================================="