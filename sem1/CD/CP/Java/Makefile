YFLAGS=d
SRCS=y.tab.c lex.yy.c

src=$(shell find ./ -name "*.c")

all : converter_java
run: converter_java
	@echo "Lanching ..........!!!"
	@echo ""
	@./a.out

.c : $(SRCS)
	gcc $∗.c 
y.tab.c : converter_java.y
	@yacc converter_java.y -$(YFLAGS) -v

lex.yy.c : converter_java.l
	@lex converter_java.l

converter_java : $(SRCS)
	@gcc $(src)
