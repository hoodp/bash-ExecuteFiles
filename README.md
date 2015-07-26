# CIS 361 - Homework 5 & 6 & 7
## Homework 7
### Runs the script from hw5 or hw6 among 9 different workstations in the eos labs. 
Modify your script from Homework 5 ( or 6 ) so that you can divide the execution of the program among 9 different workstations on the EOS lab.

The ssh command allows you to execute a command on another machine.

For instance, if you have logged into eos01, you can execute the following command on the prompt

 ssh eos02 uptime

This will execute the command uptime on the machine eos02.

The first time you execute a command remotely on another machine, you will be asked to confirm if the key on the other machine is correct. Answer yes. An entry will be created on a file called .known_hosts (in the subdirectory .ssh) that will contain the name of the machine and the key. The next time you execute a ssh command on that machine, you won't have to confirm the key.

As a suggestion, have the machine eos01 execute the command domSet on all the files with the form file1*, eos02 will work on the files of the form file2* and so on.

## Homework 6
### Uses gawk script instead of using sort and uniq from homework 5. 
Modify the script you wrote for Homework 6. Instead of using sort and uniq to produce the count of graphs with a particular value of the dominating set, use an awk script.

Include the instructions for the awk script in your bash script.

Generate a png file at the end, using gnuplot. This plot should have the possible values of the size of the dominating set in the X axis and the actual number of graphs with that particular value in the Y axis. Use appropriate labels for the plot.

## Homework 5
### Bash script to execute program for multiple files. 
The attached zip file, allfiles.zip, contains the 1044 possible undirected graphs of size 7 (Thanks to Professor Jerry Scripps for making these files available).

The names of the files are file0, file1, file2, ..., file1042, file1043.

Write a bash script that will execute the program that finds the minimum dominating set for a graph on each and every one of these graphs.
The script shall generate a single output file called results that should contain one line for every one of the 1044 input files.

That line should contain a single-digit integer (because of the definition of the minimum dominating set that integer should be a value between 1 and 7).

Once the results file has been created, sort it using the command "sort" and redirect the output to a file called sortedResults.

Then use the uniq command on sortedResults with the -c option to count how many entries there are for every possible value. Redirect the output to a file called summary.

This the summary file I calculated with my script:

156 1

708 2

152 3

21 4

5 5

1 6

1 7