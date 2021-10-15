# withdraw_frontbytes_of_file
a tool, to withdraw front bytes of file, you can specify source file name, destination file name and bytes number

1.raw is the source file for test

2.raw is the destination file for test

3.withdraw.c is the main program

4.withdraw.mk is the makefile program

5.withdraw is the output file, run in linux command

6.make and execute usage:
![飞书20211015-105558](https://user-images.githubusercontent.com/29355190/137425244-c5d08a09-4b09-42a3-97d1-608afb3d567f.png)
1).不用makefile名字的话，用.mk文件，那需要make时带-f选项
2)./filename表示执行当前文件夹下的该文件
3).后面三个框是需要用户自己输入的信息，源文件名，目的文件名，提取的字节数量
