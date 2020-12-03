YFLAGS=d
SRCS=y.tab.c lex.yy.c

all : Calc
run: Calc
	@echo "Lanching Calculator..........!!!"
	@echo ""
	@./Calculator

.c : $(SRCS)
	gcc $∗.c 
y.tab.c : Calc.y
	@yacc Calc.y -$(YFLAGS)

lex.yy.c : Calc.l
	@lex Calc.l

Calc : $(SRCS)
	@gcc y.tab.c -o Calculator
	@rm $(SRCS) *.h

