# CIS 361 - Homework 5 & 6
## Homework 6
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