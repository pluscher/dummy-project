# simple Hello World makefile

hello: show-message.c greeting.txt
	gcc -o $@ $<

