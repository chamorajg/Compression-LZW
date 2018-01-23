# Compression-LZW


Lempel-Ziv-Welch (LZW) Algorithm

The LZW algorithm is a very common compression technique.

Suppose we want to encode the Oxford Concise English dictionary which contains about 159,000 entries. Why not just transmit each word as an 18 bit number?

Problems:

Too many bits,
everyone needs a dictionary,
only works for English text.
Solution: Find a way to build the dictionary adaptively.
Original methods due to Ziv and Lempel in 1977 and 1978. Terry Welch improved the scheme in 1984 (called LZW compression).
It is used in UNIX compress -- 1D token stream (similar to below)
It used in GIF comprerssion -- 2D window tokens (treat image as with Huffman Coding Above).
