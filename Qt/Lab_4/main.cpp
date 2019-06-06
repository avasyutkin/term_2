#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <string.h>
#include <stdio.h>
//#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <qdebug.h>

using namespace std;


int do_crypt(unsigned char *plaintext, unsigned char *ciphertext, int do_encrypt)
{
    EVP_CIPHER_CTX *ctx;
    int plaintext_len = strlen((char *)plaintext), len, ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
        return 0;

    unsigned char *key = (unsigned char *)"0123456789abcdeF0123456789abcdeF";
    unsigned char *iv = (unsigned char *)"1234567887654321";

    if(1 != EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, do_encrypt))
        return 0;

    if(1 != EVP_CipherUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return 0;
    ciphertext_len = len;

    if(1 != EVP_CipherFinal_ex(ctx, ciphertext + len, &len))
        return 0;
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);
    ciphertext[ciphertext_len] = '\0';
    return ciphertext_len;
}


int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    //###########

        string stringtext;
        getline(cin, stringtext);
        unsigned char *plaintext = (unsigned char*)stringtext.c_str();

        unsigned char ciphertext[128];
        unsigned char decryptedtext[128];

        do_crypt(plaintext, ciphertext, 1);

        printf("Ciphertext is:\n");
        printf("%s\n", ciphertext);

        do_crypt(ciphertext, decryptedtext, 0);


        printf("Decrypted text is:\n");
        printf("%s\n", decryptedtext);

    //############

    return a.exec();
}
