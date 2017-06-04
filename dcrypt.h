// Copyright (c) 2013-2014 The Slimcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DCRYPT_H
#define DCRYPT_H

#ifdef __cplusplus
extern "C" {
#endif

#define DCRYPT_DIGEST_LENGTH 64

//the dcrypt hashing algorithm for a single piece of data
uint256 dcrypt_hash(const uint8_t *data, size_t data_sz, uint8_t *hash_digest = 0);

#ifdef __cplusplus
}
#endif

#endif // DCRYPT_H
