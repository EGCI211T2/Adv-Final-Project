compile: main.cpp 
	 g++ main.cpp -o main

compilet: test.cpp
	g++ test.cpp -o main

run: main
	 ./main

clean: main
	 rm main