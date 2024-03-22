# my-zip and my-unzip

## Overview

`my-zip` and `my-unzip` are a pair of command-line tools designed for simple file compression and decompression, respectively. They utilize run-length encoding (RLE) for compression, a technique that replaces sequences of repeated characters with a single character and a count. This documentation provides an overview of their functionality, usage, and implementation details.

## Run-Length Encoding (RLE)

Run-length encoding is a form of lossless data compression where sequences of data are stored as a single data value and count. For example, the string `aaaaabbb` would be encoded as `5a3b` in a human-readable form. `my-zip` applies RLE to compress files, and `my-unzip` reverses the process to decompress them.

## File Format

The compressed file format consists of a series of records, each of which includes a 4-byte integer indicating the number of times a character is repeated, followed by the single character itself. This binary format ensures compact storage, with each record taking exactly 5 bytes.

## `my-zip`: Compression Tool

### Usage

```bash
./my-zip file1 [file2 ...] > output.z
```

`my-zip` reads one or more text files, compresses them using RLE, and outputs the result to standard output (stdout). Users typically redirect this output to a file using the `>` operator.

### Functionality

- **File Reading**: `my-zip` sequentially reads the content of the specified file(s).
- **Compression**: It compresses the content by applying RLE.
- **Output**: The compressed data is written to stdout in a binary format.

### Implementation Details

- `my-zip` processes files one at a time but treats multiple files as a continuous stream for compression.
- Each character sequence is encoded as a 4-byte integer count followed by the character.
- The output is binary, not human-readable ASCII text.

## `my-unzip`: Decompression Tool

### Usage

```bash
./my-unzip file.z
```

`my-unzip` reads a compressed file produced by `my-zip` and writes the decompressed text to standard output (stdout).

### Functionality

- **File Reading**: `my-unzip` opens and reads the compressed binary file.
- **Decompression**: It decodes the RLE-compressed data.
- **Output**: The decompressed text is printed to stdout.

### Implementation

- `my-unzip` reads 5-byte records from the input file, extracting the 4-byte count and the 1-byte character.
- It prints each character to stdout the number of times specified by the preceding count.

## Error Handling

Both tools exit with a return code of 1 and display a usage message if no files are specified. `my-zip` also checks for file read errors, while `my-unzip` checks for read errors during decompression.

## Compilation

The tools can be compiled with GCC:

```bash
gcc -o my-zip my-zip.c
gcc -o my-unzip my-unzip.c
```
