.PHONY: clean
FLAGS = --std=c++1y
all:
	g++ ${FLAGS} MyArray.cpp activityNotify.cpp -o notify

qsa_test:
	g++ ${FLAGS} -g MyArray.cpp quicksort_test.cpp -o qsa_test

qsq_test:
	g++ ${FLAGS} -g MyQueue.cpp quicksort_test.cpp -o qsq_test

cs_test:
	g++ ${FLAGS} MyArray.cpp counting_test.cpp -o countingsort_test

clean:
	rm -f qsq_test qsa_test countingsort_test notify a.out

