/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include <openssl/objects.h>
#include "ssl_locl.h"

/*-
 * TLS/SSLv3 methods
 */

IMPLEMENT_tls_meth_func(TLS_ANY_VERSION, 0, 0,
                        TLS_method,
                        ossl_statem_accept,
                        ossl_statem_connect, TLSv1_2_enc_data)
IMPLEMENT_tls_meth_func(TLS1_3_VERSION, 0, SSL_OP_NO_TLSv1_3,
                        tlsv1_3_method,
                        ossl_statem_accept,
                        ossl_statem_connect, TLSv1_3_enc_data)
#ifndef OPENSSL_NO_TLS1_2_METHOD
IMPLEMENT_tls_meth_func(TLS1_2_VERSION, 0, SSL_OP_NO_TLSv1_2,
                        tlsv1_2_method,
                        ossl_statem_accept,
                        ossl_statem_connect, TLSv1_2_enc_data)
#endif
#ifndef OPENSSL_NO_TLS1_1_METHOD
IMPLEMENT_tls_meth_func(TLS1_1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1_1,
                        tlsv1_1_method,
                        ossl_statem_accept,
                        ossl_statem_connect, TLSv1_1_enc_data)
#endif
#ifndef OPENSSL_NO_TLS1_METHOD
IMPLEMENT_tls_meth_func(TLS1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1,
                        tlsv1_method,
                        ossl_statem_accept, ossl_statem_connect, TLSv1_enc_data)
#endif
#ifndef OPENSSL_NO_SSL3_METHOD
IMPLEMENT_ssl3_meth_func(sslv3_method, ossl_statem_accept, ossl_statem_connect)
#endif
/*-
 * TLS/SSLv3 server methods
 */
IMPLEMENT_tls_meth_func(TLS_ANY_VERSION, 0, 0,
                        TLS_server_method,
                        ossl_statem_accept,
                        ssl_undefined_function, TLSv1_2_enc_data)
IMPLEMENT_tls_meth_func(TLS1_3_VERSION, 0, SSL_OP_NO_TLSv1_3,
                        tlsv1_3_server_method,
                        ossl_statem_accept,
                        ssl_undefined_function, TLSv1_3_enc_data)
#ifndef OPENSSL_NO_TLS1_2_METHOD
IMPLEMENT_tls_meth_func(TLS1_2_VERSION, 0, SSL_OP_NO_TLSv1_2,
                        tlsv1_2_server_method,
                        ossl_statem_accept,
                        ssl_undefined_function, TLSv1_2_enc_data)
#endif
#ifndef OPENSSL_NO_TLS1_1_METHOD
IMPLEMENT_tls_meth_func(TLS1_1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1_1,
                        tlsv1_1_server_method,
                        ossl_statem_accept,
                        ssl_undefined_function, TLSv1_1_enc_data)
#endif
#ifndef OPENSSL_NO_TLS1_METHOD
IMPLEMENT_tls_meth_func(TLS1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1,
                        tlsv1_server_method,
                        ossl_statem_accept,
                        ssl_undefined_function, TLSv1_enc_data)
#endif
#ifndef OPENSSL_NO_SSL3_METHOD
IMPLEMENT_ssl3_meth_func(sslv3_server_method,
                         ossl_statem_accept, ssl_undefined_function)
#endif
/*-
 * TLS/SSLv3 client methods
 */
IMPLEMENT_tls_meth_func(TLS_ANY_VERSION, 0, 0,
                        TLS_client_method,
                        ssl_undefined_function,
                        ossl_statem_connect, TLSv1_2_enc_data)
IMPLEMENT_tls_meth_func(TLS1_3_VERSION, 0, SSL_OP_NO_TLSv1_3,
                        tlsv1_3_client_method,
                        ssl_undefined_function,
                        ossl_statem_connect, TLSv1_3_enc_data)
#ifndef OPENSSL_NO_TLS1_2_METHOD
IMPLEMENT_tls_meth_func(TLS1_2_VERSION, 0, SSL_OP_NO_TLSv1_2,
                        tlsv1_2_client_method,
                        ssl_undefined_function,
                        ossl_statem_connect, TLSv1_2_enc_data)
#endif
#ifndef OPENSSL_NO_TLS1_1_METHOD
IMPLEMENT_tls_meth_func(TLS1_1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1_1,
                        tlsv1_1_client_method,
                        ssl_undefined_function,
                        ossl_statem_connect, TLSv1_1_enc_data)
#endif
#ifndef OPENSSL_NO_CNSM
IMPLEMENT_tls_meth_func(SM1_1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1_1,
                        cntls_client_method,
                        ssl_undefined_function,
                        ossl_statem_connect, TLSv1_1_enc_data)
const SSL_METHOD *gmtls_client_method(void) 
{ 
    static const SSL_METHOD gmtls_client_method_data= {
           GMTLS_VERSION, 
           0, 
           GMold_SSL_OP_NO_GMTLS, 
           tls1_new, 
           tls1_clear, 
           tls1_free, 
           ssl_undefined_function, 
           GMold_ossl_statem_connect, 
           GMold_ssl3_read,
           ssl3_peek, 
           GMold_ssl3_write,
           GMold_ssl3_shutdown,
           GMold_ssl3_renegotiate,
           GMold_ssl3_renegotiate_check, 
           GMold_ssl3_read_bytes,
           GMold_ssl3_write_bytes,
           GMold_ssl3_dispatch_alert,
           ssl3_ctrl, 
           GMold_ssl3_ctx_ctrl, 
           ssl3_get_cipher_by_char, 
           ssl3_put_cipher_by_char, 
           ssl3_pending, 
           GMold_ssl3_num_ciphers, 
           GMold_ssl3_get_cipher, 
           tls1_default_timeout, 
           &GMTLS_enc_data, 
           ssl_undefined_void_function, 
           ssl3_callback_ctrl, 
           ssl3_ctx_callback_ctrl, 
    };
    return &gmtls_client_method_data;
}
#endif
#ifndef OPENSSL_NO_TLS1_METHOD
IMPLEMENT_tls_meth_func(TLS1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_TLSv1,
                        tlsv1_client_method,
                        ssl_undefined_function,
                        ossl_statem_connect, TLSv1_enc_data)
#endif
#ifndef OPENSSL_NO_SSL3_METHOD
IMPLEMENT_ssl3_meth_func(sslv3_client_method,
                         ssl_undefined_function, ossl_statem_connect)
#endif
/*-
 * DTLS methods
 */
#ifndef OPENSSL_NO_DTLS1_METHOD
IMPLEMENT_dtls1_meth_func(DTLS1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_DTLSv1,
                          dtlsv1_method,
                          ossl_statem_accept,
                          ossl_statem_connect, DTLSv1_enc_data)
#endif
#ifndef OPENSSL_NO_DTLS1_2_METHOD
IMPLEMENT_dtls1_meth_func(DTLS1_2_VERSION, 0, SSL_OP_NO_DTLSv1_2,
                          dtlsv1_2_method,
                          ossl_statem_accept,
                          ossl_statem_connect, DTLSv1_2_enc_data)
#endif
IMPLEMENT_dtls1_meth_func(DTLS_ANY_VERSION, 0, 0,
                          DTLS_method,
                          ossl_statem_accept,
                          ossl_statem_connect, DTLSv1_2_enc_data)

/*-
 * DTLS server methods
 */
#ifndef OPENSSL_NO_DTLS1_METHOD
IMPLEMENT_dtls1_meth_func(DTLS1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_DTLSv1,
                          dtlsv1_server_method,
                          ossl_statem_accept,
                          ssl_undefined_function, DTLSv1_enc_data)
#endif
#ifndef OPENSSL_NO_DTLS1_2_METHOD
IMPLEMENT_dtls1_meth_func(DTLS1_2_VERSION, 0, SSL_OP_NO_DTLSv1_2,
                          dtlsv1_2_server_method,
                          ossl_statem_accept,
                          ssl_undefined_function, DTLSv1_2_enc_data)
#endif
IMPLEMENT_dtls1_meth_func(DTLS_ANY_VERSION, 0, 0,
                          DTLS_server_method,
                          ossl_statem_accept,
                          ssl_undefined_function, DTLSv1_2_enc_data)

/*-
 * DTLS client methods
 */
#ifndef OPENSSL_NO_DTLS1_METHOD
IMPLEMENT_dtls1_meth_func(DTLS1_VERSION, SSL_METHOD_NO_SUITEB, SSL_OP_NO_DTLSv1,
                          dtlsv1_client_method,
                          ssl_undefined_function,
                          ossl_statem_connect, DTLSv1_enc_data)
IMPLEMENT_dtls1_meth_func(DTLS1_BAD_VER, SSL_METHOD_NO_SUITEB, SSL_OP_NO_DTLSv1,
                          dtls_bad_ver_client_method,
                          ssl_undefined_function,
                          ossl_statem_connect, DTLSv1_enc_data)
#endif
#ifndef OPENSSL_NO_DTLS1_2_METHOD
IMPLEMENT_dtls1_meth_func(DTLS1_2_VERSION, 0, SSL_OP_NO_DTLSv1_2,
                          dtlsv1_2_client_method,
                          ssl_undefined_function,
                          ossl_statem_connect, DTLSv1_2_enc_data)
#endif
IMPLEMENT_dtls1_meth_func(DTLS_ANY_VERSION, 0, 0,
                          DTLS_client_method,
                          ssl_undefined_function,
                          ossl_statem_connect, DTLSv1_2_enc_data)
#if OPENSSL_API_COMPAT < 0x10100000L
# ifndef OPENSSL_NO_TLS1_2_METHOD
const SSL_METHOD *TLSv1_2_method(void)
{
    return tlsv1_2_method();
}

const SSL_METHOD *TLSv1_2_server_method(void)
{
    return tlsv1_2_server_method();
}

const SSL_METHOD *TLSv1_2_client_method(void)
{
    return tlsv1_2_client_method();
}
# endif

# ifndef OPENSSL_NO_TLS1_1_METHOD
const SSL_METHOD *TLSv1_1_method(void)
{
    return tlsv1_1_method();
}

const SSL_METHOD *TLSv1_1_server_method(void)
{
    return tlsv1_1_server_method();
}

const SSL_METHOD *TLSv1_1_client_method(void)
{
    return tlsv1_1_client_method();
}
# endif

#ifndef OPENSSL_NO_CNSM
# ifndef OPENSSL_NO_CNTLS_METHOD
const SSL_METHOD *CNTLS_client_method(void)
{
    return cntls_client_method();
}
const SSL_METHOD *GMold_client_method(void)
{
    return gmtls_client_method();
}
#endif
#endif

# ifndef OPENSSL_NO_TLS1_METHOD
const SSL_METHOD *TLSv1_method(void)
{
    return tlsv1_method();
}

const SSL_METHOD *TLSv1_server_method(void)
{
    return tlsv1_server_method();
}

const SSL_METHOD *TLSv1_client_method(void)
{
    return tlsv1_client_method();
}
# endif

# ifndef OPENSSL_NO_SSL3_METHOD
const SSL_METHOD *SSLv3_method(void)
{
    return sslv3_method();
}

const SSL_METHOD *SSLv3_server_method(void)
{
    return sslv3_server_method();
}

const SSL_METHOD *SSLv3_client_method(void)
{
    return sslv3_client_method();
}
# endif

# ifndef OPENSSL_NO_DTLS1_2_METHOD
const SSL_METHOD *DTLSv1_2_method(void)
{
    return dtlsv1_2_method();
}

const SSL_METHOD *DTLSv1_2_server_method(void)
{
    return dtlsv1_2_server_method();
}

const SSL_METHOD *DTLSv1_2_client_method(void)
{
    return dtlsv1_2_client_method();
}
# endif

# ifndef OPENSSL_NO_DTLS1_METHOD
const SSL_METHOD *DTLSv1_method(void)
{
    return dtlsv1_method();
}

const SSL_METHOD *DTLSv1_server_method(void)
{
    return dtlsv1_server_method();
}

const SSL_METHOD *DTLSv1_client_method(void)
{
    return dtlsv1_client_method();
}
# endif

#endif
