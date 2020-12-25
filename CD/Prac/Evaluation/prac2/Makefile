YFLAGS=d
SRCS=lex.yy.c

all : prac2
run: prac2
	@echo "Launching PRAC2....!!!"
	@echo " "
	@echo "=================================="
	@echo "Input text: "
	@echo ""
	@cat text.txt
	@echo ""
	@echo "=================================="
	@echo "Lines with line number:"
	@echo ""
	@./a.out < text.txt
	@echo ""

.c : $(SRCS)
	gcc $∗.c 

lex.yy.c : prac2.l
	@lex prac2.l

prac2 : $(SRCS)
	@gcc lex.yy.c prac2.c
	@rm $(SRCS)

