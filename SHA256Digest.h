// SHA-256 in C
#ifndef _SHA_256_H_
#define _SHA_256_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIGEST_LENGTH 32
#define CHUNK_SIZE 64

typedef unsigned char BYTE;
typedef unsigned long WORD; // only deal with 32-bit word

typedef struct {
	BYTE data[64];
	WORD dataLength;
	WORD hash[8];
	unsigned long long totalLength; //size of message in bit, up to 64-bits
} SHA256_CTX;

void 	SHA256Initialize(SHA256_CTX *ctx);
void 	SHA256Update(SHA256_CTX *ctx, const BYTE *in, size_t inLen);
void 	SHA256Finalize(SHA256_CTX *ctx, BYTE *out); 		//output buffer size must be at least DIGEST_LENGTH
void 	SHA256ComputeDigest(BYTE *in, size_t inLen, BYTE *out); //packaged function that deal with a single input buffer
int 	SHA256DigestSize();

#endif