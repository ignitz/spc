clean_exec() {
	if [ -f *.out ]; then
		echo "cleaning executables"
		rm -rf *.out
	fi
}

do_test() {
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

compile() {
	g++ $1.cpp -std=c++14 -o $1.out
}

check_error() {
	if ! [ -f $1.out ] ; then
		echo "Error in compile these things"
		exit 1
	fi
}

main() {
	clean_exec
	compile $1
	check_error $1
	do_test $1 $2
	clean_exec
}

do_dev() {
	clean_exec
	compile $1
	check_error $1
	cat tests/input1.txt
	./$1.out < tests/input1.txt
	clean_exec
}

test_times=9
test_id=1961

# do_dev $test_id
main $test_id $test_times
