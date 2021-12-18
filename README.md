# 42Rank02

Preparation for Rank02. viel Glück!


# LLDB debugger
Basic commands to run the low-level-debugger in console.

	gcc -g ft_printf.c main.c -o myprint 

	lldb myprint					[Start debugger]
	lldb -- union.c asdf asdjklD 	[Start debugger with parameters]
	
	b ft_printf				[set breakpoint in the function]
	b main.c:10				[set breakpoint in file-name:line-nbr]
	
	run
	s 						[next step]
	p <variable-name>		[view value from variable]
	q						[exit]

https://lldb.llvm.org/use/map.html


It can be used the flags in compilation time:
	
	-fsanitize=address

As well, the system leaks in the main: 

	system("leaks a.out");