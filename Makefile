.PHONY: part2
.PHONY: wallet

part2:
	gcc	-g	fib.c	-o	fib
	gcc	-g	trace.c	-o	trace
	gcc	-g	root.c	-o	solver -lm
	gcc	-g	main.c	-o	part2

wallet:
	gcc	-g	wallet_stat.c	-o	wallet
	gcc	-g	print_help.o	-o	print_help
