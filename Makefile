.PHONY: clean
FLAGS = --std=c++1y
all:
	g++ ${FLAGS} quicksort.cpp activityNotify.cpp -o notify

test:
	g++ ${FLAGS} quicksort.cpp quicksort_test.cpp -o quicksort

clean:
	rm -f quicksort notify a.out

