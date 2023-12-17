Key Requirements:
				Program Name: minishell
				Turn-in Files: Makefile, *.h, *.c
Makefile:
				Include rules: NAME, all, clean, fclean, re
Mandatory Part:
		Program Behavior:
						My minishell should:

1.	Display a prompt when waiting for a new command.
2.	Have a working history.
3.	Search and launch the right executable based on the PATH variable or using a relative or absolute path.
4.	Avoid using more than one global variable to indicate a received signal.
5.	Not interpret unclosed quotes or special characters that are not required by the subject.
6.	Handle single quotes ('), preventing the shell from interpreting metacharacters in the quoted sequence.
7.	Handle double quotes (") preventing the shell from interpreting metacharacters except for $ (dollar sign).
8.	Implement redirections: <, >, <<, >>.
9.	Implement pipes (| character).
10.	Handle environment variables ($ followed by a sequence of characters).
11.	Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
12.	Handle ctrl-C, ctrl-D, and ctrl-\ as described.
13.	Implement builtins: echo with option -n, cd, pwd, export, unset, env, exit.
14.	Recommendations:
15.	Ensure Norm Compliance.
16.	Test thoroughly, especially with various edge cases.
17.	Handle memory leaks in my own code.
18.	Include a Makefile that compiles my source files with the required flags.
