YFLAGS=d
SRCS=lex.yy.c

all : prac3
run: prac3
	@echo "Launching PRAC3....!!!"
	@echo " "
	@echo "=================================="
	@echo "Input text: "
	@echo ""
	@cat text.txt
	@echo ""
	@echo "=================================="
	@echo "Lines starting or ending with 'a':"
	@echo ""
	@./a.out < text.txt
	@echo ""
	@echo "=================================="

.c : $(SRCS)
	gcc $∗.c 

lex.yy.c : prac3.l
	@lex prac3.l

prac3 : $(SRCS)
	@gcc lex.yy.c prac3.c
	@rm $(SRCS)

