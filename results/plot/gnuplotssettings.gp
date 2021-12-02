set yrange [-360:360]
set t pngcairo
set o "./results/plot.png"
set xlabel "itérations"
set ylabel "valeurs"
set title "Evolution des paramètres"
plot "./results/plot/gnuplotsdata.txt" using 1:2 with linespoints, "" u 1:3 w lp, "" u 1:4 w lp
