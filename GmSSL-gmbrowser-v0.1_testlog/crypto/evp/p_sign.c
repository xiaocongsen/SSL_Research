/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
#ifndef OPENSSL_NO_SM2
# include <openssl/sm2.h>
#endif
#include "internal/evp_int.h"

int EVP_SignFinal(EVP_MD_CTX *ctx, unsigned char *sigret,
                  unsigned int *siglen, EVP_PKEY *pkey)
{
    unsigned char m[EVP_MAX_MD_SIZE];
    unsigned int m_len = 0;
    int i = 0;
    size_t sltmp;
    EVP_PKEY_CTX *pkctx = NULL;

    *siglen = 0;
    if (EVP_MD_CTX_test_flags(ctx, EVP_MD_CTX_FLAG_FINALISE)) {
        if (!EVP_DigestFinal_ex(ctx, m, &m_len))
            goto err;
    } else {
        int rv = 0;
        EVP_MD_CTX *tmp_ctx = EVP_MD_CTX_new();
        if (tmp_ctx == NULL) {
            EVPerr(EVP_F_EVP_SIGNFINAL, ERR_R_MALLOC_FAILURE);
            return 0;
        }
        rv = EVP_MD_CTX_copy_ex(tmp_ctx, ctx);
        if (rv)
            rv = EVP_DigestFinal_ex(tmp_ctx, m, &m_len);
        EVP_MD_CTX_free(tmp_ctx);
        if (!rv)
            return 0;
    }

    sltmp = (size_t)EVP_PKEY_size(pkey);
    i = 0;
    pkctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (pkctx == NULL)
        goto err;
    if (EVP_PKEY_sign_init(pkctx) <= 0)
        goto err;
    if (EVP_PKEY_CTX_set_signature_md(pkctx, EVP_MD_CTX_md(ctx)) <= 0)
        goto err;
#ifndef OPENSSL_NO_SM2
    if (EVP_PKEY_id(pkey) == EVP_PKEY_EC && EC_GROUP_get_curve_name(
        EC_KEY_get0_group(EVP_PKEY_get0_EC_KEY(pkey))) == NID_sm2p256v1) {
# ifdef SM2_DEBUG
        fprintf(stderr, "[SM2_DEBUG] %s->EVP_PKEY_CTX_set_ec_scheme\n", __FUNCTION__);
# endif
        if (EVP_PKEY_CTX_set_ec_scheme(pkctx, NID_sm_scheme) <= 0) {
            goto err;
        }
    }
#endif
    {
        int gi = 0;
        printf("GMold EVP SignFinal m =[");
        for(gi=0; gi<m_len; gi++){
                printf("%02X-", m[gi]);
        }
        printf("]\n");
    }			//TODO xcst
    if (EVP_PKEY_sign(pkctx, sigret, &sltmp, m, m_len) <= 0)
        goto err;
    *siglen = sltmp;
    i = 1;
 err:
    EVP_PKEY_CTX_free(pkctx);
    return i;
}
