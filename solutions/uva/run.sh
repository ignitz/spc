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
		./$1.out < $1/tests/input$i.txt > $1/tests/temp$i.txt
		diff $1/tests/temp$i.txt $1/tests/output$i.txt > /dev/null
		if [ $? -ne 0 ] ; then
			echo "----------------- error in $i"
			diff $1/tests/temp$i.txt $1/tests/output$i.txt
		fi
		rm -rf $1/tests/temp$i.txt
	done
}

do_test_python() {
	for i in $(seq 1 $2)
	do
		echo "test number $i:"
		python3 $1/$1.py < $1/tests/input$i.txt > $1/tests/temp$i.txt
		diff $1/tests/temp$i.txt $1/tests/output$i.txt > /dev/null
		if [ $? -ne 0 ] ; then
			echo "----------------- error in $i"
			diff $1/tests/temp$i.txt $1/tests/output$i.txt
		fi
		rm -rf $1/tests/temp$i.txt
	done
}

compile() {
	g++ $1/$1.cpp -g -std=gnu++11 -o $1.out
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
	if ! [ -d $1/tests/ ]; then
		echo "No tests directory in $1"
		exit 1
	fi
	cat $1/tests/temp.txt
	echo '===================================='
	./$1.out < $1/tests/temp.txt

	clean_exec
}

do_dev_python() {
	if ! [ -d $1/tests/ ]; then
		echo "No tests directory in $1"
		exit 1
	fi
	python3 $1/$1.py < $1/tests/temp.txt
}

test_times=$3
test_id=$2
# cpp or python, python version is 3
choose_language=$1

if [ $choose_language = "cpp" ]; then
	if [ $test_times ]; then
		main_cpp $test_id $test_times
	else
		do_dev_cpp $test_id
	fi
elif [ $choose_language = "py" ]; then
	if [ $test_times ]; then
		main_python $test_id $test_times
	else
		do_dev_python $test_id
	fi
elif [ $choose_language = "make" ]; then
   if [ -d $test_id ]; then
	   echo 'Test ' . $test_id . ' already exist.'
	   exit 1
   else
	   mkdir $test_id
	   touch $test_id/$test_id.cpp
	   # Estou assumindo que já é do SPOJ
	   printf "/*\n * Yuri Niitsuma\n * 2011039023\n * XXXXXXXXXXXXXXXXXX\n * $test_id\n */\n" > $test_id/$test_id.cpp
	   mkdir $test_id/tests
	   touch $test_id/tests/temp.txt
	   touch $test_id/tests/input1.txt
	   touch $test_id/tests/output1.txt
	fi
else
	echo "No language set"
fi
