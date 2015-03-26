bin_PROGRAMS = \
  mash3 \
  mash3_single_and_multi_modulus \
  mash3_varying_modulus \
  next_prime_below \
  mash3_linearity \
  mash3_spectrum

AM_CFLAGS = $(DACMODEL_CFLAGS)

AM_CPPFLAGS = $(DACMODEL_CPPFLAGS)

LDADD = ../dsp/lib_dacmodel_dsp.la

mash3_SOURCES = \
  mash3.cpp

mash3_single_and_multi_modulus_SOURCES = \
  mash3_single_and_multi_modulus.cpp

mash3_varying_modulus_SOURCES = \
  mash3_varying_modulus.cpp

next_prime_below_SOURCES = \
  next_prime_below.cpp

mash3_linearity_SOURCES = \
  mash3_linearity.cpp

mash3_spectrum_SOURCES = \
  mash3_spectrum.cpp

linearity : linearity.png
.PHONY : linearity

linearity.png : linearity.dat linearity.gnuplot
	gnuplot linearity.gnuplot

linearity.dat : mash3_linearity
	$(builddir)/mash3_linearity > linearity.dat

spectrum : spectrum.png
.PHONY : spectrum

spectrum.png : spectrum.dat spectrum.gnuplot
	gnuplot spectrum.gnuplot

spectrum.dat : mash3_spectrum
	$(builddir)/mash3_spectrum > spectrum.dat

CLEANFILES = \
  linearity.dat linearity.png \
  spectrum.dat spectrum.png spectrum-lf.png
