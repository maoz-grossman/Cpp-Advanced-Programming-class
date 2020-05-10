#Kaizen ~/so_test $ cat -e -t -v  mk.t
all:
	git	add	--all	
	echo Hello,	please	write-down	your	commite
	read	Commit	&&	echo your commit is 	$Commit	&&	git	commit	-m	$Commit
	git	pull	--all 
	git	push	-u	origin	master

