DOCNAME = latex
BIBS = 
FIGDIR = figures
FIGS = $(wildcard $(FIGDIR)/*)

$(DOCNAME).pdf: $(DOCNAME).tex $(BIBS) $(FIGS)
ifeq( $(BIBS),)
	latex $(DOCNAME)
	latex $(DOCNAME)
else
	latex $(DOCNAME)
	bibtex $(DOCNAME)
	latex $(DOCNAME)
	latex $(DOCNAME) 
endif