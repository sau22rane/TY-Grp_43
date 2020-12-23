YFLAGS=d
SRCS=y.tab.c lex.yy.c

src=$(shell find ./ -name "*.c")

all : c2java
run: c2java
	@echo "Lanching ..........!!!"
	@echo ""
	@./a.out

.c : $(SRCS)
	gcc $∗.c 
y.tab.c : c2java.y
	@yacc c2java.y -$(YFLAGS) -v

lex.yy.c : c2java.l
	@lex c2java.l

c2java : $(SRCS)
	@gcc $(src)
	@rm $(SRCS) 
