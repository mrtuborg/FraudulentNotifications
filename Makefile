.PHONY: clean
FLAGS = --std=c++1y
all:
	g++ ${FLAGS} MyArray.cpp activityNotify.cpp -o notify

qs_test:
	g++ ${FLAGS} MyArray.cpp quicksort_test.cpp -o quicksort_test

cs_test:
	g++ ${FLAGS} MyArray.cpp counting_test.cpp -o countingsort_test

clean:
	rm -f quicksort_test countingsort_test notify a.out

