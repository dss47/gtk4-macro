TEX = pdflatex
LATEXMK = latexmk
MAIN = main.tex
TARGET = build/main.pdf
SRC = *.tex

$(TARGET): $(SRC)
	mkdir -p build
	@if command -v $(LATEXMK) >/dev/null 2>&1; then \
		$(LATEXMK) -pdf -quiet -output-directory=build $(MAIN); \
	elif command -v $(TEX) >/dev/null 2>&1; then \
		$(TEX) -interaction=nonstopmode -halt-on-error -output-directory=build $(MAIN) >/dev/null; \
		$(TEX) -interaction=nonstopmode -halt-on-error -output-directory=build $(MAIN) >/dev/null; \
	else \
		echo "Error: neither 'latexmk' nor 'pdflatex' is installed; cannot build PDF."; \
		echo "Install a LaTeX distribution (e.g., TeX Live) and optionally latexmk, then rerun: make -C report2"; \
		exit 127; \
	fi
	cp $(TARGET) main.pdf

all: $(TARGET)

clean:
	rm -rf build

distclean: clean
	rm -f main.pdf

.PHONY: all clean distclean
