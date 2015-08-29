testScores: scores_implement.o scores_main.o  
	g++ scores_implement.o scores_main.o -o testScores
	
scores_implement.o: scores_implement.cpp scores_head.h
	g++ -Wall -ansi -pedantic -c scores_implement.cpp
	
scores_main.o: scores_main.cpp scores_implement.cpp scores_head.h
	g++ -Wall -ansi -pedantic -c scores_main.cpp

clean: 
	@rm -rf scores_implement.o scores_main.o

cleanall:
	@rm -rf scores_implement.o scores_main.o testScores
