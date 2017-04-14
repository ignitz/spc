#!/bin/bash

clean_exec() {
	if [ -f *.out ]; then
		echo "cleaning executables"
		rm -rf *.out
	fi
}

do_test_cpp() {
	for i in $(seq 1 $2)
	do
		echo "test number $i:"
		./$1.out < tests/input$i.txt > tests/temp$i.txt
		diff tests/temp$i.txt tests/output$i.txt > /dev/null
		if [ $? -ne 0 ] ; then
			echo "----------------- error in $i"
			diff tests/temp$i.txt tests/output$i.txt
		fi
		rm -rf tests/temp$i.txt
	done
}

do_test_python() {
	for i in $(seq 1 $2)
	do
		echo "test number $i:"
		python3 $1.py < tests/input$i.txt > tests/temp$i.txt
		diff tests/temp$i.txt tests/output$i.txt > /dev/null
		if [ $? -ne 0 ] ; then
			echo "----------------- error in $i"
			diff tests/temp$i.txt tests/output$i.txt
		fi
		rm -rf tests/temp$i.txt
	done
}

compile() {
	g++ $1.cpp -std=c++14 -o $1.out
}

check_error() {
	if ! [ -f $1.out ] ; then
		echo "Error in compile these things"
		exit 1
	fi
}

main_cpp() {
	clean_exec
	compile $1
	check_error $1
	do_test_cpp $1 $2
	clean_exec
}

main_python() {
	do_test_python $1 $2
}

do_dev_cpp() {
	clean_exec
	compile $1
	check_error $1
	cat tests/input1.txt
	./$1.out < tests/input1.txt
	clean_exec
}

do_dev_python() {
	python3 $1.py < tests/input1.txt
}

test_times=1
test_id=2091
# cpp or python, python version is 3
choose_language=python

if [ $choose_language = "cpp" ]; then
	# do_dev_cpp $test_id
	# main_cpp $test_id $test_times
	:
elif [ $choose_language = "python" ]; then
	do_dev_python $test_id
	# main_python $test_id $test_times
	:
else
	echo "No language set"
fi
