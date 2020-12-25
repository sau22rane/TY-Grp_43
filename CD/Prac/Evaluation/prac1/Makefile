YFLAGS=d
SRCS=lex.yy.c

all : prac1
run: prac1
	@echo "Launching prac1....!!!"
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

lex.yy.c : prac1.l
	@lex prac1.l

prac1 : $(SRCS)
	@gcc lex.yy.c prac1.c
	@rm $(SRCS)

