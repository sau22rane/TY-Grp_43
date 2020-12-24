YFLAGS=d
SRCS=y.tab.c lex.yy.c

src=$(shell find ./ -name "*.c")

all : converter_python
run: converter_python
	@echo "Lanching ..........!!!"
	@echo ""
	@./a.out

.c : $(SRCS)
	gcc $∗.c 
y.tab.c : converter_python.y
	@yacc converter_python.y -$(YFLAGS) -v

lex.yy.c : converter_python.l
	@lex converter_python.l

converter_python : $(SRCS)
	@gcc $(src)
	@rm $(SRCS) 
