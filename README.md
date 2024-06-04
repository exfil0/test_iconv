
# Testing CVE-2024-2961

This repository contains a C program to test for CVE-2024-2961, which involves a buffer overflow vulnerability in the `iconv()` function of the GNU C Library (glibc).

## Prerequisites

- A system with glibc version 2.39 or older.
- GCC (GNU Compiler Collection) installed.
- `iconv` library installed.

## Steps to Test

### 1. Check glibc Version

Ensure that your system has glibc version 2.39 or older:

```bash
ldd --version
```

### 2. Clone the Repository

Clone this repository to your local machine:

```bash
git clone https://github.com/exfil0/test_iconv.git
cd test_iconv
```

### 3. Compile the Program

Use GCC to compile the C program:

```bash
gcc -o test_iconv test_iconv.c -liconv
```

### 4. Run the Program

Execute the compiled program:

```bash
./test_iconv
```

### 5. Analyze the Results

- If the program crashes or behaves unexpectedly, it might be an indication of the buffer overflow.
- Use debugging tools like `gdb` to analyze the crash and confirm if it is related to the vulnerability.

### Optional: Debugging with GDB

If you encounter a crash, you can use `gdb` to get more details:

```bash
gdb ./test_iconv
```

Within GDB, run the program:

```gdb
run
```

If the program crashes, you can inspect the state of the program:

```gdb
bt
```

This will give you a backtrace of the crash, which can help in diagnosing if the overflow is due to the CVE.

### Optional: Using Sanitizers

Compile the program with AddressSanitizer to catch the overflow:

```bash
gcc -fsanitize=address -o test_iconv test_iconv.c -liconv
./test_iconv
```

AddressSanitizer will provide detailed information if there is a buffer overflow.

## Mitigation

If the vulnerability is confirmed, consider updating glibc to a version where this issue is patched. You can download and install the latest version from the GNU project's website or your distribution's package manager.

## Disclaimer

This code is for educational and testing purposes only. Do not use it on systems without proper authorization.
