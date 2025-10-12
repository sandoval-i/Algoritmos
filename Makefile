CPPFLAGS = -std=c++20 -O2

WARNFLAGS = -Wall -Wextra -Wshadow -Wconversion -Wparentheses -Wfloat-equal -Wpedantic -Winvalid-pch -fmax-errors=2

DEBUGFLAGS = -fsanitize=undefined -fsanitize=address -g

PCH = -I. -include stdc++.h
BITSPATH = /usr/include/x86_64-linux-gnu/c++/13/bits/stdc++.h

template : template.cpp
	g++ $(CPPFLAGS) $(WARNFLAGS) $(DEBUGFLAGS) $(PCH) -o template template.cpp

.PHONY: clean headers rmall

clean:
	-rm -v template in*

headers:
	g++ $(CPPFLAGS) $(WARNFLAGS) $(DEBUGFLAGS) -o stdc++.h.gch $(BITSPATH)

rmall:
	-rm -rfv template stdc++.h.gch in*
