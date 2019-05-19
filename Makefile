.PHONY: clean
FLAGS = --std=c++1y
all:
	g++ ${FLAGS} MyArray.cpp activityNotify.cpp -o notify

qsa_test:
	g++ ${FLAGS} -g MyArray.cpp quicksort_test.cpp -o qsa_test

qsq_test:
	g++ ${FLAGS} -g MyQueue.cpp quicksort_test.cpp -o qsq_test

csa_test:
	g++ ${FLAGS} MyArray.cpp counting_test.cpp -o csa_test

csq_test:
	g++ ${FLAGS} MyQueue.cpp counting_test.cpp -o csq_test

clean:
	rm -f qsq_test qsa_test csa_test csq_test countingsort_test notify a.out

