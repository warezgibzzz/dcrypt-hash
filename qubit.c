#include "qubit.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"


void qubit_hash(const char* input, char* output)
{
    sph_luffa512_context     ctx_luffa;
    sph_cubehash512_context  ctx_cubehash;
    sph_shavite512_context   ctx_shavite;
    sph_simd512_context      ctx_simd;
    sph_echo512_context      ctx_echo;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16], hashB[16];

    sph_luffa512_init (&ctx_luffa);
    sph_luffa512 (&ctx_luffa, input, 80);
    sph_luffa512_close (&ctx_luffa, hashA);

    sph_cubehash512_init (&ctx_cubehash);
    sph_cubehash512 (&ctx_cubehash, hashA, 64);
    sph_cubehash512_close(&ctx_cubehash, hashB);

    sph_shavite512_init (&ctx_shavite);
    sph_shavite512 (&ctx_shavite, hashB, 64);
    sph_shavite512_close(&ctx_shavite, hashA);

    sph_simd512_init (&ctx_simd);
    sph_simd512 (&ctx_simd, hashA, 64);
    sph_simd512_close(&ctx_simd, hashB);

    sph_echo512_init (&ctx_echo);
    sph_echo512 (&ctx_echo, hashB, 64);
    sph_echo512_close(&ctx_echo, hashA);

    memcpy(output, hashA, 32);
	
}
