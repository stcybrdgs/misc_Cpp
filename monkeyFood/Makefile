monkeyFood: monkey_implement.o monkey_main.o  
	g++ monkey_implement.o monkey_main.o -o monkeyFood
	
monkey_implement.o: monkey_implement.cpp monkey_head.h
	g++ -Wall -ansi -pedantic -c monkey_implement.cpp
	
monkey_main.o: monkey_main.cpp monkey_implement.cpp monkey_head.h
	g++ -Wall -ansi -pedantic -c monkey_main.cpp

clean: 
	@rm -rf monkey_implement.o monkey_main.o

cleanall:
	@rm -rf monkey_implement.o monkey_main.o monkeyFood
