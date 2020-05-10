#Kaizen ~/so_test $ cat -e -t -v  mk.t
all:	
	git	add	--all
	@read -p "Hello, please	write-down your	commite:" com;	\
	echo "your commit is" 	$$com;	git	commit	-m	$$com;	\
	git	pull	--all 
	git	push	-u	origin	master

