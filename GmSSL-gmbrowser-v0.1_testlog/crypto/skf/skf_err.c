/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2017 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include <openssl/err.h>
#include <openssl/gmskf.h>

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR

# define ERR_FUNC(func) ERR_PACK(ERR_LIB_SKF,func,0)
# define ERR_REASON(reason) ERR_PACK(ERR_LIB_SKF,0,reason)

static ERR_STRING_DATA SKF_str_functs[] = {
    {ERR_FUNC(SKF_F_SKF_CANCELWAITFORDEVEVENT), "SKF_CancelWaitForDevEvent"},
    {ERR_FUNC(SKF_F_SKF_CHANGEDEVAUTHKEY), "SKF_ChangeDevAuthKey"},
    {ERR_FUNC(SKF_F_SKF_CHANGEPIN), "SKF_ChangePIN"},
    {ERR_FUNC(SKF_F_SKF_CLEARSECURESTATE), "SKF_ClearSecureState"},
    {ERR_FUNC(SKF_F_SKF_CLOSEAPPLICATION), "SKF_CloseApplication"},
    {ERR_FUNC(SKF_F_SKF_CLOSECONTAINER), "SKF_CloseContainer"},
    {ERR_FUNC(SKF_F_SKF_CLOSEHANDLE), "SKF_CloseHandle"},
    {ERR_FUNC(SKF_F_SKF_CONNECTDEV), "SKF_ConnectDev"},
    {ERR_FUNC(SKF_F_SKF_CREATEAPPLICATION), "SKF_CreateApplication"},
    {ERR_FUNC(SKF_F_SKF_CREATECONTAINER), "SKF_CreateContainer"},
    {ERR_FUNC(SKF_F_SKF_CREATEFILE), "SKF_CreateFile"},
    {ERR_FUNC(SKF_F_SKF_DECRYPT), "SKF_Decrypt"},
    {ERR_FUNC(SKF_F_SKF_DECRYPTFINAL), "SKF_DecryptFinal"},
    {ERR_FUNC(SKF_F_SKF_DECRYPTINIT), "SKF_DecryptInit"},
    {ERR_FUNC(SKF_F_SKF_DECRYPTUPDATE), "SKF_DecryptUpdate"},
    {ERR_FUNC(SKF_F_SKF_DELETEAPPLICATION), "SKF_DeleteApplication"},
    {ERR_FUNC(SKF_F_SKF_DELETECONTAINER), "SKF_DeleteContainer"},
    {ERR_FUNC(SKF_F_SKF_DELETEFILE), "SKF_DeleteFile"},
    {ERR_FUNC(SKF_F_SKF_DEVAUTH), "SKF_DevAuth"},
    {ERR_FUNC(SKF_F_SKF_DIGEST), "SKF_Digest"},
    {ERR_FUNC(SKF_F_SKF_DIGESTFINAL), "SKF_DigestFinal"},
    {ERR_FUNC(SKF_F_SKF_DIGESTINIT), "SKF_DigestInit"},
    {ERR_FUNC(SKF_F_SKF_DIGESTUPDATE), "SKF_DigestUpdate"},
    {ERR_FUNC(SKF_F_SKF_DISCONNECTDEV), "SKF_DisConnectDev"},
    {ERR_FUNC(SKF_F_SKF_ECCDECRYPT), "SKF_ECCDecrypt"},
    {ERR_FUNC(SKF_F_SKF_ECCEXPORTSESSIONKEY), "SKF_ECCExportSessionKey"},
    {ERR_FUNC(SKF_F_SKF_ECCSIGNDATA), "SKF_ECCSignData"},
    {ERR_FUNC(SKF_F_SKF_ECCVERIFY), "SKF_ECCVerify"},
    {ERR_FUNC(SKF_F_SKF_ENCRYPT), "SKF_Encrypt"},
    {ERR_FUNC(SKF_F_SKF_ENCRYPTFINAL), "SKF_EncryptFinal"},
    {ERR_FUNC(SKF_F_SKF_ENCRYPTINIT), "SKF_EncryptInit"},
    {ERR_FUNC(SKF_F_SKF_ENCRYPTUPDATE), "SKF_EncryptUpdate"},
    {ERR_FUNC(SKF_F_SKF_ENUMAPPLICATION), "SKF_EnumApplication"},
    {ERR_FUNC(SKF_F_SKF_ENUMCONTAINER), "SKF_EnumContainer"},
    {ERR_FUNC(SKF_F_SKF_ENUMDEV), "SKF_EnumDev"},
    {ERR_FUNC(SKF_F_SKF_ENUMFILES), "SKF_EnumFiles"},
    {ERR_FUNC(SKF_F_SKF_EXPORTCERTIFICATE), "SKF_ExportCertificate"},
    {ERR_FUNC(SKF_F_SKF_EXPORTPUBLICKEY), "SKF_ExportPublicKey"},
    {ERR_FUNC(SKF_F_SKF_EXTECCDECRYPT), "SKF_ExtECCDecrypt"},
    {ERR_FUNC(SKF_F_SKF_EXTECCENCRYPT), "SKF_ExtECCEncrypt"},
    {ERR_FUNC(SKF_F_SKF_EXTECCSIGN), "SKF_ExtECCSign"},
    {ERR_FUNC(SKF_F_SKF_EXTECCVERIFY), "SKF_ExtECCVerify"},
    {ERR_FUNC(SKF_F_SKF_EXTRSAPRIKEYOPERATION), "SKF_ExtRSAPriKeyOperation"},
    {ERR_FUNC(SKF_F_SKF_EXTRSAPUBKEYOPERATION), "SKF_ExtRSAPubKeyOperation"},
    {ERR_FUNC(SKF_F_SKF_GENECCKEYPAIR), "SKF_GenECCKeyPair"},
    {ERR_FUNC(SKF_F_SKF_GENERATEAGREEMENTDATAANDKEYWITHECC),
     "SKF_GenerateAgreementDataAndKeyWithECC"},
    {ERR_FUNC(SKF_F_SKF_GENERATEAGREEMENTDATAWITHECC),
     "SKF_GenerateAgreementDataWithECC"},
    {ERR_FUNC(SKF_F_SKF_GENERATEKEYWITHECC), "SKF_GenerateKeyWithECC"},
    {ERR_FUNC(SKF_F_SKF_GENEXTRSAKEY), "SKF_GenExtRSAKey"},
    {ERR_FUNC(SKF_F_SKF_GENRANDOM), "SKF_GenRandom"},
    {ERR_FUNC(SKF_F_SKF_GENRSAKEYPAIR), "SKF_GenRSAKeyPair"},
    {ERR_FUNC(SKF_F_SKF_GETCONTAINERTYPE), "SKF_GetContainerType"},
    {ERR_FUNC(SKF_F_SKF_GETDEVINFO), "SKF_GetDevInfo"},
    {ERR_FUNC(SKF_F_SKF_GETDEVSTATE), "SKF_GetDevState"},
    {ERR_FUNC(SKF_F_SKF_GETFILEINFO), "SKF_GetFileInfo"},
    {ERR_FUNC(SKF_F_SKF_GETPININFO), "SKF_GetPINInfo"},
    {ERR_FUNC(SKF_F_SKF_IMPORTCERTIFICATE), "SKF_ImportCertificate"},
    {ERR_FUNC(SKF_F_SKF_IMPORTECCKEYPAIR), "SKF_ImportECCKeyPair"},
    {ERR_FUNC(SKF_F_SKF_IMPORTECCPRIVATEKEY), "SKF_ImportECCPrivateKey"},
    {ERR_FUNC(SKF_F_SKF_IMPORTRSAKEYPAIR), "SKF_ImportRSAKeyPair"},
    {ERR_FUNC(SKF_F_SKF_IMPORTSESSIONKEY), "SKF_ImportSessionKey"},
    {ERR_FUNC(SKF_F_SKF_LOADLIBRARY), "SKF_LoadLibrary"},
    {ERR_FUNC(SKF_F_SKF_LOCKDEV), "SKF_LockDev"},
    {ERR_FUNC(SKF_F_SKF_MAC), "SKF_Mac"},
    {ERR_FUNC(SKF_F_SKF_MACFINAL), "SKF_MacFinal"},
    {ERR_FUNC(SKF_F_SKF_MACINIT), "SKF_MacInit"},
    {ERR_FUNC(SKF_F_SKF_MACUPDATE), "SKF_MacUpdate"},
    {ERR_FUNC(SKF_F_SKF_METHOD_LOAD_LIBRARY), "SKF_METHOD_load_library"},
    {ERR_FUNC(SKF_F_SKF_NEWECCCIPHER), "SKF_NewECCCipher"},
    {ERR_FUNC(SKF_F_SKF_NEWENVELOPEDKEY), "SKF_NewEnvelopedKey"},
    {ERR_FUNC(SKF_F_SKF_OPENAPPLICATION), "SKF_OpenApplication"},
    {ERR_FUNC(SKF_F_SKF_OPENCONTAINER), "SKF_OpenContainer"},
    {ERR_FUNC(SKF_F_SKF_READFILE), "SKF_ReadFile"},
    {ERR_FUNC(SKF_F_SKF_RSAEXPORTSESSIONKEY), "SKF_RSAExportSessionKey"},
    {ERR_FUNC(SKF_F_SKF_RSASIGNDATA), "SKF_RSASignData"},
    {ERR_FUNC(SKF_F_SKF_RSAVERIFY), "SKF_RSAVerify"},
    {ERR_FUNC(SKF_F_SKF_SETLABEL), "SKF_SetLabel"},
    {ERR_FUNC(SKF_F_SKF_SETSYMMKEY), "SKF_SetSymmKey"},
    {ERR_FUNC(SKF_F_SKF_TRANSMIT), "SKF_Transmit"},
    {ERR_FUNC(SKF_F_SKF_UNBLOCKPIN), "SKF_UnblockPIN"},
    {ERR_FUNC(SKF_F_SKF_UNLOCKDEV), "SKF_UnlockDev"},
    {ERR_FUNC(SKF_F_SKF_VERIFYPIN), "SKF_VerifyPIN"},
    {ERR_FUNC(SKF_F_SKF_W), "SKF_WaitForDevEvent"},
    {ERR_FUNC(SKF_F_SKF_WAITFORDEVEVENT), "SKF_WaitForDevEvent"},
    {ERR_FUNC(SKF_F_SKF_WRITEFILE), "SKF_WriteFile"},
    {0, NULL}
};

static ERR_STRING_DATA SKF_str_reasons[] = {
    {ERR_REASON(SKF_R_APPLICATION_ALREADY_EXIST),
     "application already exist"},
    {ERR_REASON(SKF_R_APPLICATION_NOT_EXISAT), "application not exisat"},
    {ERR_REASON(SKF_R_APPLICATION_NOT_EXIST), "application not exist"},
    {ERR_REASON(SKF_R_BUFFER_TOO_SMALL), "buffer too small"},
    {ERR_REASON(SKF_R_CERTIFICATE_NOT_FOUND), "certificate not found"},
    {ERR_REASON(SKF_R_CSP_IMPORT_PUBLIC_KEY_ERROR),
     "csp import public key error"},
    {ERR_REASON(SKF_R_DECRYPT_INVALID_PADDING), "decrypt invalid padding"},
    {ERR_REASON(SKF_R_DEVICE_REMOVED), "device removed"},
    {ERR_REASON(SKF_R_DIGEST_ERROR), "digest error"},
    {ERR_REASON(SKF_R_DSO_LOAD_FAILURE), "dso load failure"},
    {ERR_REASON(SKF_R_ENVELOPE_PRVATE_KEY_FAILURE),
     "envelope prvate key failure"},
    {ERR_REASON(SKF_R_EXPORT_FAILED), "export failed"},
    {ERR_REASON(SKF_R_FAILURE), "failure"},
    {ERR_REASON(SKF_R_FILE_ALREADY_EXIST), "file already exist"},
    {ERR_REASON(SKF_R_FILE_ERROR), "file error"},
    {ERR_REASON(SKF_R_FILE_NOT_EXIST), "file not exist"},
    {ERR_REASON(SKF_R_FUNCTION_NOT_SUPPORTED), "function not supported"},
    {ERR_REASON(SKF_R_HASH_NOT_EQUAL), "hash not equal"},
    {ERR_REASON(SKF_R_IMPORT_ENVELOPED_ECC_PRIVATE_KEY_FAILURE),
     "import enveloped ecc private key failure"},
    {ERR_REASON(SKF_R_INVALID_APPLICATION_NAME), "invalid application name"},
    {ERR_REASON(SKF_R_INVALID_CONTAINER_TYPE), "invalid container type"},
    {ERR_REASON(SKF_R_INVALID_DIGEST_HANDLE), "invalid digest handle"},
    {ERR_REASON(SKF_R_INVALID_HANDLE), "invalid handle"},
    {ERR_REASON(SKF_R_INVALID_INPUT_LENGTH), "invalid input length"},
    {ERR_REASON(SKF_R_INVALID_INPUT_VALUE), "invalid input value"},
    {ERR_REASON(SKF_R_INVALID_KEY_INFO_TYPE), "invalid key info type"},
    {ERR_REASON(SKF_R_INVALID_KEY_USAGE), "invalid key usage"},
    {ERR_REASON(SKF_R_INVALID_MAC_LENGTH), "invalid mac length"},
    {ERR_REASON(SKF_R_INVALID_MODULUS_LENGTH), "invalid modulus length"},
    {ERR_REASON(SKF_R_INVALID_NAME_LENGTH), "invalid name length"},
    {ERR_REASON(SKF_R_INVALID_OBJECT), "invalid object"},
    {ERR_REASON(SKF_R_INVALID_PARAMETER), "invalid parameter"},
    {ERR_REASON(SKF_R_INVALID_PIN), "invalid pin"},
    {ERR_REASON(SKF_R_INVALID_PIN_LENGTH), "invalid pin length"},
    {ERR_REASON(SKF_R_INVALID_RSA_MODULUS_LENGTH),
     "invalid rsa modulus length"},
    {ERR_REASON(SKF_R_INVALID_USER_TYPE), "invalid user type"},
    {ERR_REASON(SKF_R_KEY_NOT_FOUND), "key not found"},
    {ERR_REASON(SKF_R_LOAD_LIBRARY_FAILURE), "load library failure"},
    {ERR_REASON(SKF_R_MEMORY_ERROR), "memory error"},
    {ERR_REASON(SKF_R_NOT_INITIALIZED), "not initialized"},
    {ERR_REASON(SKF_R_NOT_SUPPORTED_CIPHER_ALGOR),
     "not supported cipher algor"},
    {ERR_REASON(SKF_R_NOT_SUPPORTED_DIGEST_ALGOR),
     "not supported digest algor"},
    {ERR_REASON(SKF_R_NOT_SUPPORTED_PKEY_ALGOR), "not supported pkey algor"},
    {ERR_REASON(SKF_R_NO_EVENT), "no event"},
    {ERR_REASON(SKF_R_NO_SPACE), "no space"},
    {ERR_REASON(SKF_R_NULL_ARGUMENT), "null argument"},
    {ERR_REASON(SKF_R_OPERATION_NOT_SUPPORTED), "operation not supported"},
    {ERR_REASON(SKF_R_PIN_INCORRECT), "pin incorrect"},
    {ERR_REASON(SKF_R_PIN_LOCKED), "pin locked"},
    {ERR_REASON(SKF_R_RANDOM_GENERATION_FAILED), "random generation failed"},
    {ERR_REASON(SKF_R_READ_FILE_FAILURE), "read file failure"},
    {ERR_REASON(SKF_R_RSA_DECRYPTION_FAILURE), "rsa decryption failure"},
    {ERR_REASON(SKF_R_RSA_ENCRYPTION_FAILURE), "rsa encryption failure"},
    {ERR_REASON(SKF_R_RSA_KEY_GENERATION_FAILURE),
     "rsa key generation failure"},
    {ERR_REASON(SKF_R_SKF_METHOD_NOT_INITIALIZED),
     "skf method not initialized"},
    {ERR_REASON(SKF_R_SUCCESS), "success"},
    {ERR_REASON(SKF_R_TIMEOUT), "timeout"},
    {ERR_REASON(SKF_R_UNKNOWN_ERROR), "unknown error"},
    {ERR_REASON(SKF_R_UNKNOWN_VENDOR), "unknown vendor"},
    {ERR_REASON(SKF_R_USER_ALREADY_LOGGED_IN), "user already logged in"},
    {ERR_REASON(SKF_R_USER_NOT_LOGGED_IN), "user not logged in"},
    {ERR_REASON(SKF_R_USER_PIN_NOT_INITIALIZED), "user pin not initialized"},
    {ERR_REASON(SKF_R_WISEC_AUTH_BLOCKED), "wisec auth blocked"},
    {ERR_REASON(SKF_R_WISEC_CERTNOUSAGEERR), "wisec certnousageerr"},
    {ERR_REASON(SKF_R_WISEC_CERTUSAGEERR), "wisec certusageerr"},
    {ERR_REASON(SKF_R_WISEC_CONTAINER_EXISTS), "wisec container exists"},
    {ERR_REASON(SKF_R_WISEC_CONTAINER_NOT_EXISTS),
     "wisec container not exists"},
    {ERR_REASON(SKF_R_WISEC_DEVNOAUTH), "wisec devnoauth"},
    {ERR_REASON(SKF_R_WISEC_FILEATTRIBUTEERR), "wisec fileattributeerr"},
    {ERR_REASON(SKF_R_WISEC_INVALIDCONTAINERERR),
     "wisec invalidcontainererr"},
    {ERR_REASON(SKF_R_WISEC_KEYNOUSAGEERR), "wisec keynousageerr"},
    {ERR_REASON(SKF_R_WRITE_FILE_FAILURE), "write file failure"},
    {0, NULL}
};

#endif

int ERR_load_SKF_strings(void)
{
#ifndef OPENSSL_NO_ERR

    if (ERR_func_error_string(SKF_str_functs[0].error) == NULL) {
        ERR_load_strings(0, SKF_str_functs);
        ERR_load_strings(0, SKF_str_reasons);
    }
#endif
    return 1;
}
