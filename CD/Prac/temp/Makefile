YFLAGS=d
SRCS=y.tab.c lex.yy.c

all : Calc
run: Calc
	@echo "Lanching ..........!!!"
	@echo ""
	@./a.out

.c : $(SRCS)
	gcc $∗.c 
y.tab.c : y.y
	@yacc y.y -$(YFLAGS)

lex.yy.c : l.l
	@lex l.l

Calc : $(SRCS)
	@gcc y.tab.c lex.yy.c -lm
	@rm $(SRCS) *.h

