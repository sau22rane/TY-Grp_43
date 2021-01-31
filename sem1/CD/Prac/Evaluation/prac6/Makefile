YFLAGS=d
SRCS=lex.yy.c

all : prac6
run: prac6
	@echo "Launching prac6....!!!"
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

lex.yy.c : prac6.l
	@lex prac6.l

prac6 : $(SRCS)
	@gcc lex.yy.c prac6.c
	@rm $(SRCS)

