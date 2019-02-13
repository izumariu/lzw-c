lzw: lzw.c
	$(CC) -o $@ $?

clean:
	$(RM) lzw

.PHONY: clean
