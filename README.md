# withdraw_frontbytes_of_file
a tool, to withdraw front bytes of file, you can specify source file name, destination file name and bytes number

1.raw is the source file for test

2.raw is the destination file for test

3.withdraw.c is the main program

4.withdraw.mk is the makefile program

5.withdraw is the output file, run in linux command

6.make and execute usage:

![飞书20211015-105558](https://user-images.githubusercontent.com/29355190/137425244-c5d08a09-4b09-42a3-97d1-608afb3d567f.png)

1).if using .mk file instead of naming makefile，need -f option

2)./filename means execute the file in current directory

3).the last 3 informations need user to specify

new branch function:
1.auto traverse all file in a directory
2.you only need determine the directory name and the byte num that you need to withdraw.
