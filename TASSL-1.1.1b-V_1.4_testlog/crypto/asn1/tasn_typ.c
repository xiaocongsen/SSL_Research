/*
 * Copyright 2000-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>

/* Declarations for string types */

#define IMPLEMENT_ASN1_STRING_FUNCTIONS(sname) \
    IMPLEMENT_ASN1_TYPE(sname) \
    IMPLEMENT_ASN1_ENCODE_FUNCTIONS_fname(sname, sname, sname) \
sname *sname##_new(void) \
{ \
    return ASN1_STRING_type_new(V_##sname); \
} \
void sname##_free(sname *x) \
{ \
    ASN1_STRING_free(x); \
}

IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_OCTET_STRING)

const ASN1_ITEM GMold_ASN1_OCTET_STRING_it = {
    ASN1_ITYPE_PRIMITIVE, V_ASN1_OCTET_STRING, NULL, 0, NULL, 0, "ASN1_OCTET_STRING"
    };

IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_INTEGER)

const ASN1_ITEM GMold_ASN1_INTEGER_it = {
     ASN1_ITYPE_PRIMITIVE, V_ASN1_INTEGER, NULL, 0, NULL, 0, "ASN1_INTEGER" 
};

ASN1_INTEGER *GMold_d2i_ASN1_INTEGER(ASN1_INTEGER **a, const unsigned char **in, long len) 
{ 
        return (ASN1_INTEGER *)GMold_ASN1_item_d2i((ASN1_VALUE **)a, in, len, (&(GMold_ASN1_INTEGER_it)));
} 
int GMold_i2d_ASN1_INTEGER(ASN1_INTEGER *a, unsigned char **out) 
{ 
        return GMold_ASN1_item_i2d((ASN1_VALUE *)a, out, (&(GMold_ASN1_INTEGER_it)));
} 

IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_ENUMERATED)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_BIT_STRING)

const ASN1_ITEM GMold_ASN1_BIT_STRING_it = { 
    ASN1_ITYPE_PRIMITIVE, V_ASN1_BIT_STRING, NULL, 0, NULL, 0, "ASN1_BIT_STRING" 
};

ASN1_BIT_STRING *GMold_d2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a, const unsigned char **in, long len) 
{ return (ASN1_BIT_STRING *)ASN1_item_d2i((ASN1_VALUE **)a, in, len, (&(GMold_ASN1_BIT_STRING_it))); } 
int GMold_i2d_ASN1_BIT_STRING(ASN1_BIT_STRING *a, unsigned char **out) 
{ return ASN1_item_i2d((ASN1_VALUE *)a, out, (&(GMold_ASN1_BIT_STRING_it))); } 
ASN1_BIT_STRING *GMold_ASN1_BIT_STRING_new(void) 
{ return ASN1_STRING_type_new(V_ASN1_BIT_STRING); } 
void GMold_ASN1_BIT_STRING_free(ASN1_BIT_STRING *x) 
{ ASN1_STRING_free(x); }

IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_UTF8STRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_PRINTABLESTRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_T61STRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_IA5STRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_GENERALSTRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_UTCTIME)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_GENERALIZEDTIME)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_VISIBLESTRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_UNIVERSALSTRING)
IMPLEMENT_ASN1_STRING_FUNCTIONS(ASN1_BMPSTRING)

IMPLEMENT_ASN1_TYPE(ASN1_NULL)

const ASN1_ITEM GMold_ASN1_NULL_it =
{
    ASN1_ITYPE_PRIMITIVE, V_ASN1_NULL, NULL, 0, NULL, 0, "ASN1_NULL"
};

IMPLEMENT_ASN1_FUNCTIONS(ASN1_NULL)

IMPLEMENT_ASN1_TYPE(ASN1_OBJECT)

const ASN1_ITEM GMold_ASN1_OBJECT_it = { ASN1_ITYPE_PRIMITIVE, V_ASN1_OBJECT, NULL, 0, NULL, 0, "ASN1_OBJECT" };

IMPLEMENT_ASN1_TYPE(ASN1_ANY)

const ASN1_ITEM GMold_ASN1_ANY_it = { ASN1_ITYPE_PRIMITIVE, V_ASN1_ANY, NULL, 0, NULL, 0, "ASN1_ANY" };

/* Just swallow an ASN1_SEQUENCE in an ASN1_STRING */
IMPLEMENT_ASN1_TYPE(ASN1_SEQUENCE)

IMPLEMENT_ASN1_FUNCTIONS_fname(ASN1_TYPE, ASN1_ANY, ASN1_TYPE)

/* Multistring types */

IMPLEMENT_ASN1_MSTRING(ASN1_PRINTABLE, B_ASN1_PRINTABLE)
IMPLEMENT_ASN1_FUNCTIONS_name(ASN1_STRING, ASN1_PRINTABLE)

IMPLEMENT_ASN1_MSTRING(DISPLAYTEXT, B_ASN1_DISPLAYTEXT)
IMPLEMENT_ASN1_FUNCTIONS_name(ASN1_STRING, DISPLAYTEXT)

IMPLEMENT_ASN1_MSTRING(DIRECTORYSTRING, B_ASN1_DIRECTORYSTRING)
IMPLEMENT_ASN1_FUNCTIONS_name(ASN1_STRING, DIRECTORYSTRING)

/* Three separate BOOLEAN type: normal, DEFAULT TRUE and DEFAULT FALSE */
IMPLEMENT_ASN1_TYPE_ex(ASN1_BOOLEAN, ASN1_BOOLEAN, -1)
const ASN1_ITEM GMold_ASN1_BOOLEAN_it = { ASN1_ITYPE_PRIMITIVE, V_ASN1_BOOLEAN, NULL, 0, NULL, -1, "ASN1_BOOLEAN" };
IMPLEMENT_ASN1_TYPE_ex(ASN1_TBOOLEAN, ASN1_BOOLEAN, 1)
IMPLEMENT_ASN1_TYPE_ex(ASN1_FBOOLEAN, ASN1_BOOLEAN, 0)

/* Special, OCTET STRING with indefinite length constructed support */

IMPLEMENT_ASN1_TYPE_ex(ASN1_OCTET_STRING_NDEF, ASN1_OCTET_STRING, ASN1_TFLG_NDEF)

ASN1_ITEM_TEMPLATE(ASN1_SEQUENCE_ANY) =
        ASN1_EX_TEMPLATE_TYPE(ASN1_TFLG_SEQUENCE_OF, 0, ASN1_SEQUENCE_ANY, ASN1_ANY)
ASN1_ITEM_TEMPLATE_END(ASN1_SEQUENCE_ANY)

ASN1_ITEM_TEMPLATE(ASN1_SET_ANY) =
        ASN1_EX_TEMPLATE_TYPE(ASN1_TFLG_SET_OF, 0, ASN1_SET_ANY, ASN1_ANY)
ASN1_ITEM_TEMPLATE_END(ASN1_SET_ANY)

IMPLEMENT_ASN1_ENCODE_FUNCTIONS_const_fname(ASN1_SEQUENCE_ANY, ASN1_SEQUENCE_ANY, ASN1_SEQUENCE_ANY)
IMPLEMENT_ASN1_ENCODE_FUNCTIONS_const_fname(ASN1_SEQUENCE_ANY, ASN1_SET_ANY, ASN1_SET_ANY)
