YFLAGS=d
SRCS=y.tab.c lex.yy.c

all : lang
.c : $(SRCS)
	gcc $∗.c 
y.tab.c : lang.y
	yacc lang.y -$(YFLAGS)

lex.yy.c : lang.l
	lex lang.l

lang : $(SRCS)
	gcc $(SRCS) -o langauge
	rm $(SRCS) *.h

