make:
	clang++ -std=c++23 main.cpp -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./game
