CXX         = clang++
WARNINGS    = -Wall -Wextra -Wparentheses -Wno-dangling-else
LIBARYFLAGS = -lncurses -stdlib=libc++
CXXFLAGS    = -std=c++1z $(WARNINGS) $(LIBARYFLAGS) -g $(SANS)

.PHOMY:all seg msan
all: format TAGS deps mains
seg: clean msan
msan:
	make --no-print-directory all SANS=-fsanitize=address

# generate the etags file
TAGS:
	@rm -f TAGS
	@git ls-files|grep "pp$$"|xargs -r etags -a
	@echo "Generated Tags"

# use the etags file to find all excicutables
.PHOMY:mains
mains:
	@for f in `ls *.c*` ; do \
		if etags $$f -o - | grep "int main(" - > /dev/null; \
			then echo $$f | sed -e 's/[.][^.]*$$/.bin/' -e 's/.*/make --no-print-directory &/' |sh; \
		fi ; \
	done

.PHOMY:deps
deps:
	-@for f in `ls *.cpp` ; do \
		echo $$f | sed -e 's,cpp$$,d,' -e 's/.*/make -s .d\/&/'|sh; \
	done

# dependancy making
DEPDIR      = .d
$(shell mkdir -p $(DEPDIR) > /dev/null)
.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR)/%.d: %.cpp
	@set -e; rm -f $@; \
	 $(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	 echo ".INTERMEDIATE: $*.o" >> $@; \
	 sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ >> $@; \
	 sed -e 's,[.]o\([ :]\),.bin\1,g' -e 's,[.][hc]pp\>,.o,g' -e 's,\<[a-zA-Z]*[.]tpp\>,,g' < $@.$$$$ >> $@; \
	 printf '\t$$(CXX) $$(CXXFLAGS) $$(LIBARYFLAGS) -o $$@ $$^' >> $@; \
	 echo >> $@; \
	 rm -f $@.$$$$
	@echo "remade $@"

# emacs flycheck-mode
.PHOMY:check-syntax csyntax
check-syntax: csyntax
csyntax:
	$(CXX) $(CXXFLAGS) -c ${CHK_SOURCES} -o /dev/null

.PHOMY: clean
clean:
	rm -rf -- *.o *.bin .d/

.PHOMY: format
format:
	@find|egrep '.*[.](cpp|cxx|cc|c++|c|tpp|txx)$$'|sed 's/[] ()'\''\\[&;]/\\&/g'|xargs clang-format -i
	@echo "reformatted code"


include $(wildcard $(DEPDIR)/*.d)
include $(wildcard *.d)
