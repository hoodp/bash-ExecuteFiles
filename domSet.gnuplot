set terminal png
set output "distribution.png"
set xlabel "Min. Dominating Set Size" 
set ylabel "# of Graphs" 
set title "Minimum Dominating Set Sizes" 
plot "summary" with linespoints