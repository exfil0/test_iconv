
#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>
#include <string.h>
#include <errno.h>

int main() {
    iconv_t cd = iconv_open("ISO-2022-CN-EXT", "UTF-8");
    if (cd == (iconv_t)-1) {
        perror("iconv_open");
        exit(EXIT_FAILURE);
    }

    char inbuf[256];
    strcpy(inbuf, "Test string to trigger CVE-2024-2961 vulnerability");
    size_t inbytesleft = strlen(inbuf);

    char outbuf[256];
    char *outptr = outbuf;
    size_t outbytesleft = sizeof(outbuf);

    if (iconv(cd, &inbuf, &inbytesleft, &outptr, &outbytesleft) == (size_t)-1) {
        perror("iconv");
        iconv_close(cd);
        exit(EXIT_FAILURE);
    }

    printf("Conversion successful\n");

    iconv_close(cd);
    return 0;
}
