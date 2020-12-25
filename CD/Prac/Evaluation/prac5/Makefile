YFLAGS=d
SRCS=lex.yy.c

all : prac5
run: prac5
	@echo "Launching prac5....!!!"
	@echo " "
	@echo "=================================="
	@echo "Input text: "
	@echo ""
	@cat text.txt
	@echo ""
	@echo "=================================="
	@echo "Convert all uppercase characters to lowercase except inside comments:"
	@echo ""
	@./a.out < text.txt
	@echo ""
	@echo "=================================="

.c : $(SRCS)
	gcc $∗.c 

lex.yy.c : prac5.l
	@lex prac5.l

prac5 : $(SRCS)
	@gcc lex.yy.c prac5.c
	@rm $(SRCS)

