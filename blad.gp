# Set the output file type and size
set terminal png size 1600,1200

# Set the output file name
set output "wynikRownomierny.png"

# Set the title and axis labels
set title ""
set xlabel "x"
set ylabel "f(x)"

# Set the colors and line styles for the different series
set style line 1 lc rgb "red" lt 1 lw 2

# Plot the data from the different files
plot "wynik.txt" using 1:2 with points title "Interpolacja", \
     1/(1+10*x**6) with lines linestyle 1 title "f(x)"


set output "wynikCzebyszew.png"

plot "czebyszew.txt" using 1:2 with points title "Interpolacja na węzłach Czebyszewa", \
     1/(1+10*x**6) with lines linestyle 1 title "f(x)"