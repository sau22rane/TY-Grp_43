YFLAGS=d
SRCS=lex.yy.c

all : prac4
run: prac4
	@echo "Launching prac4....!!!"
	@echo " "
	@echo "=================================="
	@echo "Input text: "
	@echo ""
	@cat text.txt
	@echo ""
	@echo "=================================="
	@echo "Count of characters, words and lines:"
	@echo ""
	@./a.out < text.txt
	@echo ""
	@echo "=================================="

.c : $(SRCS)
	gcc $∗.c 

lex.yy.c : prac4.l
	@lex prac4.l

prac4 : $(SRCS)
	@gcc lex.yy.c prac4.c
	@rm $(SRCS)

