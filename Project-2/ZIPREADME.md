# Run-Length Encoding Utilities

This repository contains two utility programs for simple file compression and decompression using run-length encoding (RLE). RLE is a form of lossless data compression in which runs of data are stored as a single data value and count.

## Programs

- `my-zip`: Compresses one or more text files using RLE, producing a binary output of 4-byte integers followed by a single character, indicating the count and the character respectively.
- `my-unzip`: Decompresses files that were compressed with `my-zip`, restoring them to their original state.

## Getting Started

### Prerequisites

- A C compiler such as GCC
- Make (optional for easier compilation)

### Compilation

You can compile both programs with the following commands:

```sh
gcc -o my-zip my-zip.c
gcc -o my-unzip my-unzip.c
```

Alternatively, if you have a `Makefile`, you could simply run:

```sh
make
```

### Usage

To compress files with `my-zip`, redirect the output to a file as follows:

```sh
./my-zip input1.txt [input2.txt ...] > output.z
```

To decompress a file with `my-unzip`, you can use:

```sh
./my-unzip output.z
```

## Implementation Details

- `my-zip` reads through the input file(s) and compresses them using run-length encoding. The output is a binary format where each 5-byte block contains a 4-byte integer (representing the count of repeated characters) followed by the single repeated character.
- `my-unzip` reads the binary compressed file and decompresses it, effectively reversing the process performed by `my-zip`.

## Example

Given a file `example.txt` containing:

```
aaaaabbbcccdde
```

Compressing it with `my-zip` and then decompressing with `my-unzip` will produce:

```
aaaaabbbcccdde
```
