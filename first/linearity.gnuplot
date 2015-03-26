set term png size 800, 600
set output "linearity.png"
plot 'linearity.dat' using "Input":"Output" with lines
