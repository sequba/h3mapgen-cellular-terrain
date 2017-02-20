TEX = pdflatex -halt-on-error -file-line-error

all: report.pdf

check:
	aspell --lang=en_GB --mode=tex check report.tex

report.pdf: report.tex clean
	$(TEX) report.tex && $(TEX) report.tex && $(TEX) report.tex && $(TEX) report.tex && $(TEX) report.tex && $(TEX) report.tex && $(TEX) report.tex

clean:
	rm -f *.aux
