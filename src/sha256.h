// Copyright (c) 2014-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_SHA256_H
#define BITCOIN_CRYPTO_SHA256_H

#include <stdint.h>

typedef uint32_t size_t;

void memcpy (void *dst, const void *src, size_t len) {
    auto p = static_cast <char *> (dst);
    auto q = static_cast <const char *> (src);
    do {
        * p ++ = * q ++;
    } while (-- len);
}

/** A hasher class for SHA-256. */
class CSHA256
{
private:
    uint32_t s[8];
    unsigned char buf[64];
    uint64_t bytes{0};

public:
    static const size_t OUTPUT_SIZE = 32;

    CSHA256();
    CSHA256& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA256& Reset();
};

void __attribute__((export_name("SHA256"))) SHA256 (const unsigned char* data, unsigned char *hash) {
    CSHA256 SHA256;
    SHA256.Write (data, hash - data);
    SHA256.Finalize (hash);
}

#endif // BITCOIN_CRYPTO_SHA256_H
