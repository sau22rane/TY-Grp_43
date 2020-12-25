YFLAGS=d
SRCS=y.tab.c lex.yy.c

all : prac8
run: prac8
	@echo "Lanching ..........!!!"
	@echo ""
	@./a.out

.c : $(SRCS)
	gcc $∗.c 
y.tab.c : prac8.y
	@yacc prac8.y -$(YFLAGS)

lex.yy.c : prac8.l
	@lex prac8.l

prac8 : $(SRCS)
	@gcc y.tab.c lex.yy.c -lm
	@rm $(SRCS) *.h

