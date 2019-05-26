#include <QCoreApplication>

#include<iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <openssl/evp.h>

#define BUFSIZE 1024 //Любое число байт, кратное 16.

void printCharsAsHex(unsigned char *buf, int len){
    for(int i=0; i<len; i++) printf("0x%02x ", buf[i]);
    printf("\n\n");
}

//General encryption and decryption function example using FILE I/O and AES256 with a 256-bit key.
int do_crypt(unsigned char *text_for_encrypt, int do_encrypt){

    int sizetext = strlen((char *)text_for_encrypt);

    unsigned char cryptedtext[256]; // зашифрованный результат
    unsigned char decryptedtext[256];
    unsigned char key[] = "0123456789abcdeF0123456789abcdeF"; //256 бит
    unsigned char iv[] = "1234567887654321"; //128 бит

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, do_encrypt);
    OPENSSL_assert(EVP_CIPHER_CTX_key_length(ctx) == 32);
    OPENSSL_assert(EVP_CIPHER_CTX_iv_length(ctx) == 16);
    EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, do_encrypt);

    EVP_EncryptUpdate(ctx, // объект с настройками
        cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
        &sizetext, // выходной параметр: длина полученного шифра
        text_for_encrypt, // входной параметр: что шифровать
        sizetext); // входной параметр : длина входных данных
    int cryptedtext_len = sizetext;
    EVP_CIPHER_CTX_free(ctx);

    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decryptedtext, &sizetext, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ
    int dectypted_len = sizetext;
    EVP_DecryptFinal_ex(ctx, decryptedtext + sizetext, &sizetext);
    dectypted_len += sizetext;
    EVP_CIPHER_CTX_free(ctx);
    decryptedtext[dectypted_len] = '\0';
    std::cout << cryptedtext << decryptedtext << std::endl;
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    //############
    unsigned char *text_for_encrypt;

    std::cin >> text_for_encrypt;
    do_crypt(text_for_encrypt, 1);
    /*printf("ENCRYPT:\n\n");
    FILE *encode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file.txt", "rb");
    FILE *decode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file1.txt", "wb");
    do_crypt(encode_file, decode_file, 1); // 0 - decrypt, 1 - encrypt
    fclose(encode_file);
    fclose(decode_file);

    printf("\n---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n\n");
    printf("DECRYPT:\n\n");

    encode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file.txt", "rb");
    decode_file = fopen("D:\\181_331_vasyutkin\\vasyutkin_term2\\Qt\\Lab_4\\file1.txt", "wb");
    do_crypt(encode_file, decode_file, 1); // 0 - decrypt, 1 - encrypt
    fclose(encode_file);
    fclose(decode_file);*/

    //############

    return a.exec();
}

