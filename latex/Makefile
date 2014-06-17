DOCNAME = latex
BIBS = 
FIGDIR = figures
FIGS = $(wildcard $(FIGDIR)/*)

$(DOCNAME).pdf: $(DOCNAME).tex $(BIBS) $(FIGS)
ifeq ($(BIBS),)
else
	pdflatex $(DOCNAME)
	bibtex $(DOCNAME)
endif
	pdflatex $(DOCNAME)
	pdflatex $(DOCNAME) 
	rm -f $(DOCNAME).aux
	rm -f $(DOCNAME).bbl
	rm -f $(DOCNAME).blg
	rm -f $(DOCNAME).log

tarball: $(DOCNAME).tgz

$(DOCNAME).tgz: $(DOCNAME).tex $(BIBS) $(FIGS)
	mkdir $(DOCNAME)
ifeq ($(BIBS),)
else
	mv $(BIBS) $(DOCNAME)
endif
	if [ -f $(DOCNAME).pdf ]; then mv $(DOCNAME).pdf $(DOCNAME); fi
	mv $(DOCNAME).tex $(DOCNAME)
	mv $(FIGDIR) $(DOCNAME)
	tar -czf $(DOCNAME).tgz $(DOCNAME)
	mv $(DOCNAME)/* ./
	rmdir $(DOCNAME)

.PHONEY : clean

clean:
	rm -f $(DOCNAME).aux
	rm -f $(DOCNAME).bbl
	rm -f $(DOCNAME).blg
	rm -f $(DOCNAME).log
	rm -f $(DOCNAME).pdf
	rm -f $(DOCNAME).tgz

