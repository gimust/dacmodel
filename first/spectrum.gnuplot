set term png size 800, 600

#with a 100MHz sample rate and a 2^24 length fft, each bin is ~12Hz
set output "spectrum.png"
set logscale x
plot 'spectrum.dat' using ($1*12):2 every 10000

reset

set output "spectrum-lf.png"
set logscale x
plot 'spectrum.dat' using ($1*12):2 every 100::0::100000
